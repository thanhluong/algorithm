#include <iostream>
#include <algorithm>

#define x first
#define y second

using namespace std;

typedef pair<int, int> ii;

const int max_n = 100000+1;

ii O;

inline bool ccw(ii a, ii b, ii c)
{
    int u = b.x-a.x, v = b.y-a.y;
    int uu = c.x-b.x, vv = c.y-b.y;
    return (u*vv > uu*v);
}

inline bool comp(ii a, ii b)
{
    return ccw(O, a, b);
}

main()
{
    int n, i, j, res[max_n];
    ii p[max_n];
    cin >> n;
    for (i=1; i <= n; i++)
    {
        cin >> p[i].x >> p[i].y;
        if (p[1].y > p[i].y)
            swap(p[1], p[i]);
    }
    O = p[1];
    sort(p+2, p+n+1, comp);
    j = 3;
    res[1] = 1; res[2] = 2; res[3] = 3;
    for (i=4; i <= n; i++)
    {
        while (!ccw(p[res[j-1]], p[res[j]], p[i])) j--;
        res[++j] = i;
    }
    cout << j << endl;
    for (i=1; i <= j; i++)
        cout << p[res[i]].x << " " << p[res[i]].y << endl;
}
