#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>

#define x first
#define y second
#define itr(t) vector<t>::iterator
#define LOOP(n) while (n--)
#define FOR(i, a, b) for (i=(a); i <= (b); i++)
#define FORD(i, a, b) for (i=(a); i >= (b); i--)
#define IT(i, v) for (i=(v)->begin(); i != (v)->end(); i++)
#define abs(x) ((x) > 0 ? (x) : -(x))
#define input_file "input.txt"
#define output_file "output.txt"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;

inline ll gcd(ll a, ll b)
{
    return (a ? gcd(b%a, a) : b);
}

main()
{
    freopen(input_file, "r", stdin);
    //freopen(output_file, "w", stdout);
}
a[1]*b[1]+a[2]*b[2]+...+a[n]*b[n]=x
