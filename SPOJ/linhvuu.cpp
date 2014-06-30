#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

const int oo = 1 << 30;
const int max_n = 100;

int n, f[max_n][max_n];
char open['}'+1];
string s;

inline void init()
{
    memset(f, -1, sizeof(f));
    n = s.length();
    open[')'] = '(';
    open[']'] = '[';
    open['}'] = '{';
}

inline bool is_open(char hook)
{
    return (hook=='(' or hook == '[' or hook=='{');
}

inline int get_f(int i, int j)
{
    if (i > j) return 0;
    if (f[i][j]+1) return f[i][j];
    char rear = s[j];
    if (is_open(rear)) return get_f(i, j-1)+1;
    f[i][j] = oo;
    for (int k=i; k <= j; k++)
        if (open[rear]==s[k])
            f[i][j] = min(f[i][j], get_f(i, k-1));
        else
            f[i][j] = min(f[i][j], get_f(i, k-1)+get_f(k, j-1)+1);
    return f[i][j];
}

main()
{
    cin >> s;
    init();
    cout << get_f(0, n-1);
}
