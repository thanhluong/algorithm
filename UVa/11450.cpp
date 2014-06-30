#include <iostream>
#include <cstdio>

using namespace std;

const int M=200+1;
const int N=20+1;
const int K=20+1;

int m, n, i, j, k, t, T;

inline void optimize()
{
    scanf("%d%d", &m, &n);
    bool f[N][M];
    int a[N][K];
    f[0][0]=true;
    for (i=1; i <= n; i++)
    {
        scanf("%d", &k);
        for (j=1; j <= k; j++) scanf("%d", &a[i][j]);
        for (j=0; j <= M; j++)
        {
            f[i][j]=false;
            for (t=1; t <= k; t++)
                if (j >= a[i][t])
                    f[i][j]=f[i][j] or f[i-1][j-a[i][t]];
        }
    }
    for (i=m; i >= 0; i--)
        if (f[n][i])
        {
            printf("%d\n", i);
            return ;
        }
    printf("no solution\n");
}

main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d", &T);
    while (T--) optimize();
}
