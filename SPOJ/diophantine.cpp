#include <iostream>

#define X first
#define Y second

using namespace std;

typedef long long l;
typedef

inline l gcd(l a, l b)
{
    return (a ? gcd(b%a, a) : b);
}

main()
{
    cout << gcd(140, 42);
}
