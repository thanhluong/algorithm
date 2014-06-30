#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

typedef pair<long long, int> lli;

const long long oo = ((1 << 30)-1)*2-1;
const int max_n = 5000+1;

int n, m;
long long min_d, dist = 0, count[max_n];
vector<lli> adj[max_n];

inline void load_map()
{
    cin >> n >> m;
    int type, u, v, w;
    while (m--)
    {
        cin >> type >> u >> v >> w;
        adj[u].push_back(lli(w, v));
        if (type==2) adj[v].push_back(lli(w, u));
    }
}

inline void dijkstra()
{
    vector<lli>::iterator it;
    long long cuv, du, d[max_n];
    int u, v;
    priority_queue<lli, vector<lli>, greater<lli> > heap;
    for (u=1; u <= n; u++) d[u] = +oo;
    memset(count, 0, sizeof(count));
    d[1] = 0; count[1] = 1;
    heap.push(lli(0, 1));
    while (heap.size())
    {
        du = heap.top().first; u = heap.top().second;
        heap.pop();
        if (du != d[u]) continue;
        if (u == n) break;
        for (it=adj[u].begin(); it != adj[u].end(); it++)
        {
            cuv = it->first; v = it->second;
            if (d[v]==d[u]+cuv) count[v] += count[u];
            if (d[v] > d[u]+cuv)
            {
                d[v] = d[u]+cuv;
                count[v] = count[u];
                heap.push(lli(d[v], v));
            }
        }
    }
    min_d = d[n];
}

main()
{
    load_map();
    dijkstra();
    cout << min_d << " " << count[n];
}
