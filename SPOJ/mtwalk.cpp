#include <cstdio>
#include <cstring>

using namespace std;

const int max_n = 1000+1;

bool check, avail[max_n][max_n];
int n, diff, h[max_n][max_n];

inline void load_data()
{
    scanf("%d", &n);
    int i, j;
    for (i=1; i <= n; i++)
        for (j=1; j <= n; j++) scanf("%d", &h[i][j]);
}

inline bool valid(int i, int j)
{
    return (i and i <= n and j and j <= n);
}

inline int max(int a, int b)
{
    if (a > b) return a;
    return b;
}

inline int min(int a, int b)
{
    if (a < b) return a;
    return b;
}

inline void dfs(int i, int j, int max_h, int min_h)
{
    if (check) return ;
    if (i==n and j==n)
    {
        check = true;
        return ;
    }
    avail[i][j] = false;
    int ii, jj, hh=h[i][j], max_t, min_t;
    for (ii=-1; ii <= 1; ii++)
        for (jj=-1; jj <= 1; jj++)
            if (ii+jj==1 or ii+jj==-1)
            {
                i += ii; j += jj;
                //cout << "(" << i << "," << j << "), ";
                if (valid(i, j) and avail[i][j])
                {
                    max_t = max(max_h, hh);
                    min_t = min(min_h, hh);
                    if (max_t-min_t <= diff) dfs(i, j, max_t, min_t);
                }
                i -= ii; j -= jj;
            }
}

inline bool find_path(int d)
{
    check = false; diff = d;
    //cout << diff << ": ";
    memset(avail, true, sizeof(avail));
    dfs(1, 1, h[1][1], h[1][1]);
    //cout << endl;
    return check;
}

main()
{
    load_data();
    int m, l = 0, r = 1000000;
    m = (l+r)/2;
    while (l != m and m != r)
    {
        if (find_path(m))
            r = m;
        else l = m;
        m = (l+r)/2;
    }
    for (m=l; m <= r; m++)
        if (find_path(m))
        {
            printf("%d", m);
            break ;
        }
}
