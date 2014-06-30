#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

const int oo=2000000000;

int n, l, m, r, i, j, v, res=oo;
vector<int> b;

inline int abs(int n)
{
    return (n > 0 ? n : -n);
}

main()
{
    scanf("%d", &n);
    for (i=0; i < n; i++)
    {
        scanf("%d", &v);
        b.push_back(-v);
    }
    sort(b.begin(), b.end());
    for (i=0; i < n; i++)
    {
        scanf("%d", &v);
        l=0; r=n-1;
        while (l <= r)
        {
            m=(l+r)/2;
            if (b[m]==v)
            {
                printf("0");
                return 0;
            }
            if (b[m] < v)
                l=m+1;
            else
                r=m-1;
        }
        for (j=max(m-6, 0); j <= min(m+6, n-1); j++)
            res=min(res, abs(v-b[j]));
    }
    printf("%d", res);
}
