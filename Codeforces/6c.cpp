#include <iostream>

using namespace std;

const int N=100000+1;

int n, i, j, a, b, t[N];

main()
{
    cin >> n;
    for (i=1; i <= n; i++) cin >> t[i];
    i=1; j=n;
    while (i+1 < j)
        if (t[i] < t[j])
            t[j] -= t[i++];
        else if (t[i] > t[j])
            t[i] -= t[j--];
        else
        {
            i++; j--;
        }
    if (i==j) j++;
    cout << i << " " << n-j+1;
}
