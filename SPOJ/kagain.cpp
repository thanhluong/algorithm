#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

const int max_n = 30000+1;

int n, a[max_n+1], l[max_n], r[max_n];
stack<int> stack_l, stack_r;

inline int amount(int i)
{
    return (r[i]-l[i]+1)*a[i];
}

inline void kagain()
{
    int i, j;
    cin >> n;
    for (i=1; i <= n; i++) cin >> a[i];
    a[0] = (a[n+1] = 0);
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
    stack_r.push(n+1);
    for (i=n; i >= 1; i--)
    {
        while (true)
        {
            j = stack_r.top();
            if (a[j] < a[i]) break;
            stack_r.pop();
        }
        r[i] = j-1;
        stack_r.push(i);
    }
    j = 1;
    for (i=2; i <= n; i++)
        if ((amount(i) > amount(j)) or (amount(i)==amount(j) and l[i] < l[j]))
            j = i;
    cout << amount(j) << " " << l[j] << " " << r[j] << endl;
}

main()
{
    short t;
    cin >> t;
    while (t--) kagain();
}
