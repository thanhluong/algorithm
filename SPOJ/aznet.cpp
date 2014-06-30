#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

typedef pair<int, int> ii;

const int N=10000+1;

int n, m, c, u, v, i, j, max_A, max_B, a[N], b[N], par[N];
vector<ii> A, B;

inline int find_set(int u)
{
    if (par[u] != u)
        par[u]=find_set(par[u]);
    return par[u];
}

inline void join(int u, int v)
{
    par[find_set(u)]=find_set(v);
}

inline void reset()
{
    for (int u=1; u <= n; u++) par[u]=u;
}

main()
{
    freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    a[0]=0; b[0]=0;
    for (i=1; )
    while (m--)
    {
        scanf("%d%d%d", &c, &u, &v);
        if (c-1)
            A.push_back(ii(u, v));
        else
            B.push_back(ii(u, v));
    }
    reset();
    TRY(A, max_A);
    reset();
    TRY(B, max_B
    j=max_A;
    for (i=n-1-max_B; i < max_A; i++)
        if (a[i]+b[n-1-i] < a[j]+b[n-1-j])
            j=i;
    build_spanning_tree(j, n-1-j);
}
