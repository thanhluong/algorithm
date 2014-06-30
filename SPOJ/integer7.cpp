#include <iostream>
#include <cmath>

#define x first
#define y second

using namespace std;

typedef pair<long long, long long> ii;

const long long oo = 1000000000;

long long gcd;

inline ii solve_gcd(long long a, long long b)
{
    if (abs(b) < abs(a)) swap(a, b);
    if (b%a)
    {
        ii recur = solve_gcd(b%a, a);
        long long y = recur.x;
        long long x = (gcd-b*y)/a;
        return ii(x, y);
    }
    else
    {
        gcd = a;
        return (ii(1, 0));
    }
}

inline ii solve(long long a, long long b, long long c)
{
    ii sg = solve_gcd(a, b);
    if (c%gcd)
        return ii(oo, oo);
    return ii(sg.x*c/gcd, sg.y*c/gcd);
}

main()
{
    long long a_1, b_1, a_2, b_2;
    cin >> a_1 >> b_1 >> a_2 >> b_2;
    ii res = solve(a_1, -a_2, b_2-b_1);
    cout << res.x << " " << res.y;
}
