#include <iostream>
#include <cstdio>

using namespace std;

const int oo=1000000;

int n, n_4=0, n_7, c_4=oo, c_7=oo;

main()
{
    scanf("%d", &n);
    while (true)
    {
        if (4*n_4 > n) break;
        if (!((n-4*n_4)%7))
        {
            n_7=(n-4*n_4)/7;
            if (n_4+n_7 < c_4+c_7)
            {
                c_4=n_4;
                c_7=n_7;
            }
        }
        n_4++;
    }
    if (c_7==oo)
    {
        printf("-1");
        return 0;
    }
    while (c_4--)
        printf("4");
    while (c_7--)
        printf("7");
}
