#include <iostream>

using namespace std;

main()
{
    string inp;
    cin >> inp;
    for (string::iterator it=inp.begin(); it != inp.end(); it++)
        cout << (char)(*it-('a'-'A'));
}
