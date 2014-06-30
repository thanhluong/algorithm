#include <iostream>

using namespace std;

typedef unsigned long long ull;

ull a, b, m;

inline ull fast_multi(ull a, ull b)
{
    if (!b) return 0;
    if (!(b-1)) return a;
    if (b%2)
        return (fast_multi(a, b/2)*2+a)%m;
    else
        return (fast_multi(a, b/2)*2)%m;
}

struct matrix
{
    ull x_1, y_1, x_2, y_2;
    matrix(ull a, ull b, ull c, ull d)
    {
        x_1 = a; y_1 = b;
        x_2 = c; y_2 = d;
    }
};

inline matrix multi(matrix a, matrix b)
{
    ull x_1 = fast_multi(a.x_1, b.x_1)+fast_multi(a.y_1, b.x_2);
    ull y_1 = fast_multi(a.x_1, b.y_1)+fast_multi(a.y_1, b.y_2);
    ull x_2 = fast_multi(a.x_2, b.x_1)+fast_multi(a.y_2, b.x_2);
    ull y_2 = fast_multi(a.x_2, b.y_1)+fast_multi(a.y_2, b.y_2);
    return matrix(x_1%m, y_1%m, x_2%m, y_2%m);
}

inline matrix pow(long long n)
{
    if (n==1)
        return matrix(a%m, 0, b%m, 1%m);
    matrix square_root = pow(n/2);
    if (n%2)
        return multi(multi(square_root, square_root), pow(1));
    else
        return multi(square_root, square_root);
}

inline void one4ever()
{
    ull k, x;
    cin >> a >> b >> m >> k;
    x = b%m;
    if (k==1)
        cout << x;
    else
    {
        matrix mat = pow(k-1);
        cout << (x*mat.x_1+mat.x_2)%m;
    }
    cout << endl;
}

main()
{
    short t;
    cin >> t;
    while (t--) one4ever();
}
