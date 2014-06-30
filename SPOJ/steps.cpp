#include <iostream>
#include <cstring>

using namespace std;

const int mod = 14062008;

main()
{
    int i, n, k, tmp;
    cin >> n >> k;
    int f[n+1];
    memset(f, 0, sizeof(f));
    while (k--)
    {
        cin >> tmp;
        f[tmp] = -1;
    }
    f[1] = 1;
    for (i=2; i <= n; i++)
        if (f[i] == -1)
            f[i] = 0;
        else
            f[i] = (f[i-1]+f[i-2])%mod;
    cout << f[n];
}
