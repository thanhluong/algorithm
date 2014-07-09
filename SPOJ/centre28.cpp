#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>

#define x first
#define y second
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
typedef vector<int> vi;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;

const ll N=30000+1;
const ll oo=2000000000;

typedef ll arr[N];

inline ll gcd(ll a, ll b)
{
    return (a ? gcd(b%a, a) : b);
}

int n, u, COUNT=0;
arr f1, fn, d1, dn;
vector<ii> adj[N];
vector<ll> res;
itr(ll) it;

inline void load_data()
{
    int m, u, v, d;
    scanf("%d%d", &n, &m);
    LOOP(m)
    {
        scanf("%d%d%d", &u, &v, &d);
        adj[u].push_back(ii(d, v));
        adj[v].push_back(ii(d, u));
    }
}

inline void dijkstra(ll u, arr &d, arr &way)
{
    ll v, w, du; itr(ii) it;
    priority_queue<ii, vector<ii>, greater<ii> > heap;
    FOR(v, 1, n)
    {
        way[v]=0;
        d[v]=oo;
    }
    d[u]=0; way[u]=1;
    heap.push(ii(0, u));
    while (heap.size())
    {
        u=heap.top().y; du=heap.top().x;
        heap.pop();
        if (du != d[u]) continue;
        IT(it, &adj[u])
        {
            v=it->y; w=it->x;
            if (d[v]==du+w)
                way[v]+=way[u];
            else if (d[v] > du+w)
            {
                d[v]=du+w;
                way[v]=way[u];
                heap.push(ii(d[v], v));
            }
        }
    }
}

main()
{
    freopen(input_file, "r", stdin);
    //freopen(output_file, "w", stdout);
    load_data();
    dijkstra(1, d1, f1);
    dijkstra(n, dn, fn);
    FOR(u, 2, n-1)
    {
        //cout << f1[u] << " " << fn[u] << endl;
        if (d1[u]+dn[u] != d1[n] or f1[u]*fn[u] != f1[n])
            res.push_back(u);
    }
    printf("%d\n", res.size());
    IT(it, &res)
        printf("%d\n", *it);
}
