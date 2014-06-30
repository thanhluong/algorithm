#include <iostream>

using namespace std;

const int m = 20122007;

inline long long exp(int d)
{
    if (!d) return 1;
    long long half = exp(d/2);
    if (d%2)
        return (half*half*3)%m;
    else
        return (half*half)%m;
}

main()
{
    int d, a, res=1;
    cin >> a;
    for (d=1; d*d <= a; d++)
    {
        if (a%d) continue;
        res = (res*(exp(d)-1))%m;
        if (d*d < a) res = (res*(exp(a/d)-1))%m;
    }
    cout << res;
}

