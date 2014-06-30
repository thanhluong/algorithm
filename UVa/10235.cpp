#include <iostream>
#include <fstream>

using namespace std;

int n, rn;

inline int rev(int n)
{
    int d, NEW=0;
    while (n)
    {
        d=n%10; n/=10;
        NEW=NEW*10+d;
    }
    return NEW;
}

inline bool prime(int n)
{
    for (int i=2; i*i <= n; i++)
        if (!(n%i)) return false;
    return (n > 1);
}

main()
{
    //cout << rev(12345);
    while (cin >> n)
    {
        /*cin >> n;
        if (cin.eof()) break;*/
        cout << n << " is ";
        if (!prime(n))
        {
            cout << "not prime" << endl;
            continue;
        }
        rn=rev(n);
        if (rn == n or !prime(rn))
        {
            cout << "prime" << endl;
            continue;
        }
        cout << "emirp" << endl;
    }
}
