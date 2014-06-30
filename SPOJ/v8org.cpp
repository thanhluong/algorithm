#include <iostream>
#include <vector>

using namespace std;

const int max_n = 10000+1;

vector<int> adj[max_n];
int k, res = 0;

inline int dfs(int u)
{
    int v, count = 1;
    for (vector<int>::iterator it=adj[u].begin(); it != adj[u].end(); it++)
    {
        v = *it;
        count += dfs(v);
    }
    //cout << u << " " << count << endl;
    if (count >= k)
    {
        res++;
        count = 0;
    }
    return count;
}

main()
{
    int n, u, v;
    cin >> k >> n;
    for (int u=2; u <= n; u++)
    {
        cin >> v;
        adj[v].push_back(u);
    }
    dfs(1);
    cout << res;
}
