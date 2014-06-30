#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

typedef vector<int> vi;

const int N=2000+1;

vi new_group;
vi::iterator it;
vector<vi> group;
vector<vi>::iterator it_group;
int n, u, v, COUNT=0, manager[N];
bool superior[N][N], ok, added;

inline void filter(int u)
{
    int v=u;
    memset(superior[u], false, sizeof(superior[u]));
    while (true)
    {
        //cout << u << endl;
        v=manager[v];
        if (v==-1)
        {
            //cout << u << " " << v << endl;
            return ;
        }
        superior[u][v]=true;
    }
}

main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (u=1; u <= n; u++)
    {
        //par[u]=u;
        scanf("%d", &v);
        manager[u]=v;
    }
    for (u=1; u <= n; u++)
        filter(u);
    for (u=1; u <= n; u++)
    {
        added=false;
        for (it_group=group.begin(); it_group != group.end(); it_group++)
        {
            ok=true;
            for (it=it_group->begin(); it != it_group->end(); it++)
                if (superior[u][*it] or superior[*it][u])
                {
                    ok=false;
                    break;
                }
            if (ok)
            {
                it_group->push_back(u);
                added=true;
                break;
            }
        }
        if (!added)
        {
            //cout << u << endl;
            new_group=vi();
            new_group.push_back(u);
            group.push_back(new_group);
        }
    }
    /*for (it_group=group.begin(); it_group != group.end(); it_group++)
    {
        for (it=it_group->begin(); it != it_group->end(); it++)
            cout << *it << " ";
        cout << endl;
    }*/
    //cout << group[0].size() << " " << group[1].size() << endl;
    printf("%d", group.size());
}
