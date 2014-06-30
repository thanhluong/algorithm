#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

int n, k;
string a = "";

inline string str(int n)
{
    ostringstream tmp;
    tmp << n;
    return tmp.str();
}

inline bool prime(int n)
{
    for (int i=2; i*i <= n; i++)
        if (!(n%i))
            return false;
    return true;
}

inline void assembly()
{
    int p = 1, count = 0;
    while (count < n)
    {
        p++;
        if (prime(p))
        {
            count++;
            a += str(p);
        }
    }
}

inline int choose(int i, int j)
{
    return (a[i] > a[j] ? i : j);
}

main()
{
    cin >> n;
    assembly();
    cin >> k;
    int i, j, len = a.length(), m = a.length()-k, count = 0, l = 0;
    int c[len][30];
    for (i=0; i < len; i++)
        c[i][0] = i;
    for (j=1; (1<<j) < len; j++)
        for (i=0; i+(1<<j)-1 < len; i++)
            c[i][j] = choose(c[i][j-1], c[i+(1<<(j-1))][j-1]);
    while (count < m)
    {
        j = log2(len-m+count-l+1);
        i = choose(c[l][j], c[len-m+count-(1<<j)+1][j]);
        count++;
        for (j=l; j <= len-m+count; j++)
            if (a[j]==a[i])
            {
                cout << a[j];
                l = j+1;
                break;
            }
    }
}
