#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N=50+1;
const int T=1000+1;
const int oo=1000000000;

int n, t, traveltime[N][N], c[N][N], f[T][N];

inline void load_data()
{
    int u, v;
    for (u=1; u <= n; u++)
        for (v=1; v <= n; v++)
            scanf("%d", &traveltime[u][v]);
    for (u=1; u <= n; u++)
        for (v=1; v <= n; v++)
            scanf("%d", &c[u][v]);
}

inline void optimize()
{
    int TIME, u, v;
    for (TIME=0; TIME <= t; TIME++)
        for (u=1; u <= n; u++)
        {
            if (!TIME and u==1)
            {
                f[0][1]=0;
                continue;
            }
            f[TIME][u]=oo;
            for (v=1; v <= n; v++)
                if (TIME >= traveltime[v][u])
                    f[TIME][u]=min(f[TIME][u], f[TIME-traveltime[v][u]][v]+c[v][u]);
            //cout << traveltime << " " << u << " " << f[traveltime][u] << endl;
        }
}

inline void print_result()
{
    int TIME, choice=0;
    for (TIME=1; TIME <= t; TIME++)
        if (f[TIME][n] < f[choice][n])
            choice=TIME;
    printf("%d %d\n", f[choice][n], choice);
}

main()
{
        //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    while (true)
    {
        scanf("%d%d", &n, &t);
        if (!n and !t) break;
        load_data();
        optimize();
        print_result();
    }
}
