#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long n, x, res=0, c;
vector<int> C;

main()
{
    cin >> n >> x;
    while (n--)
    {
        cin >> c;
        C.push_back(c);
    }
    sort(C.begin(), C.end());
    for (vector<int>::iterator it=C.begin(); it!=C.end(); it++)
    {
        res += x*(*it);
        if (x > 1) x--;
    }
    cout << res;
}
