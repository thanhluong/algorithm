#include <iostream>
#include <cmath>

using namespace std;

const int max_n = 1000+1;

typedef unsigned long long ull;

ull x[max_n], y[max_n];

inline ull sqr(ull n)
{
    return n*n;
}

inline double dist(int i, int j)
{
    return sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]));
}

main()
{
    int n, i, A, B, C, count = 0;
    cin >> n;
    for (i=1; i <= n; i++) cin >> x[i] >> y[i];
    for (A=1; A <= n; A++)
        for (B=1; B < n; B++)
            for (C=B+1; C <= n; C++)
                if (dist(A, B)==dist(A, C) and dist(A, B) != dist(B, C)) count++;
    cout << count;
}
