#include <fstream>
#include <vector>
#include <cstring>

#define x first
#define y second

using namespace std;

ifstream fin ("maze.inp");
ofstream fout ("maze.out");

typedef pair<int, int> ii;

const int max_n = 3000+1;
const int max_v = max_n*max_n;
const int t     = 1;
const int d     = 2;
const int l     = 3;
const int r     = 4;

int par[max_n*max_n];
bool adj[max_n*max_n][r+1];
int get_vertex[max_n][max_n];

inline int find_set(int u)
{
    if (par[u]==u)
        return u;
    else
        return (par[u] = find_set(par[u]));
}

inline void join(int u, int v)
{
    par[find_set(u)] = find_set(v);
}

inline void maze()
{
    memset(adj, true, sizeof(adj));
    memset(get_vertex, 0, sizeof(get_vertex));
    int n, n_vertex = 0, i, j, u, v; char tmp;
    fin >> n;
    for (i=1; i <= n; i++)
        for (j=1; j <= n; j++)
        {
            fin >> tmp;
            if (tmp=='0') get_vertex[i][j] = ++n_vertex;
        }
    for (u=1; u <= n_vertex; u++) par[u] = u;
    vector<ii> edge;
    for (i=1; i <= n; i++)
        for (j=1; j <= n; j++)
            if (get_vertex[i][j])
            {
                u = get_vertex[i][j];
                if (i > 1 && get_vertex[i-1][j])
                {
                    v = get_vertex[i-1][j];
                    if (adj[u][t])
                    {
                        edge.push_back(ii(u, v));
                        adj[v][d] = false;
                    }
                }
                if (i < n && get_vertex[i+1][j])
                {
                    v = get_vertex[i+1][j];
                    if (adj[u][d])
                    {
                        edge.push_back(ii(u, v));
                        adj[v][t] = false;
                    }
                }
                if (j > 1 && get_vertex[i][j-1])
                {
                    v = get_vertex[i][j-1];
                    if (adj[u][l])
                    {
                        edge.push_back(ii(u, v));
                        adj[v][r] = false;
                    }
                }
                if (j < n && get_vertex[i][j+1])
                {
                    v = get_vertex[i][j+1];
                    if (adj[u][r])
                    {
                        edge.push_back(ii(u, v));
                        adj[v][l] = false;
                    }
                }
            }
    vector<ii>::iterator it;
    if (edge.size() > n_vertex-1)
    {
        fout << "NO" << endl;
        return ;
    }
    int count = 0;
    for (it=edge.begin(); it != edge.end(); it++)
    {
        u = it->x; v=it->y;
        if (u != v)
        {
            count++;
            join(u, v);
        }
        else
        {
            fout << "NO" << endl;
            return ;
        }
    }
    if (count < n_vertex-1)
    {
        fout << "NO" << endl;
        return ;
    }
    fout << "YES" << endl;
}

main()
{
    short test;
    fin >> test;
    while (test--) maze();
}
