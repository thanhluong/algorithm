#include <iostream>
#include <map>
#include <cstdio>

using namespace std;

typedef pair<int, int> ii;

const int N=30+1;

map<ii, int> COUNT;
int U, V, res=0, n, mid, x[N], y[N];

inline void load_data()
{
    int i;
    scanf("%d", &n);
    for (i=1; i <= n; i++) scanf("%d%d", &x[i], &y[i]);
    scanf("%d%d", &U, &V);
    mid=n/2;
}

inline void init(int l, int r, int u, int v)
{
    if (l==r+1)
    {
        COUNT[ii(u, v)]++;
        return ;
    }
    init(l+1, r, u, v);
    init(l+1, r, u+x[l], v+y[l]);
}

inline void calc(int l, int r, int u, int v)
{
    if (l==r+1)
    {
        res+=COUNT[ii(U-u, V-v)];
            //cout << u << " " << v << " " << res << endl;
        return ;
    }
    calc(l+1, r, u, v);
    calc(l+1, r, u+x[l], v+y[l]);
}

main()
{
    //freopen("input.txt", "r", stdin);
    load_data();
    if (!n)
    {
        cout << 1;
        return 0;
    }
    init(1, mid, 0, 0);
    calc(mid+1, n, 0, 0);
    cout << res+(!res);
}
