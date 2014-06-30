#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>

#define x first
#define y second

using namespace std;

typedef pair<int, bool> ib;

const int N=100000+1;

int n, m, i, u, v, w, SIZE[N];
vector<ib> adj[N];
long long res=0, up[N], down[N];
bool avail[N], is_lucky;

inline bool lucky(int n)
{
    int last_digit;
    while (n)
    {
        last_digit=n%10;
        if (last_digit-4 and last_digit-7) return false;
        n/=10;
    }
    return true;
}

inline void init_SIZE(int u)
{
    int v;
    avail[u]=false; SIZE[u]=1;
    for (vector<ib>::iterator it=adj[u].begin(); it != adj[u].end(); it++)
    {
        v=it->x;
        if (avail[v])
        {
            init_SIZE(v);
            SIZE[u]+=SIZE[v];
        }
    }
}

inline void init_down(int u)
{
    int v; bool is_lucky;
    vector<ib>::iterator it;
    avail[u]=false; down[u]=0;
    for (it=adj[u].begin(); it != adj[u].end(); it++)
    {
        v=it->x; is_lucky=it->y;
        if (avail[v])
        {
            init_down(v);
            down[u]+=(is_lucky ? SIZE[v] : down[v]);
        }
    }
}

inline void init_up(int u)
{
    int v; bool is_lucky;
    vector<ib>::iterator it;
    avail[u]=false;
    for (it=adj[u].begin(); it != adj[u].end(); it++)
    {
        v=it->x; is_lucky=it->y;
        if (avail[v])
        {
            up[v]=(is_lucky ? n-SIZE[v] : up[u]+down[u]-down[v]);
            init_up(v);
        }
    }
}

main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (i=1; i < n; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        is_lucky=lucky(w);
        adj[u].push_back(ib(v, is_lucky));
        adj[v].push_back(ib(u, is_lucky));
    }
    memset(avail, true, sizeof(avail));
    init_SIZE(1);
    memset(avail, true, sizeof(avail));
    init_down(1);
    memset(avail, true, sizeof(avail));
    up[1]=0;
    init_up(1);
    for (u=1; u <= n; u++)
    {
        //cout << u << " " << SIZE[u] << " " << down[u] << " " << up[u] << endl;
        res+=(up[u]+down[u])*(up[u]+down[u]-1);
    }
    cout << res;
}
