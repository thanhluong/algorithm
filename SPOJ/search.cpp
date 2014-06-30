#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

const int max_n = 100000+1;

int m, n, p, a[max_n], c[max_n];
bool appear_b[max_n], appear_c[max_n];

inline void load_data()
{
    memset(appear_b, false, sizeof(appear_b));
    cin >> m >> n >> p;
    int i, j;
    for (i=1; i <= m; i++) cin >> a[i];
    for (i=1; i <= n; i++)
    {
        cin >> j;
        appear_b[j] = true;
    }
    for (i=1; i <= p; i++) cin >> c[i];
}

inline bool check(int i, int j)
{
    memset(appear_c, false, sizeof(appear_c));
    int k;
    for (k=i; k <= j; k++)
    {
        if (appear_b[c[k]]) return false;
        appear_c[c[k]] = true;
    }
    for (k=1; k <= m; k++)
        if (!appear_c[a[k]]) return false;
    return true;
}

main()
{
    load_data();
    int i, j, res = 0;
    for (i=1; i <= p; i++)
        for (j=p; j >= i; j--)
            if (check(i, j))
            {
                res = max(res, j-i+1);
                break ;
            }
    cout << res;
}
