#include <iostream>

using namespace std;

main()
{
    string name;
    getline(cin, name);
    int res = 0;
    for (string::iterator it=name.begin(); it != name.end(); it++)
        if (*it != ' ')
            res = (res+(int)(*it)-(int)'a'+1)%9;
    cout << res;
}
00000
11001
11101
11111
11111
r-l+1
