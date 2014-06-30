#include <cstdio>
#include <cmath>

using namespace std;

const long long N=50000+1;

long long n, i, match[N], each=0, delta, total=0;

main()
{
    scanf("%d", &n);
    for (i=1; i <= n; i++)
    {
        scanf("%d", &match[i]);
        each+=match[i];
    }
    each/=n;
    for (i=1; i <= n; i++)
    {
        delta=each-match[i];
        match[i+1]-=delta;
        total+=abs(delta);
    }
    printf("%lld", total);
}
