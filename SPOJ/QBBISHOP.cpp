#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <cmath>

#define x first
#define y second

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int N=200+1;

int n, m, p, q, s, t;
bool avail[N][N], possible[N][N];
ii start, des;
queue<iii> Q;
char readln;

inline void refine(int &X)
{
    X=n-X+1;
}

inline void load_data()
{
    int i, j;
    memset(avail, true, sizeof(avail));
    memset(possible, true, sizeof(possible));
    scanf("%d%d%d%d%d%d", &n, &m, &start.x, &start.y, &des.x, &des.y);
    refine(start.x);
    refine(des.x);
    //cin >> n >> m >> start.x >> start.y >> des.x >> des.y;
    while (m--)
    {
        scanf("%d%d", &i, &j);
        refine(i);
        possible[i][j]=false;
    }
}

inline bool valid(int i, int j)
{
    return (i and i <= n and j and j <= n);
}

inline void bfs()
{
    int i, I, J, N;
    ii cur;
    Q.push(iii(0, start));
    while (Q.size())
    {
        cur=Q.front().y;
        N=Q.front().x;
        Q.pop();
        if (cur==des)
        {
            printf("%d", N);
            return ;
        }
        //cout << cur.x << " " << cur.y << " " << N << endl;
        //cin >> readln;
        for (I=-1; I <= 1; I++)
            for (J=-1; J <= 1; J++)
                if (abs(I)==1 and abs(J)==1)
                    for (i=1; valid(cur.x+I*i, cur.y+J*i) and possible[cur.x+I*i][cur.y+J*i]; i++)
                    {
                        //cout << cur.x << " " << cur.y << "->" << cur.x+I*i << " " << cur.y+J*i << ": " << N+1 << endl;
                        if (avail[cur.x+I*i][cur.y+J*i])
                        {
                            avail[cur.x+I*i][cur.y+J*i]=false;
                            Q.push(iii(N+1, ii(cur.x+I*i, cur.y+J*i)));
                        }
                    }
    }
    printf("-1");
}

main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    load_data();
    bfs();
}
