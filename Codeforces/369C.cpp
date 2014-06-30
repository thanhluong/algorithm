#include <iostream>
#include <vector>
#include <cstring>

#define x first
#define y second

using namespace std;

const int max_n = 100000+1;

typedef pair<int, bool> ib;

bool avail[max_n];
vector<ib> adj[max_n];
vector<int> res;

inline int dfs(int u, bool error)
{
    avail[u] = false;
    int v, count = 0;
    for (vector<ib>::iterator road=adj[u].begin(); road != adj[u].end(); road++)
    {
        v = road->x;
        if (avail[v]) count += dfs(v, road->y);
    }
    if (error && !count) res.push_back(u);
    avail[u] = true;
    return (count+error);
}

main()
{
    memset(avail, true, sizeof(avail));
    int i, n, u, v, t;
    cin >> n;
    for (i=1; i < n; i++)
    {
        cin >> u >> v >> t;
        adj[u].push_back(ib(v, t==2));
        adj[v].push_back(ib(u, t==2));
    }
    dfs(1, false);
    cout << res.size() << endl;
    for (vector<int>::iterator it=res.begin(); it != res.end(); it++)
        cout << *it << " ";
}
