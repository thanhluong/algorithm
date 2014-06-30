#include <iostream>
#include <vector>
#include <bitset>
#include <cstdio>
#include <cstring>

using namespace std;

typedef vector<int> vi;

const int N=10000+1;

int oo=30000*10000*4, a[N][5], f[N][17], sum[N][17], n, i, j, SUM, res;
vi hor, adj[17];
vi::iterator x, y;

inline bool check_horizontal(int n)
{
    bitset<4> a=n;
    int i;
    for (i=0; i < 3; i++)
        if (a[i] and a[i+1]) return false;
    //cout << a << endl;
    return true;
}

inline bool check_vertical(int m, int n)
{
    bitset<4> a=m, b=n;
    int i;
    for (i=0; i < 4; i++)
        if (a[i] and a[i]==b[i]) return false;
    //cout << a << " " << b << endl;
    return true;
}

inline void init()
{
    int i;
    vi::iterator I, J;
    for (i=0; i < 16; i++)
        if (check_horizontal(i))
            hor.push_back(i);
    for (I=hor.begin(); I != hor.end(); I++)
        for (J=hor.begin(); J != hor.end(); J++)
            if (check_vertical(*I, *J))
                adj[*I].push_back(*J);
}

inline void get_sum(int i)
{
    int j;
    vi::iterator I;
    for (I=hor.begin(); I != hor.end(); I++)
    {
        bitset<4> b=*I;
        sum[i][*I]=0;
        for (j=0; j < 4; j++)
            sum[i][*I]+=a[i][j+1]*b[j];
    }
}

inline bool except()
{
    res=-oo;
    for (i=1; i <= n; i++)
        for (j=1; j <= 4; j++)
        {
            if (a[i][j] >= 0) return false;
            res=max(res, a[i][j]);
        }
    return true;
}

main()
{
    init();
    //freopen("input.txt", "r", stdin);
    init();
    scanf("%d", &n);
    for (j=1; j <= 4; j++)
        for (i=1; i <= n; i++)
            scanf("%d", &a[i][j]);
    res=-oo;
    if (except())
    {
        cout << res;
        return 0;
    }
    for (i=1; i <= n; i++) get_sum(i);
    memset(f[0], 0, sizeof(f[0]));
    for (i=1; i <= n; i++)
        for (x=hor.begin(); x != hor.end(); x++)
        {
            j=*x;
            f[i][j]=-oo; SUM=sum[i][j];
            for (y=adj[j].begin(); y != adj[j].end(); y++)
                f[i][j]=max(f[i][j], f[i-1][*y]+SUM);
            if (i==n) res=max(res, f[i][j]);
        }
    cout << res;
}
