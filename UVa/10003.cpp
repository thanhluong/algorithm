#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N=50+2;
const int oo=2000000000;

int l, n, c[N], f[N][N];

inline void init()
{
    int i;
    scanf("%d", &n);
    c[0]=0; c[n+1]=l;
    for (i=1; i <= n; i++) scanf("%d", &c[i]);
    memset(f, -1, sizeof(f));
}

inline int get_f(int i, int j)
{
    int len=c[j]-c[i], contain=oo, k;
    //cout << i << " " << j << endl;
    if (j-i <= 1) return 0;
    if (j-i==2) return len;
    if (f[i][j] != -1) return f[i][j];
    for (k=i+1; k < j; k++)
        contain=min(contain, get_f(i, k)+get_f(k, j));
    //cout << i << " " << j << " " << contain << endl;
    return (f[i][j]=len+contain);
}
//0, 1, 2, 3, 4
main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    while (true)
    {
        scanf("%d", &l);
        if (!l) break;
        init();
        printf("The minimum cutting is %d.\n", get_f(0, n+1));
    }
}
