#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int max_n = 21;

int x[max_n];
bool avail[max_n];
int n, k=0;
vector<int> res;

inline bool prime(int n)
{
    if (n <= 1) return false;
    for (int i=2; i*i <= n; i++)
        if (!(n%i)) return false;
    return true;
}

inline void gen(int i)
{
    int j;
    if (i == 2*n+1)
    {
        if (prime(x[i-1]+1))
        {
            if (++k <= 10000)
                for (j=1; j <= 2*n; j++) res.push_back(x[j]);
        }
        return ;
    }
    for (j=2; j <= 2*n; j++)
        if (avail[j] and (prime(x[i-1]+j)))
        {
            x[i] = j;
            avail[j] = false;
            gen(i+1);
            avail[j] = true;
        }
}

main()
{
    cin >> n;
    memset(avail, true, sizeof(avail));
    x[1]=1; avail[1]=false;
    gen(2);
    cout << k << endl;
    int i, j=0;
    for (i=1; i <= min(k, 10000); i++)
    {
        for (j=1; j <= 2*n; j++) cout << res[(i-1)*2*n+j-1] << " ";
        cout << endl;
    }
}
