#include <iostream>
#define lim 102

using namespace std;

inline bool prime(int n)
{
    for (int i=2; i*i <= n; i++)
        if (!(n%i)) return false;
    return true;
}

main()
{
    for (int i=lim; true; i++)
        if (prime(i))
        {
            cout << i;
            break;
        }
}
