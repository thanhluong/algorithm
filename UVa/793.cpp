#include <sstream>
#include <iostream>
#include <cstdio>

using namespace std;

const int N=100000+1;

int t, n, u, v, sum, success, par[N];
char type;
string line;

inline void init()
{
    sum=0; success=0;
    for (int u=1; u <= n; u++) par[u]=u;
}

inline int find_set(int u)
{
    if (par[u]-u)
        par[u]=find_set(par[u]);
    return par[u];
}

inline void connect(int u, int v)
{
    par[find_set(u)]=find_set(v);
}

inline bool is_same_set(int u, int v)
{
    return find_set(u)==find_set(v);
}

main()
{
    //freopen("input.txt", "r", stdin);
    cin >> t;
    while (t--)
    {
        cin >> n; getline(cin, line);
        init();
        while (true)
        {
            getline(cin, line);
            if (!line.length()) break;
            istringstream request (line);
            request >> type >> u >> v;
            //cout << type << " " << u << " " << v << endl;
            if (type=='c')
                connect(u, v);
            else
            {
                sum++;
                success+=is_same_set(u, v);
            }
        }
        cout << success << "," << sum-success << endl;
        if (t) cout << endl;
    }
}
