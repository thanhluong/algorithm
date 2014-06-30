#include <iostream>

using namespace std;

main()
{
    int n, m, i, j, f[10002], t[10001];
    cin >> n >> m;
    t[0] = 0;
    for (i=1; i <= n; i++)
    {
        cin >> t[i];
        t[i] += t[i-1];
    }
    f[n+1] = 0;
    for (i=n; i >= 1; i--)
    {
            f[i] = f[i+1];
            for (j=1; j <= m; j++)
                if (i+2*j <= n+1)
                    f[i] = max(f[i], t[i+j-1]-t[i-1]+f[i+2*j]);
    }
    cout << f[1];
}
//1 2 3 4 5 6
