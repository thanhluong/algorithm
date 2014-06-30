#include <iostream>

using namespace std;

const int max_n = 1000;

inline int abs(int a)
{
    return (a > 0 ? a : -a);
}

main()
{
    int n, i, a[max_n], b[max_n], f[max_n][2], h, res;
    cin >> n >> a[1] >> b[1];
    f[1][0] = a[1]; f[1][1] = b[1];
    for (i=2; i <= n; i++)
    {
        cin >> a[i] >> b[i];
        f[i][0] = max(abs(b[i]-b[i-1])+f[i-1][0], abs(b[i]-a[i-1])+f[i-1][1])+a[i];
        f[i][1] = max(abs(a[i]-b[i-1])+f[i-1][0], abs(a[i]-a[i-1])+f[i-1][1])+b[i];
        //cout << f[1][1] << " " << f[i-1][1] << endl;
    }
    cout << max(f[n][0], f[n][1]);
}
