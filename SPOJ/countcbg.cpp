#include <iostream>

using namespace std;

inline int countcbg(int n)
{
    int j, res = 0;
    for (j=2; j*j <= 2*n; j++)
        if ((n*2)%j==0 and ((n*2)/j-j+1)%2==0 and ((n*2)/j-j+1)/2 > 0) res++;
    return res;
}

main()
{
    int n;
    while (true)
    {
        cin >> n;
        if (cin.eof()) break;
        cout << countcbg(n) << endl;
    }
}
