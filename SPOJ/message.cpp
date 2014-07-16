#include <bits/stdc++.h>

#define X first
#define Y second
#define itr(t) vector<t>::iterator
#define LOOP(n) while (n--)
#define FOR(i, a, b) for (i=(a); i <= (b); i++)
#define FORD(i, a, b) for (i=(a); i >= (b); i--)
#define IT(i, v) for (i=(v)->begin(); i != (v)->end(); i++)
#define abs(x) ((x) > 0 ? (x) : -(x))
#define input_file "input.txt"
#define output_file "output.txt"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vi;
typedef stack<ll> si;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;

const int N=10000+1;

int n, m, u, v, par[N], number[N], low[N], COUNT=0, res=0;
bool /*sender[N], ADJ[N][N], dfsed[N],*/ avail[N], has_anc[N];
si S;
vi adj[N];
vector<ii> edge;

inline void error(int n)
{
    cout << fixed << setprecision(n+1);
}

inline ll gcd(ll a, ll b)
{
    return (a ? gcd(b%a, a) : b);
}

/*inline ll find_set(ll u)
{
    if (par[u] != u)
        par[u]=find_set(par[u]);
    return par[u];
}

inline void join(ll u, ll v)
{
    par[find_set(u)]=find_set(v);
}*/

inline void dfs(ll u)
{
    itr(ll) it; ll v;
    low[u]=(number[u]=++COUNT); S.push(u);
    IT(it, &adj[u])
    {
        v=*it;
        if (par[v]) continue;
        if (number[v])
            low[u]=min(low[u], number[v]); //visited
        else
        {
            dfs(v);
            low[u]=min(low[u], low[v]);
        }
    }
    if (low[u]==number[u])
    {
        while (true)
        {
            v=S.top(); S.pop();
            par[v]=u;
            if (v==u) break;
        }
    }
}

inline void process()
{
    //memset(ADJ, false, sizeof(ADJ));
    itr(ii) it;
    ll u, v;
    IT(it, &edge)
    {
        u=par[it->X]; v=par[it->Y];
        if (u != v)
        {
        //ADJ[u][v]=true;
        has_anc[v]=true;
        //cout << u << " " << v << endl;
        }
    }
}

/*inline void send(ll u, bool change)
{
    ll v;
    sender[u]=!change;
    avail[u]=false;
    FOR(v, 1, n)
        if (avail[v] and ADJ[u][v])
        {
            //cout << u << " " << v << endl;
            send(v, true);
        }
}*/

main()
{
    //freopen(input_file, "r", stdin);
    //freopen(output_file, "w", stdout);
    scanf("%d%d", &n, &m);
    LOOP(m)
    {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        edge.push_back(ii(u, v));
    }
    FOR(u, 1, n)
        if (!number[u])
            dfs(u);
    memset(has_anc, false, sizeof(has_anc));
    process();
    /*memset(dfsed, false, sizeof(dfsed));
    FOR(u, 1, n)
    {
        v=par[u];
        cout << v << endl;
        if (!dfsed[v])
        {
            dfsed[v]=true; sender[v]=true;
            memset(avail, true, sizeof(avail));
            send(v, false);
        }
    }*/
    memset(avail, true, sizeof(avail));
    FOR(u, 1, n)
    {
        //cout << u << " " << sender[u] << endl;
        //res+=sender[u];
        v=par[u];
        if (avail[v])
        {
            res+=!has_anc[v];
            avail[v]=false;
        }
    }
    printf("%d", res);
}
