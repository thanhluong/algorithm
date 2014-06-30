#include <iostream>

using namespace std;

int n, m, a, remain=0, COUNT=0;

main()
{
    cin >> n >> m;
    while (n--)
    {
        cin >> a;
        if (remain < a)
        {
            COUNT++;
            remain=m;
        }
        remain-=a;
    }
    cout << COUNT;
}
