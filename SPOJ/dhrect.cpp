#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 300000+1;

long long n, d[max_n];

inline void dhrect()
{
    cin >> n;
    long long i, prev, n_pair = 0;
    for (i=1; i <= n; i++) cin >> d[i];
    sort(d+1, d+n+1);
    for (i=n-1; i >= 1; i--)
        if (d[i] == d[i+1])
        {
            if (++n_pair == 2)
            {
                cout << d[i]*prev << endl;
                return ;
            }
            prev = d[i];
            d[i] = -1;
        }
    cout << -1 << endl;
}

main()
{
    short t;
    cin >> t;
    while (t--) dhrect();
}
