#include <iostream>
#include <cstring>

using namespace std;

const int N=400+2;
const int M=400+2;

//typedef unsigned long long ull;

int i, j, n, m, COUNT=0, t_1[N][M], t_2[N][M], c_1[N][M], c_2[N][M];
char c;
bool gij, grid[N][M];

inline bool check_sumt_1(int i, int j_1, int j_2)
{
    return !(t_1[i][j_2]-t_1[i][j_1-1]);
}

inline bool check_sumt_2(int j, int i_1, int i_2)
{
    return !(t_2[i_2][j]-t_2[i_1-1][j]);
}

inline bool check_sumc_1(int i_1, int j_1, int i_2, int j_2)
{
    return !(c_1[i_2][j_2]-c_1[i_1-1][j_1-1]);
}

inline bool check_sumc_2(int i_1, int j_1, int i_2, int j_2)
{
    return !(c_2[i_2][j_2]-c_2[i_1-1][j_1+1]);
}

inline bool valid(int i, int j)
{
    return (i and i <= n and j and j <= m and !grid[i][j]);
}

inline void count_1(int i, int j)
{
    int k;
    for (k=1; valid(i+k, j-k) and valid(i+k, j+k); k++)
        COUNT += check_sumt_1(i+k, j-k, j+k);
    for (k=1; valid(i-k, j-k) and valid(i-k, j+k); k++)
        COUNT += check_sumt_1(i-k, j-k, j+k);
    for (k=1; valid(i-k, j+k) and valid(i+k, j+k); k++)
        COUNT += check_sumt_2(j+k, i-k, i+k);
    for (k=1; valid(i-k, j-k) and valid(i+k, j-k); k++)
        COUNT += check_sumt_2(j-k, i-k, i+k);
}

inline void count_2(int i, int j)
{
    int k;
    for (k=1; valid(i, j-k) and valid(i+k, j); k++)
        COUNT += check_sumc_1(i+k, j, i, j-k);
    for (k=1; valid(i-k, j) and valid(i, j+k); k++)
        COUNT += check_sumc_1(i, j+k, i-k, j);
    for (k=1; valid(i, j+k) and valid(i+k, j); k++)
        COUNT += check_sumc_2(i+k, j, i, j+k);
    for (k=1; valid(i-k, j) and valid(i, j-k); k++)
        COUNT += check_sumc_2(i, j-k, i-k, j);
}

main()
{
    memset(t_1, 0, sizeof(t_1));
    memset(t_2, 0, sizeof(t_2));
    memset(c_1, 0, sizeof(c_1));
    memset(c_2, 0, sizeof(c_2));
    cin >> n >> m;
    for (i=1; i <= n; i++)
        for (j=1; j <= m; j++)
        {
            cin >> c;
            gij=c-'0';
            grid[i][j]=gij;
            t_1[i][j]=t_1[i][j-1]+gij;
            t_2[i][j]=t_2[i-1][j]+gij;
            c_1[i][j]=c_1[i-1][j-1]+gij;
            c_2[i][j]=c_2[i-1][j+1]+gij;
        }
    for (i=1; i <= n; i++)
        for (j=1; j <= m; j++)
            if (!grid[i][j])
            {
                count_1(i, j);
                count_2(i, j);
            }
    cout << COUNT;
}
