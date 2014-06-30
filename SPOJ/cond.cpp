#include <iostream>
#include <cstring>

using namespace std;

typedef unsigned long long ull;

const int max_n = 11+1;

ull factorial[max_n], c[max_n][max_n];

inline void init()
{
    int i, j;
    factorial[0]=1;
    for (i=1; i < max_n; i++)
        factorial[i]=factorial[i-1]*i;
    memset(c, 0, sizeof(c));
    c[0][0]=1;
    for (i=1; i < max_n; i++)
    {
        c[0][i]=1;
        for (j=1; j <= i; j++)
            c[j][i]=c[j-1][i-1]+c[j][i-1];
    }
}

inline ull cond(int n)
{
    int i, j;
    ull res = 0, f[max_n];
    for (i=1; i <= n; i++)
    {
        f[i]=0;
        for (j=1; i+j-1 <= n; j++)
            f[i] += factorial[j-1]*factorial[n-i-j+1];
        cout << n << " " << i << " " << f[i] << endl;
    }
    for (i=1; i <= n; i++)
        res += c[i][n]*f[i];
    return res;
}

main()
{
    init();
    int n;
    while (true)
    {
        cin >> n;
        if (!(n+1)) break;
        cout << cond(n) << endl;
    }
}
