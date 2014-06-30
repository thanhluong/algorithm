#include <iostream>
#include <cstdio>

using namespace std;

const int N=1000+1;
const long long oo=1000000000000;

int m, n, q;
long long c[N][N], e[2*N][2][N], res;

inline void load_data()
{
    int i, j;
    scanf("%d%d", &m, &n);
    for (i=1; i <= m; i++)
        for (j=1; j <= n; j++)
            scanf("%d", &c[i][j]);
}

inline void optimize()
{
    int i, j, k;
    long long min_x, min_y;
    res=oo;
    e[1][0][1]=(e[1][1][1]=0);
    for (j=2; j <= m; j++) e[1][0][j]=oo;
    for (j=2; j <= n; j++) e[1][1][j]=oo;
    for (i=2; i <= m+n; i++)
    {
        min_x=oo;
        for (j=1; j <= m; j++)
        {
            e[i][0][j]=min_x;
            for (k=1; k <= n; k++)
            {
                e[i][0][j]=min(e[i][0][j], e[i-1][1][k]+c[j][k]);
                cout << "x: " << i << " " << j << " " << k << " " << e[i-1][1][k]+c[j][k] << endl;
            }
            if (i==m+n) res=min(res, e[i][0][j]);
            cout << "x*: " << i << " " << j << " " << min_x << " " << e[i][0][j] << endl;
            min_x=min(min_x, e[i-1][0][j]);
        }
        min_y=oo;
        for (j=1; j <= n; j++)
        {
            e[i][1][j]=min_y;
            for (k=1; k <= m; k++)
            {
                e[i][1][j]=min(e[i][1][j], e[i-1][0][k]+c[k][j]);
                cout << "y: " << i << " " << j << " " << k << " " << e[i-1][0][k]+c[k][j] << endl;
            }
            if (i==m+n) res=min(res, e[i][1][j]);
            cout << "y*: " << i << " " << j << " " << min_y << " " << e[i][1][j] << endl;
            min_y=min(min_y, e[i-1][1][j]);
        }
    }
}

main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &q);
    while (q--)
    {
        load_data();
        optimize();
        cout << res << endl;
    }
}
