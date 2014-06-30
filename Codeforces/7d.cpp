#include <iostream>
#include <cstring>

using namespace std;

typedef unsigned long long ull;

const ull m=257;
const ull N=10000000;

string s;
ull hash_l=0, hash_r=0, e=1, i, deg[N], sum=0;

main()
{
    memset(deg, 0, sizeof(deg));
    cin >> s;
    for (i=0; i < s.length(); i++)
    {
        hash_l=hash_l*m+s[i];
        hash_r=s[i]*e+hash_r;
        e *= m;
        sum += (hash_l==hash_r ? (deg[i+1]=deg[(i+1)/2]+1) : 0);
    }
    cout << sum;
}
