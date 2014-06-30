#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef char str[10];

const int M=1000+5;
const int N=1000+5;

int m, n, test, north_val[M], south_val[N], f[M][N], r[M][N];
str north_os[M], south_os[N];

inline void load_data()
{
    int i;
    str cityname;
    scanf("%d", &m);
    for (i=1; i <= m; i++) scanf("%s%s%d", &cityname, &north_os[i], &north_val[i]);
    scanf("%d", &n);
    for (i=1; i <= n; i++) scanf("%s%s%d", &cityname, &south_os[i], &south_val[i]);
}

inline void ASSIGN(int i, int j, int I, int J, bool connect)
{
    f[i][j]=f[I][J]+connect*(north_val[i]+south_val[j]);
    r[i][j]=r[I][J]+connect;
}

inline void optimize()
{
    memset(f, 0, sizeof(f));
    memset(r, 0, sizeof(r));
    int i, j, candidate_f, candidate_r;
    for (i=1; i <= m; i++)
        for (j=1; j <= n; j++)
        {
            //cout << i << " " << j << endl;
            if (f[i-1][j] > f[i][j-1] or (f[i-1][j]==f[i][j-1] and r[i-1][j] < r[i][j-1]))
                ASSIGN(i, j, i-1, j, false);
            else
                ASSIGN(i, j, i, j-1, false);
            if (!strcmp(north_os[i], south_os[j]))
            {
                candidate_f=f[i-1][j-1]+north_val[i]+south_val[j];
                candidate_r=r[i-1][j-1]+1;
                if (candidate_f > f[i][j] or (candidate_f==f[i][j] and candidate_r < r[i][j]))
                    ASSIGN(i, j, i-1, j-1, true);
            }
        }
}

main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d", &test);
    while (test--)
    {
        load_data();
        optimize();
        printf("%d %d\n", f[m][n], r[m][n]);
    }
}
