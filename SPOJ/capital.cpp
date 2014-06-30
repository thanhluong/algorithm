#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

#define x first
#define y second

using namespace std;

typedef pair<int, int> ii;

const int max_n = 10000+1;

int n, p, max_dist[max_n], dc[max_n];
vector<ii> adj[max_n];
bool avail[max_n];

inline void load_graph()
{
    int u, v, w;
    cin >> n >> p;
    for (int count_loop=1; count_loop < n; count_loop++)
    {
        cin >> u >> v >> w;
        adj[u].push_back(ii(w, v));
        adj[v].push_back(ii(w, u));
    }
}

inline void dfs(int root, int u, int dist)
{
    max_dist[root] = max(max_dist[root], min(dist, dc[u]));
    avail[u] = false;
    int v, w;
    for (vector<ii>::iterator it=adj[u].begin(); it != adj[u].end(); it++)
    {
        v = it->y; w = it->x;
        if (avail[v]) dfs(root, v, dist+w);
    }
}

inline void measure(int u)
{
    max_dist[u] = 0;
    memset(avail, true, sizeof(avail));
    dfs(u, u, 0);
}

inline void dfs_capital(int u, int dist)
{
    int v, w;
    dc[u] = dist;
    avail[u] = false;
    for (vector<ii>::iterator it=adj[u].begin(); it != adj[u].end(); it++)
    {
        v = it->y; w = it->x;
        if (avail[v]) dfs_capital(v, dist+w);
    }
}

main()
{
    load_graph();
    memset(avail, true, sizeof(avail));
    dfs_capital(p, 0);
    int u;
    for (u=1; u <= n; u++) measure(u);
    int res = 0;
    for (u=1; u <= n; u++) if (u-p) res = max(res, max_dist[p]-max_dist[u]);
    cout << res;
}
