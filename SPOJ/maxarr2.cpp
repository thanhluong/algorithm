#include <iostream>

using namespace std;

const int pre[] = {0, 1, 1};

main()
{
    short t; long long i, n, res;
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (n <= 2)
            cout << pre[n] << endl;
        else
        {
            i = 3; res = 1;
            while (2*(i-1)+1 <= n)
            {
                i = 2*(i-1)+1;
                res = res+i;
            }
            cout << res;
        }
    }
}
2(i-1)
