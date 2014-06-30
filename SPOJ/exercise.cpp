#include <iostream>
#include <cstring>

using namespace std;

const int max_n = 20+1;
bool avail[max_n][max_n];

int n, count, vertex;

inline bool valid(int i, int j)
{
    return (i && i <= n && j && j <= n);
}

inline void dfs(int i, int j)
{
    vertex++;
    avail[i][j] = false;
    if (i==n && j==1 && vertex==n*n) count++;
    int ii, jj;
    for (ii=-1; ii <= 1; ii++)
        for (jj=-1; jj <= 1; jj++)
            if ((ii+jj==1 or ii+jj==-1) && valid(i+ii, j+jj) && avail[i+ii][j+jj])
            {
                dfs(i+ii, j+jj);
            }
    avail[i][j] = true; vertex--;
}

main()
{
    cin >> n;
    count = 0;
    vertex = 0;
    memset(avail, true, sizeof(avail));
    dfs(1, 1);
    cout << count;
}
