#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef unsigned long long ull;
typedef vector<ull> vull;

const ull max_pow = 18+1;

ull m, pow_3[max_pow], d[max_pow];
vull l, r;

inline void init()
{
    memset(d, 0, sizeof(d));
    pow_3[0]=1;
    for (ull i=1; i < max_pow; i++)
        pow_3[i] = pow_3[i-1]*3;
}

inline void factor(ull x)
{
    d[0]=x;
    int i = 0;
    while (true)
    {
        if (pow_3[++i] > x) break;
        d[i]=d[i-1]/3;
        d[i-1]=d[i-1]%3;
    }
}

inline void lascale()
{
    factor(m);
    for (int i=0; i < max_pow; i++)
    {
        if (d[i] >= 2)
        {
            if (d[i]==2) l.push_back(i);
            d[i]=0;
            d[i+1]++;
        }
        if (d[i]) r.push_back(i);
    }
}

inline void print_vector(vull v)
{
    cout << v.size();
    for (vull::iterator it=v.begin(); it != v.end(); it++) cout << " " << *it;
    cout << endl;
}

main()
{
    init();
    cin >> m;
    lascale();
    print_vector(l);
    print_vector(r);
}
