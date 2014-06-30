#include <stack>
#include <cmath>
#include <cstring>
#include <cstdio>

using namespace std;

const int max_n = 2000+1;

int n, a[max_n+1], l[max_n], r[max_n], max_area = 0;

inline int area(int i)
{
    return a[i]*(r[i]-l[i]+1);
}

inline void add_line()
{
    int i, j; bool c;
    a[0] = (a[n+1] = -1);
    for (i=1; i <= n; i++)
    {
        scanf("%d", &c);
        a[i] = c*(a[i]+c);
    }
    stack<int> stack_l;
    stack_l.push(0);
    for (i=1; i <= n; i++)
    {
        while (true)
        {
            j = stack_l.top();
            if (a[j] < a[i]) break;
            stack_l.pop();
        }
        l[i] = j+1;
        stack_l.push(i);
    }
    stack<int> stack_r;
    stack_r.push(n+1);
    for (i=n; i >= 1; i--)
    {
        while (true)
        {
            j = stack_r.top();
            if (a[j] < a[i]) break ;
            stack_r.pop();
        }
        r[i] = j-1;
        stack_r.push(i);
    }
    for (i=1; i <= n; i++)
        max_area = max(max_area, area(i));
}

main()
{
    int m;
    scanf("%d%d", &m, &n);
    memset(a, 0, sizeof(a));
    while (m--) add_line();
    printf("%d", max_area);
}
