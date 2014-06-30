#include <iostream>

using namespace std;

main()
{
    int n, m, n_r, m_r, n_110;
    cin >> n >> m;
    for (n_110=0; n_110 <= n; n_110++)
    {
        n_r = n-n_110; m_r = m-2*n_110;
        if (m_r < 0) break;
        if (m_r >= n_r and m_r-n_r <= 2)
        {
            while (n_110--) cout << 110;
            while (n_r--)
            {
                cout << 10;
                m_r--;
            }
            while (m_r--) cout << 1;
            return 0;
        }
        if (n_r == m_r+1)
        {
            cout << 0; n_r--;
            while (n_110--) cout << 110;
            while (n_r--) cout << 10;
            return 0;
        }
    }
    cout << -1;
}
