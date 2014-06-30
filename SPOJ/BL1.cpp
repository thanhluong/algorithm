#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

ifstream fin ("digitsum.inp");
ofstream fout ("digitsum.out");

const int max_n = 20+1;
const int max_k = 30+1;
const char digit[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

long long f[max_n][max_k];

inline long long get_f(int i, int j)
{
    if (i <= 0 or j < 0) return 0;
    if (i==1 && j < 10) return 1;
    if (f[i][j]+1) return f[i][j];
    f[i][j] = 0;
    for (short k=0; k <= 9; k++)
        f[i][j] += get_f(i-1, j-k);
    return f[i][j];
}

main()
{
    memset(f, -1, sizeof(f));
    int i, j, n, k, p, sum;
    fin >> n >> k >> p;
    int tmp = k, tmp2 = 0;
    fout << get_f(n, k) << endl;
    bool first = true;
    for (i=n; i > 1; i--)
    {
        j = 0; sum = get_f(i-1, k);
        cout << i << " " << sum << " " << p << endl;
        while (j < 9 && sum < p)
        {
            sum += get_f(i-1, k-j);
            j++;
        }
        cout << j << endl;
        k -= j;
        if (j==0 && first) continue;
        first = false;
        fout << j; tmp2 += j;
    }
    fout << tmp-tmp2;
    fin.close(); fout.close();
}
