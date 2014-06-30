#include <iostream>
#include <vector>

using namespace std;

const long long pow[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};

long long a, b, n_digit;
vector<int> res[9];

main()
{
    for (a=0; a <= 9999; a++)
        for (b=0; b <= 9999; b++)
            for (n_digit=0; n_digit <= 8; n_digit += 2)
                if (a < pow[n_digit/2] and b < pow[n_digit/2] and (a+b)*(a+b)==a*pow[n_digit-1]+b)
                    res[n_digit].push_back((a+b)*(a+b));
    for (vector<int>::iterator it=res[4].begin(); it != res[4].end(); it++)
        cout << *it << endl;
}
