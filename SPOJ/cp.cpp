#include <iostream>
#include <algorithm>

/* Make list numbers that they smaller or equal to v */

using namespace std;

main()
{
    int n, v, i, l, r, m, a[100001];
    cin >> n >> v;
    for (int i=1; i <= n; i++) cin >> a[i];
    sort(a+1, a+n+1);
    l = 1; r = n;
    while (l+1 != r)
    {
        m = (l+r)/2;
        if (a[m] > v)
            r = m;
        else l = m;
    }
    cout << r;
}
