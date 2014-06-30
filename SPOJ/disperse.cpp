#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const int N=50+1;
const int K=50+1;
const int oo=2000000000;

int n, k, i, j, a[N], f[N][K], v[N][K];

main()
{
    freopen("disperse.inp", "r", stdin);
    freopen("dispere.out", "w", stdout);
    scanf("%d %d", &n, &k);
    for (i=1; i <= n; i++) scanf("%d", &a[i]);
    sort(a+1, a+n+1);
    v[1][1]=a[1]; f[1][1]=0;
    f[1][2]=oo; v[1][2]=0;
    for (i=2; i <= n; i++)
        for (j=i; j <= k; j++)
        {
            f[i][j]=oo;
            if (j > i) continue;
            if (f[i][j] > f[i-1][j]+abs(a[i]-v[i-1][j]))
            {
                f[i][j]=f[i-1][j]+abs(a[i]-v[i-1][j]);
                v[i][j]=v[i-1][j];
            }
            if (f[i][j] > f[i-1][j-1]+abs(a[i]-(v[i-1][j-1]+1)))
            {
                f[i][j]=f[i-1][j-1]+abs(a[i]-(v[i-1][j-1]+1));
                v[i][j]=v[i-1][j-1]+1;
            }
            cout << i << " " << j << " " << f[i][j] << endl;
        }
    printf("%d", f[n][k]);
}
