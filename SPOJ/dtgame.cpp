#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const int max_n = 2000+1;

int n, t[max_n], f[max_n][max_n];

inline int sum(int i, int j)
{
    return t[j]-t[i-1];
}

main()
{
    memset(f, 0, sizeof(f));
    scanf("%d", &n);
    t[0] = 0;
    for (int i=1; i <= n; i++)
    {
        scanf("%d", &t[i]);
        t[i] += t[i-1];
    }
    for (j=1; j <= n; j++)
        for (i=j; i >= 1; i--)
            if (i==j)
                f[i][j] = 0;
            else
                f[i][j] = max(f[i][j], min(f[i][k]+sum(i, k), f[k+1][j]));
    cout << f[1][n];
}
