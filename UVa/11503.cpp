#include <iostream>
#include <map>
#include <vector>
#include <cstdio>

#define x first
#define y second

using namespace std;

typedef pair<int, int> ii;

const int N=4*100000+1;

int t, f, rear, u, v, par[N], SIZE[N];
string name_1, name_2;

inline void init()
{
    for (int u=1; u <= rear; u++)
    {
        par[u]=u;
        SIZE[u]=1;
    }
}

inline int find_set(int u)
{
    if (par[u]-u)
        par[u]=find_set(par[u]);
    return par[u];
}

inline void add_friend(int u, int v)
{
    u=find_set(u); v=find_set(v);
    if (u-v) SIZE[u]+=SIZE[v];
    par[v]=u;
}

main()
{
    //freopen("input.txt", "r", stdin);
    cin >> t;
    while (t--)
    {
        map<string, unsigned int> ID;
        vector<ii> edge;
        cin >> f;
        rear=0;
        while (f--)
        {
            cin >> name_1 >> name_2;
            if (!ID[name_1])
                ID[name_1]=++rear;
            if (!ID[name_2])
                ID[name_2]=++rear;
            edge.push_back(ii(ID[name_1], ID[name_2]));
        }
        init();
        for (vector<ii>::iterator it=edge.begin(); it != edge.end(); it++)
        {
            u=it->x; v=it->y;
            add_friend(u, v);
            cout << SIZE[par[u]] << endl;
        }
    }
}
