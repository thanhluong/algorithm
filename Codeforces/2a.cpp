#include <iostream>
#include <map>
#include <cstdio>

using namespace std;

bool first=true;
int n, inc;
map<string, int> score;
map<string, bool> lost;
string name, winner;

main()
{
    cin >> n;
    while (n--)
    {
        cin >> name >> inc;
        if (first)
        {
            winner=name;
            first=false;
        }
        if (inc < 0) lost[name]=true;
        score[name]+=inc;
        if (!lost[name] and score[name] > score[winner]) winner=name;
    }
    cout << winner;
}
