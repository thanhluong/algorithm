#include <cstdio>
#include <cstring>

using namespace std;

const int N=100000+1;

int n, m;
bool watched[N];

main()
{
    memset(watched, false, sizeof(watched));
    scanf("%d", &n);
    while (--n)
    {
        scanf("%d", &m);
        watched[m]=true;
    }
    m=1;
    while (watched[m]) m++;
    printf("%d", m);
}
