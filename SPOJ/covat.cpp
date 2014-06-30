#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

#define x first
#define y second

using namespace std;

ifstream fin ("covat.inp");
ofstream fout ("covat.out");

const int max_m = 100+1;
const int max_n = 100+1;

struct t_edge
{
    int w, x1, y1, x2, y2;
    t_edge(int a, int b, int c, int d, int e)
    {
        w = a;
        x1 = b; y1 = c;
        x2 = d; y2 = e;
    }
};

typedef pair<int, int> ii;

int m, n;
vector<t_edge> edge;
ii par[max_m][max_n];
char cell[max_m][max_n];

inline ii find_set(int i, int j)
{
    if (par[i][j]==ii(i, j))
        return ii(i, j);
    else
        return (par[i][j] = find_set(par[i][j].x, par[i][j].y));
}

inline void join(int x1, int y1, int x2, int y2)
{
    ii child = find_set(x1, y1), parent = find_set(x2, y2);
    par[child.x][child.y] = ii(parent.x, parent.y);
}

inline bool comp(t_edge a, t_edge b)
{
    return (a.w < b.w);
}

inline bool valid(int i, int j)
{
    return (i && i <= m && j && j <= n && cell[i][j] != '#');
}

inline void bfs(int i, int j)
{
    bool free[max_m][max_n];
    memset(free, true, sizeof(free));
    queue<ii> q;
    q.push(ii(i, j));
    free[i][j] = false;
    int k, l, aa, bb, d = 0;
    while (q.size())
    {
        d++;
        k = q.front().x; l = q.front().y;
        q.pop();
        for (aa=-1; aa <= 1; aa++)
            for (bb=-1; bb <= 1; bb++)
                if ((aa+bb==-1 or aa+bb==1) and valid(k+aa, l+bb) and free[k+aa][l+bb])
                {
                    if (cell[k+aa][l+bb]=='C' or cell[k+aa][l+bb]=='S')
                        edge.push_back(t_edge(d, i, j, k+aa, l+bb));
                    else
                        q.push(ii(k+aa, l+bb));
                    free[k+aa][l+bb] = false;
                }
    }
}

main()
{
    int count = 0, i, j, k, l, n_edge = 0, res = 0;;
    fin >> m >> n;
    for (i=1; i <= m; i++)
        for (j=1; j <= n; j++)
        {
            par[i][j] = ii(i, j);
            fin >> cell[i][j];
        }
    for (i=1; i <= m; i++)
        for (j=1; j <= n; j++)
            if (cell[i][j] == 'C' or cell[i][j]=='S')
            {
                count++;
                bfs(i, j);
            }
    sort(edge.begin(), edge.end(), comp);
    for (vector<t_edge>::iterator it=edge.begin(); it != edge.end(); it++)
    {
        i = it->x1; j=it->y1; k=it->x2; l=it->y2;
        if (find_set(i, j) != find_set(k, l))
        {
            join(i, j, k, l);
            res += it->w;
            if (++n_edge == count) break;
        }
    }
    fout << res;
    fin.close(); fout.close();
}
