#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

const int max_n = 800+1;

vector<int> adj[max_n];
int n, m, res = 0, count = 0, low[max_n], number[max_n];

inline void dfs(int u)
{
    int v;
    number[u] = ++count; low[u] = n+1;
    for (vector<int>::iterator it=adj[u].begin(); it != adj[u].end(); it++)
    {
        v = *it;
        if (number[v])
            low[u] = min(low[u], number[v]);
        else
        {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
    }
    res += (low[u] >= number[u]);
}

inline void load_graph()
{
    int u, v;
    cin >> n >> m;
    while (m--)
    {
        cin >> u >> v;
        adj[u].push_back(v);
    }
}

inline void tarjan()
{
    memset(number, 0, sizeof(number));
    for (int u=1; u <= n; u++)
        if (!number[u]) dfs(u);
}

main()
{
    load_graph();
    tarjan();
    cout << res;
}
