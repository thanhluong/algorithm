#include <iostream>
#include <vector>

using namespace std;

main()
{
    char c, cc, chr, dot;
    string choice['E'];
    vector<char> vc;
    bool shorter, longer;
    for (c='A'; c <= 'D'; c++) cin >> chr >> dot >> choice[c];
    for (c='A'; c <= 'D'; c++)
    {
        shorter=true;
        for (cc='A'; cc <= 'D'; cc++)
            if (c != cc and choice[cc].length()/choice[c].length() < 2)
                shorter=false;
        longer=true;
        for (cc='A'; cc <= 'D'; cc++)
            if (c != cc and choice[c].length()/choice[cc].length() < 2)
                longer=false;
        if (shorter or longer) vc.push_back(c);
    }
    cout << (vc.size()==1 ? vc[0] : 'C');
}
