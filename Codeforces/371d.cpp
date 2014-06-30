#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N=4*100000;

int n, i, m, type, p, x, k, a[N], v[N], real[N];

inline void increase(int p, int x)
{
    int i, j, remain;
    if ((i=real[p]) > n) return ;
    while (i <= n)
    {
        remain=a[i]-v[i];
        if (x <= remain)
        {
            v[i]+=x;
            break;
        }
        x-=remain; v[i]=a[i]; i++;
    }
    for (j=i-1; j >= real[p]; j--) real[j]=i;
    /*for (k=1; k <= n; k++) cout << v[k] << " ";
    cout << endl;*/
}

main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (i=1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        real[i]=i;
    }
    memset(v, 0, sizeof(v));
    scanf("%d", &m);
    while (m--)
    {
        scanf("%d", &type);
        if (type-1)
        {
            scanf("%d", &k);
            printf("%d\n", v[k]);
        }
        else
        {
            scanf("%d%d", &p, &x);
            increase(p, x);
        }
    }
}
