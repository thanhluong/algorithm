#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>

#define x first
#define y second

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int N=500+1;
const int K=30000+1;
const int oo=1000000000;

int test, n, k, d[K][N], res;
vector<iii> adj[N];

inline void load_data()
{
    int r, u, v, l, t;
    scanf("%d%d%d", &k, &n, &r);
    for (u=1; u <= n; u++) adj[u]=vector<iii>();
    while (r--)
    {
        scanf("%d%d%d%d", &u, &v, &l, &t);
        adj[u].push_back(iii(v, ii(l, t)));
    }
}

inline void dijkstra()
{
    res=oo;
    priority_queue<iii, vector<iii>, greater<iii> > heap;
    int u, v, l, t, L, T, dtu;
    vector<iii>::iterator it;
    for (t=0; t <= k; t++)
        for (u=1; u <= n; u++) d[t][u]=oo;
    d[0][1]=0;
    heap.push(iii(0, ii(0, 1)));
    while (heap.size())
    {
        dtu=heap.top().x; t=heap.top().y.x; u=heap.top().y.y;
        heap.pop();
        if (dtu != d[t][u]) continue;
        if (u==n)
        {
            res=min(res, dtu);
            return ;
        }
        for (it=adj[u].begin(); it!=adj[u].end(); it++)
        {
            v=it->x; L=it->y.x; T=it->y.y;
            //cout << u << " " << v << endl;
            if (t+T <= k and d[t+T][v] > dtu+L)
            {
                d[t+T][v]=dtu+L;
                heap.push(iii(d[t+T][v], ii(t+T, v)));
            }
        }
    }
}

main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d", &test);
    while (test--)
    {
        load_data();
        dijkstra();
        printf("%d\n", res>=oo?-1:res);
    }
}
