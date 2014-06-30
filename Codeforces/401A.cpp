#include <iostream>
#include <cmath>

using namespace std;

main()
{
    int n, x, card, sum = 0;
    cin >> n >> x;
    while (n--)
    {
        cin >> card;
        sum += card;
    }
    sum = abs(sum);
    if (sum%x)
        cout << sum/x+1;
    else
        cout << sum/x;
}
