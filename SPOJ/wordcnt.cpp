#include <iostream>

using namespace std;

inline void wordcnt()
{
    string s, t="";
    int count = 0, res = 0, len = -1;
    getline(cin, s);
    s += ' ';
    for (string::iterator it=s.begin(); it != s.end(); it++)
        if (*it == ' ')
        {
            if (t.length())
            {
                if (t.length() == len)
                    count++;
                else
                    count = 1;
                len = t.length();
            }
            res = max(res, count);
            t = "";
        }
        else
            t += *it;
    cout << res << endl;
}

main()
{
    short t;
    cin >> t;
    string pass;
    getline(cin, pass);
    while (t--) wordcnt();
}
