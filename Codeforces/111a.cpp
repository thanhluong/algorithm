#include <iostream>
#include <cstdio>

using namespace std;

long long n, x, y, i;

inline long long sqr(long long n)
{
    return n*n;
}

main()
{
    cin >> n >> x >> y;
    if (y < n or n-1+sqr(y-n+1) < x)
    {
        cout << -1;
        return 0;
    }
    for (i=1; i < n; i++) cout << 1 << endl;
    cout << y-n+1;
}
