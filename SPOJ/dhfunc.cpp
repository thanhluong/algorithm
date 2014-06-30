#include <iostream>
#include <cstring>

using namespace std;

typedef unsigned long long ull;

const int max_id = 501;

ull x, y, a, b, m, fib[max_id], f[max_id][max_id], count=0;

inline ull gcd(ull a, ull b)
{
    return (a ? gcd(b%a, a) : b);
}

inline ull fmul(ull a, ull b)
{
    if (!b) return 0;
    if (!(b-1)) return a;
    if (b%2)
        return (fmul(a, b/2)*2+a)%m;
    else
        return (fmul(a, b/2)*2)%m;
}

/*inline void init()
{
    fib[0]=0; fib[1]=1;
    for (int i=2; i < max_id; i++) fib[i] = (fib[i-1]+fib[i-2])%m;
}


inline ull get_f(int x, int y)
{
    if (!y) return x;
    if (!x) return y;
    if (f[x][y]) return f[x][y];
    cout << ++count << endl;
    return (fmul(a, get_f(x-1, y))+fmul(b, get_f(x, y-1))+fib[gcd(x, y)])%m;
}*/

inline void dhfunc()
{
    cin >> x >> y >> a >> b >> m;
    int i, j;
    fib[1] = 1; fib[2] = 1;
    for (i=3; i < max_id; i++) fib[i] = (fib[i-1]+fib[i-2])%m;
    for (i=0; i <= x; i++) f[i][0] = i%m;
    for (i=0; i <= y; i++) f[0][i] = i%m;
    for (i=1; i <= x; i++)
        for (j=1; j <= y; j++)
        {
            //cout << i << " " << j << endl;
            f[i][j] = (fmul(a, f[i-1][j])+fmul(b, f[i][j-1])+fib[gcd(i, j)])%m;
        }
    cout << f[x][y] << endl;
}
//f[0][]
main()
{
    short t;
    cin >> t;
    while (t--) dhfunc();
}

