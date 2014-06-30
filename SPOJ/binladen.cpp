#include <iostream>
#include <vector>
#include <queue>

#define x first
#define y second

using namespace std;

const int oo = 1 << 30;
const int max_vertex = 2222*10+1;

typedef pair<int, int> ii;

vector<ii> adj[max_vertex];
int m, n, d[max_vertex];

inline void add_edge(int u, int v, int c)
{
    //cout << "added edge that connect " << u << " to " << v << endl;
    adj[u].push_back(ii(c, v));
    adj[v].push_back(ii(c, u));
}

inline void build_graph()
{
    int i, j, c;
    cin >> m >> n;
    for (i=0; i < m; i++)
    {
        for (j=1; j <= n; j++)
        {
            cin >> c;
            if (i)
                add_edge((i-1)*n+j, i*n+j, c);
            else
                add_edge(0, j, c);
        }
        for (j=1; j < n; j++)
        {
            cin >> c;
            add_edge(i*n+j, i*n+j+1, c);
        }
    }
}

inline void dijkstra()
{
    int u, v, du, cuv;
    vector<ii>::iterator it;
    priority_queue<ii, vector<ii>, greater<ii> > heap;
    heap.push(ii(0, 0));
    for (u=1; u <= m*n; u++) d[u] = oo;
    d[0] = 0;
    while (heap.size())
    {
        u = heap.top().y; du = heap.top().x;
        heap.pop();
        if (d[u] != du) continue;
        for (it=adj[u].begin(); it != adj[u].end(); it++)
        {
            v = it->y; cuv = it->x;
            if (d[v] > du+cuv)
            {
                d[v] = du+cuv;
                heap.push(ii(d[v], v));
            }
        }
    }
}

main()
{
    build_graph();
    dijkstra();
    cout << d[m*n];
}

