#include <iostream>
#include <vector>
#include <algorithm>

#define x first
#define y second

using namespace std;

typedef pair<int, int> ii;

inline int calc_min(int s, int f)
{
    if (s > f) return 0;
    int delta = f-s+1;
    if (delta%2)
        return (delta/2+1);
    return (delta/2);
}

inline int calc_max(int s, int f)
{
    if (s > f) return 0;
    return f-s+1;
}

main()
{
    int x, k, type, num_1, num_2;
    cin >> x >> k;
    vector<ii> rounds;
    rounds.push_back(ii(x, 0));
    while (k--)
    {
        cin >> type;
        if (type==1)
        {
            cin >> num_1 >> num_2;
            rounds.push_back(ii(num_1, num_2));
        }
        else
        {
            cin >> num_2;
            rounds.push_back(ii(num_2, num_2));
        }
    }
    rounds.push_back(ii(0, 0));
    sort(rounds.begin(), rounds.end());
    int res_max = 0, res_min = 0;
    for (int i=0; i+1 < rounds.size(); i++)
    {
        res_max += calc_max(rounds[i].y+1, rounds[i+1].x-1);
        res_min += calc_min(rounds[i].y+1, rounds[i+1].x-1);
    }
    cout << res_min << " " << res_max;
}
