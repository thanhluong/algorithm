#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>

#define x first
#define y second

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

const int M=1000000007;
const int N=100000+1;

vii adj[N];
int n, u, v, w;
bool avail[N];
long long sum[N], res=0;

inline void dfs(int u)
{
    avail[u]=false; sum[u]=0;
    int v, w, child=0; long long SUM=0;
    for (vii::iterator it=adj[u].begin(); it != adj[u].end(); it++)
    {
        v=it->x; w=it->y;
        if (avail[v])
        {
            child++;
            dfs(v);
            SUM=(SUM+sum[u]*((w*sum[v])%M))%M;
            sum[u]=(sum[u]+w*sum[v])%M;
            //cout << u << " " << SUM << " " << sum[u] << endl;
        }
    }
    //cout << u << " " << SUM << " " << sum[u] << endl;
    res=(res+sum[u]+SUM)%M;
    sum[u]++;
}

main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    while (--n)
    {
        scanf("%d%d%d", &u, &v, &w);
        adj[u].push_back(ii(v, w));
        adj[v].push_back(ii(u, w));
    }
    memset(avail, true, sizeof(avail));
    dfs(1);
    cout << res;
}
