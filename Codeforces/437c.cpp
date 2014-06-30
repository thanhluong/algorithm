#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef unsigned long long ull;
typedef vector<int> vi;

const int N=1000+1;

int n, m, x, y;
ull v[N], COST=0;
bool removed[N];
vi toy, adj[N];

inline ull remove_before(int x, int y)
{
    ull cost=0;
    vi::iterator it;
    for (it=adj[x].begin(); it != adj[x].end(); it++)
        cost += v[*it];
    for (it=adj[y].begin(); it != adj[y].end(); it++)
        if (*it != x) cost += v[*it];
    return cost;
}

inline void REMOVE(int x)
{
    removed[x]=true;
    for (vi::iterator it=adj[x].begin(); it != adj[x].end(); it++)
        if (!removed[*it]) COST += v[*it];
}

inline bool comp(int x, int y)
{
    return (remove_before(x, y) < remove_before(y, x));
}

main()
{
    cin >> n >> m;
    for (x=1; x <= n; x++)
    {
        cin >> v[x];
        toy.push_back(x);
    }
    while (m--)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    sort(toy.begin(), toy.end(), comp);
    memset(removed, false, sizeof(removed));
    for (vi::iterator it=toy.begin(); it != toy.end(); it++)
    {
        cout << *it << endl;
        REMOVE(*it);
    }
    cout << COST;
}
