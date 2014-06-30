#include <iostream>
#include <cmath>

using namespace std;

const int oo = 1 << 30;

int n, t[5002], res = 0;
char readln;

inline int find_k(int s, int f, int v)
{
    int m;
    cout << s << " " << f << " ";
    while (s <= f)
    {
        m = (s+f)/2;
        if (t[m]==v)
            break ;
        else if (t[m] < v)
            s = m+1;
        else f = m-1;
    }
    cout << m << endl;
    cin >> readln;
    return (t[m]-v ? 0 : m);
}

inline void two_sum()
{
    int i, j, k;
    cin >> n;
    t[0] = 0; t[n+1] = oo;
    for (i=1; i <= n; i++)
    {
        cin >> t[i];
        t[i] += t[i-1];
    }
    for (i=1; i < n; i++)
        for (j=n; j > i; j--)
            if ((!(t[j]+t[i-1])%2))
            {
                k = find_k(i, j-1, (t[j]+t[i-1])/2);
                if (k)
                {
                    res = max(res, j-i+1);
                    break;
                }
            }
    cout << res;
}

main()
{
    two_sum();
}
