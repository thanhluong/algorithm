#include <iostream>

using namespace std;

typedef long long ll;

const ll k=256;
const ll l=1000000;
const ll m=1000000000+7;

string a, b;
ll h[l], e[l], len_a, len_b, hash_b;

inline void init_e()
{
    e[0]=1;
    for (int i=1; i < l; i++) e[i]=(e[i-1]*k)%m;
}

inline ll enpositive(ll n)
{
    while (n < 0) n += m;
    return n;
}

inline ll HASH(string str)
{
    int i, len=str.length();
    h[0]=str[0];
    for (int i=1; i < len; i++)
    {
        h[i]=(h[i-1]*k+str[i])%m;
        //cout << i << " " << h[i] << endl;
    }
    return h[len-1];
}

inline ll HASH(int l, int r)
{
    return enpositive((h[r]-(l ? h[l-1]*e[r-l+1] : 0))%m);
}

main()
{
    cin >> a >> b;
    len_a=a.length(); len_b=b.length();
    init_e();
    hash_b=HASH(b);
    HASH(a);
    for (int i=0; i+len_b-1 < len_a; i++)
    {
        //cout << i << " " << HASH(i, i+len_b-1) << endl;
        if (HASH(i, i+len_b-1)==hash_b)
            cout << i+1 << " ";
    }
}
