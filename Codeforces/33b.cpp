#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int oo=1000000000;
const char Z='z'+1;

typedef char str[300000];

str A, B;
int n, c, i, f[Z][Z], l_A, l_B, optimal, total=0;
char u, v, t;

inline void floyd()
{
    char u, v, t;
    for (t='a'; t <= 'z'; t++)
        for (u='a'; u <= 'z'; u++)
            for (v='a'; v <= 'z'; v++)
            {
                if (f[u][v] > f[u][t]+f[t][v])
                    f[u][v]=f[u][t]+f[t][v];
                //printf("%c %c %d\n", u, v, f[u][v]);
            }
}

main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%s%s", &A, &B);
    l_A=strlen(A); l_B=strlen(B);
    if (l_A != l_B)
    {
        printf("-1");
        return 0;
    }
    scanf("%d", &n);
    for (u='a'; u <= 'z'; u++)
        for (v='a'; v <= 'z'; v++)
            f[u][v]=(u==v ? 0 : oo);
    while (n--)
    {
        scanf(" %c %c%d", &u, &v, &c);
        f[u][v]=min(c, f[u][v]);
    }
    floyd();
    for (i=0; i < l_A; i++)
    {
        u=A[i]; v=B[i]; optimal=oo;
        for (t='a'; t <= 'z'; t++)
            if (f[u][t]+f[v][t] < optimal)
            {
                optimal=f[u][t]+f[v][t];
                A[i]=t;
            }
        if (optimal >= oo)
        {
            printf("-1");
            return 0;
        }
        total+=optimal;
    }
    printf("%d\n%s", total, A);
}
