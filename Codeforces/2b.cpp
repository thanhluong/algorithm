#include <iostream>
#include <vector>

#define x first
#define y second

using namespace std;

const int N=1000+1;
const int oo=1000000000;

typedef pair<int, int> ii;
typedef int T_f[N][N];
typedef ii T_trace[N][N];

int n, mat[N][N];
T_f f_2, f_5;
T_trace trace_2, trace_5;
vector<char> res;

inline int get_val(int n)
{
    return (n+1 ? n : 1);
}

inline void load_data()
{
    int i, j;
    cin >> n;
    for (i=1; i <= n; i++)
        for (j=1; j <= n; j++) cin >> mat[i][j];
}

inline void optimize(T_f &f, T_trace &trace, int p)
{
    int i, j, deg;
    for (i=1; i <= n; i++)  f[i][0]=(f[0][i]=oo);
    for (i=1; i <= n; i++)
        for (j=1; j <= n; j++)
            if (!mat[i][j])
            {
                f[i][j]=-1;
                trace[i][j]=ii(i-1, j);
            }
            else
            {
                deg=0;
                while (!(mat[i][j]%p))
                {
                    mat[i][j] /= p;
                    deg++;
                }
                if (i==1 and j==1)
                {
                    f[i][j]=deg;
                    continue;
                }
                if (get_val(f[i-1][j]) < get_val(f[i][j-1]))
                {
                    f[i][j]=(f[i-1][j]+1 ? f[i-1][j]+deg : -1);
                    trace[i][j]=ii(i-1, j);
                }
                else
                {
                    f[i][j]=(f[i][j-1]+1 ? f[i][j-1]+deg : -1);
                    trace[i][j]=ii(i, j-1);
                }
            }
}

inline void trace_back(T_trace &trace)
{
    ii cell; int i=n, j=n;
    while (true)
    {
        cell=trace[i][j];
        res.push_back(i > cell.x ? 'D' : 'R');
        i=cell.x; j=cell.y;
        if (i==1 and j==1) break;
    }
    for (vector<char>::reverse_iterator it=res.rbegin(); it != res.rend(); it++)
        cout << *it;
}

main()
{
    load_data();
    optimize(f_2, trace_2, 2);
    optimize(f_5, trace_5, 5);
    if (get_val(f_2[n][n]) < get_val(f_5[n][n]))
    {
        cout << get_val(f_2[n][n]) << endl;
        trace_back(trace_2);
    }
    else
    {
        cout << get_val(f_5[n][n]) << endl;
        trace_back(trace_5);
    }
}
