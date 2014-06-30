#include <iostream>
#include <cstring>

using namespace std;

const int max_n = 20+1;

int n;
long long f[max_n][max_n][max_n*max_n];

inline bool valid(int i, int j)
{
    return (i && i <= n && j && j <= n);
}

inline long long get_f(int i, int j, int k)
{
    if (k <= 0) return 0;
    if (i==1 && j==1)
    {
        if (k==1) return 1; else return 0;
    }
    if (f[i][j][k]+1) return f[i][j][k];
    int ii, jj;
    f[i][j][k] = 0;
    for (ii=-1; ii <= 1; ii++)
        for (jj=-1; jj <= 1; jj++)
            if ((ii+jj==-1 or ii+jj==1) && valid(i+ii, j+jj))
                f[i][j][k] += get_f(i+ii, j+jj, k-1);
    return (f[i][j][k]);
}

main()
{
    cin >> n;
    memset(f, -1, sizeof(f));
    cout << get_f(n, 1, n*n);
}
