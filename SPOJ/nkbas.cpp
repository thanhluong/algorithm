#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

typedef pair<int, int> ii;

const int N=1000;

priority_queue<ii> heap;
int n, m, u, v, adj[N];
bool is_adj[N][N], ok[N];

inline int result()
{
    int u, v, t, adj_u, COUNT=0;
    //bool complete=true;
    memset(ok, false, sizeof(ok));
    for (u=1; u <= n; u++) heap.push(ii(adj[u], u));
    while (heap.size())
    {
        adj_u=heap.top().first; u=heap.top().second;
        heap.pop();
        if (adj_u != adj[u]) continue;
        if (!adj_u) break;
        //cout << u << " " << adj_u << endl;
        ok[u]=true; COUNT++;
        for (v=1; v <= n; v++)
            if (is_adj[u][v])
            {
                //cout << u << " " << v << endl;
                ok[v]=true;
            }
        for (v=1; v <= n; v++)
        {
            adj[v]=0;
            for (t=1; t <= n; t++)
                if (is_adj[v][t] and !ok[t]) adj[v]++;
            //complete=complete and ok[v];
            heap.push(ii(adj[v], v));
        }
        //if (complete) break;
    }
    return COUNT;
}

main()
{
    freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    memset(is_adj, false, sizeof(is_adj));
    for (u=1; u <= n; u++)
    {
        is_adj[u][u]=true;
        adj[u]=1;
    }
    while (m--)
    {
        scanf("%d%d", &u, &v);
        if (!is_adj[u][v])
        {
            adj[u]++;
            adj[v]++;
        }
        is_adj[u][v]=true;
        is_adj[v][u]=true;
    }
    printf("%d", result());
}
