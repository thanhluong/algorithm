#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int N=5000+1;

struct T_envolope
{
    int id, w, h;
} card, envolope[N];

int n, i, j, l[N], trace[N];
vector<int> res;

inline bool bigger(T_envolope a, T_envolope b)
{
    return (a.w > b.w and a.h > b.h);
}

inline void find_lis()
{
    int i;
    memset(l, 1, sizeof(l));
    memset(trace, 0, sizeof(trace));
    for (i=n-1; i >= 1; i--)
        for (j=i+1; j <= n; j++)
            if (bigger(envolope[j], envolope[i]) and l[j]+1 > l[i])
            {
                l[i]=l[j]+1;
                trace[i]=j;
            }
}

inline void trace_back(int i)
{
    while (true)
    {
        if (!i) break;
        res.push_back(envolope[i].id);
        i=trace[i];
    }
}

inline bool comp(T_envolope a, T_envolope b)
{
    if (a.w==b.w)
        return (a.h < b.h);
    else
        return (a.w < b.w);
}

main()
{
    cin >> n >> card.w >> card.h;
    for (i=1; i <= n; i++)
    {
        cin >> envolope[i].w >> envolope[i].h;
        envolope[i].id=i;
    }
    sort(envolope+1, envolope+n+1, comp);
    find_lis();
    l[0]=0; j=0;
    for (i=1; i <= n; i++)
        if (bigger(envolope[i], card) and l[i] > l[j]) j=i;
    trace_back(j);
    cout << res.size() << endl;
    for (vector<int>::iterator it=res.begin(); it != res.end(); it++)
        cout << *it << endl;
}
