#include <iostream>
#include <cstdio>

using namespace std;

const int N=150+1;
const int M=150+1;
const int oo=N*M;

int n, m, i, j, COUNT=0;
char a[N][M];

inline bool valid(int i, int j)
{
    return (i and i <= n and j and j <= m);
}

inline int buffalo(int i, int j, int dir, int remain)
{
    if (!remain or (a[i][j]=='W' and remain==1)) return 0;
    int res=oo;
    if (valid(i, j+dir)) res=min(res, buffalo(i, j+dir, dir, remain-(a[i][j]=='W'))+1);
    if (valid(i+1, j)) res=min(res, buffalo(i+1, j, -dir, remain-(a[i][j]=='W'))+1);
    return res;
}

main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for (i=1; i <= n; i++)
        for (j=1; j <= m; j++)
        {
            cin >> a[i][j];
            COUNT+=(a[i][j]=='W');
        }
    cout << buffalo(1, 1, 1, COUNT);
}
