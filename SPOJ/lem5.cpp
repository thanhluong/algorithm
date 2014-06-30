#include <iostream>
#include <map>
#include <vector>
#include <cstdio>

#define val first
#define pos second

using namespace std;

typedef pair<int, int> ii;

const int N=100000+1;
const int D=100+1;
const int KEY=1000000+3;

vector<ii> memo[KEY];
int n, d, i, j, a, res=0, f[N][D];

inline int HASH(int n)
{
    n=(n > 0 ? n : -n);
    return (n%KEY);
}

inline void INSERT(int n, int p)
{
    int MAP=HASH(n);
    for (vector<ii>::iterator it=memo[MAP].begin(); it != memo[MAP].end(); it++)
        if (it->val==n)
        {
            it->pos=p;
            return ;
        }
    memo[MAP].push_back(ii(n, p));
}

inline int FIND(int n)
{
    int MAP=HASH(n);
    for (vector<ii>::iterator it=memo[MAP].begin(); it != memo[MAP].end(); it++)
        if (it->val==n) return it->pos;
    return 0;
}

main()
{
    freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (d=1; d < D; d++) f[0][d]=0;
    for (i=1; i <= n; i++)
    {
        scanf("%d", &a);
        for (d=1; d < D; d++)
        {
            j=FIND(a-d);
            f[i][d]=f[j][d]+1;
            res=max(res, f[i][d]);
        }
        INSERT(a, i);
    }
    printf("%d", res);
}
