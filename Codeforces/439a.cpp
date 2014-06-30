#include <iostream>

using namespace std;

int n, t, T=0, d, crack=0;

main()
{
    cin >> n >> d;
    for (int i=1; i <= n; i++)
    {
        cin >> t;
        T+=t;
        if (T>d)
        {
            cout << -1;
            return 0;
        }
        if (i < n)
        {
            T+=10;
            crack+=2;
        }
        else
            crack+=(d-T)/5;
    }
    cout << crack;
}
