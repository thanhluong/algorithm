#include <iostream>

using namespace std;

const long long mod = 111539786;

struct matrix
{
    long long x_1, y_1, x_2, y_2;
    matrix(long long a, long long b, long long c, long long d)
    {
        x_1 = a; y_1 = b;
        x_2 = c; y_2 = d;
    }
};

inline matrix multi(matrix a, matrix b)
{
    long long x_1 = a.x_1*b.x_1+a.y_1*b.x_2;
    long long y_1 = a.x_1*b.y_1+a.y_1*b.y_2;
    long long x_2 = a.x_2*b.x_1+a.y_2*b.x_2;
    long long y_2 = a.x_2*b.y_1+a.y_2*b.y_2;
    return matrix(x_1%mod, y_1%mod, x_2%mod, y_2%mod);
}

inline matrix get_mat(long long n)
{
    if (n==1)
        return matrix(0, 1, 1, 1);
    matrix square_root = get_mat(n/2);
    if (n%2)
        return multi(square_root, multi(square_root, get_mat(1)));
    else
        return multi(square_root, square_root);
}

inline void latgach4()
{
    long long n;
    cin >> n;
    cout << get_mat(n).y_2 << endl;
}

main()
{
    short t;
    cin >> t;
    while (t--) latgach4();
}
