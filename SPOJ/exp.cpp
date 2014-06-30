#include <queue>
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

typedef pair<int, int> ii;

inline int sharp(int a, int b)
{
    int xx = 0, yy = 0, zz = 9;
    while (a)
    {
        xx += a%10;
        a /= 10;
    }
    while (b)
    {
        yy = max(yy, b%10);
        zz = min(zz, b%10);
        b /= 10;
    }
    return (xx*yy+zz);
}

main()
{
    long long x, y;
    cin >> x >> y;
    if (x==y)
    {
        cout << 0;
        return 0;
    }
    if (y > 738)
    {
        cout << "NO";
        return 0;
    }
    queue<ii> q;
    while (q.size())
    {
        u = q.top().first; du = q.top().second();
        q.pop();
        v = sharp(x, u);
        if (avail[v])
        {
            q.push(v, du+1);
            avail[v] = false;
        }
        v = sharp(u, x);
        if (avail[v])
        {
            q.push(v, du+1);
            avail[v] = false;
        }
        v = sharp(u, u);
    }
}
