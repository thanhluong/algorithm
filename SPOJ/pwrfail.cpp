#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

typedef pair<double, int> di;

const int max_n = 1000+1;
const int oo = 1000000000;

int n, x[max_n], y[max_n], par[max_n];
double m, d[max_n], c[max_n][max_n];

inline void getch()
{
    char s;
    cin >> s;
}

inline double dist(int i, int j)
{
    return sqrt(pow(x[i]-x[j], 2)+pow(y[i]-y[j], 2));
}

inline int cind_set(int u)
{
    if (par[u]==u)
        return u;
    else
        return (par[u] = cind_set(par[u]));
}

inline void join(int u, int v)
{
    par[cind_set(u)] = cind_set(v);
}

inline void init()
{
    int i, j, w;
    cin >> n >> w >> m;
    for (i=1; i <= n; i++)
    {
        par[i] = i;
        cin >> x[i] >> y[i];
    }
    while (w--)
    {
        cin >> i >> j;
        join(i, j);
    }
    for (i=1; i < n; i++)
        for (j=i+1; j <= n; j++)
            c[j][i] = (c[i][j] = (cind_set(i)==cind_set(j) ? 0 : dist(i, j)));
}

inline void dijkstra()
{
    int u, v;
    double du;
    for (u=1; u <= n; u++) d[u] = oo;
    d[1] = 0;
    priority_queue<di, vector<di>, greater<di> > heap;
    heap.push(di(0, 1));
    while (heap.size())
    {
        u = heap.top().second; du = heap.top().first;
        heap.pop();
        if (d[u] != du) continue;
        for (v=1; v <= n; v++)
            if (v != u && c[u][v] <= m && d[v] > d[u]+c[u][v])
            {
                d[v] = d[u]+c[u][v];
                heap.push(di(d[v], v));
            }
    }
}

inline long long recine(double x)
{
    return (x*1000);
}

main()
{
    init();
    dijkstra();
    if (d[n] == oo)
        cout << -1;
    else
        cout << recine(d[n]);
}
