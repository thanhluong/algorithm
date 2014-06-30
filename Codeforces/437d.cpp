#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>

#define x first
#define y second

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const long long N=100000+1;

long long n, m, u, v, w, a[N], par[N], SIZE[N], res=0;
vector<iii> edge;

inline long long find_set(long long u)
{
    if (par[u]!=u)
        par[u]=find_set(par[u]);
    return par[u];
}

inline void join(long long u, long long v)
{
    long long set_u=find_set(u), set_v=find_set(v);
    SIZE[set_u]+=SIZE[set_v];
    par[set_v]=set_u;
}

main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for (u=1; u <= n; u++)
    {
        scanf("%d", &a[u]);
        par[u]=u;
        SIZE[u]=1;
    }
    while (m--)
    {
        scanf("%d%d", &u, &v);
        edge.push_back(iii(min(a[u], a[v]), ii(u, v)));
    }
    sort(edge.rbegin(), edge.rend());
    for (vector<iii>::iterator it=edge.begin(); it != edge.end(); it++)
    {
        u=it->y.x; v=it->y.y; w=it->x;
        if (find_set(u)==find_set(v)) continue;
        res+=w*SIZE[par[u]]*SIZE[par[v]];
        //printf("%d %d %d\n", w, SIZE[par[u]], SIZE[par[v]]);
        join(u, v);
    }
    printf("%.7f", (res*2)/(1.0*n*(n-1)));
}
