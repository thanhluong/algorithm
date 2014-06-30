#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

const int N=1000000+1;

string s;
stack<int> si;
int i, j, a[N], l[N];

main()
{
    cin >> s;
    memset(a, 0, sizeof(a));
    memset(l, 0, sizeof(l));
    for (i=0; i < s.length(); i++)
        if (s[i]=='(')
            si.push(i);
        else if (si.size())
        {
            j=si.top();
            l[i]=(j ? l[j-1] : 0)+i-j+1;
            a[l[i]]++;
            si.pop();
        }
    for (i=N-1; i >= 1; i--)
        if (a[i])
        {
            cout << i << " " << a[i];
            return 0;
        }
    cout << "0 1";
}
