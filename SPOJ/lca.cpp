#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

const int N=1000+1;

vector<int> child[N];
int par[N], level[N], n, m, q, u, v, test, CASE;

inline void dfs(int u, int LEVEL)
{
    level[u]=LEVEL;
    for (vector<int>::iterator it=child[u].begin(); it != child[u].end(); it++)
        dfs(*it, LEVEL+1);
}

inline void init()
{
    int u, root;
    for (u=1; u <= n; u++)
        if (!par[u])
        {
            root=u;
            break;
        }
    dfs(root, 0);
}

inline int lca(int u, int v)
{
    while (level[u] > level[v]) u=par[u];
    while (level[v] > level[u]) v=par[v];
    while (u != v)
    {
        u=par[u];
        v=par[v];
    }
    return u;
}

main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d", &test);
    for (CASE=1; CASE <= test; CASE++)
    {
        memset(par, 0, sizeof(par));
        scanf("%d", &n);
        for (u=1; u <= n; u++)
        {
            child[u]=vector<int>();
            scanf("%d", &m);
            while (m--)
            {
                scanf("%d", &v);
                par[v]=u;
                child[u].push_back(v);
            }
        }
        init();
        printf("Case %d:\n", CASE);
        scanf("%d", &q);
        while (q--)
        {
            scanf("%d%d", &u, &v);
            printf("%d\n", lca(u, v));
        }
    }
}
