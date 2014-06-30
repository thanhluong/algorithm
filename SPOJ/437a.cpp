#include <iostream>
#include <vector>

using namespace std;

main()
{
    char c, cc, chr, dot;
    string choice['E'];
    vector<char> vc;
    bool great;
    for (c='A'; c <= 'D'; c++) cin >> chr >> dot >> choice[c];
    for (c='A'; c <= 'D'; c++)
    {
        great=true;
        for (cc='A'; cc <= 'D'; cc++)
            if (c != cc and choice[c].length()*2 > choice[cc].length() and choice[cc].length()*2 > choice[c].length())
                great=false;
        if (great) vc.push_back(c);
    }
    cout << (vc.size()==1 ? vc[0] : 'C');
}
