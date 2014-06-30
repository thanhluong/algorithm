#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

typedef vector<int> vi;

const int LIMIT=100000;

int sum, limit, LOW, i;
vi low[LIMIT], res;

inline int lowbit(int n)
{
    return ((n^(n-1))+1)>>1;
}

main()
{
    scanf("%d%d", &sum, &limit);
    for (i=limit; i >= 1; i--)
        low[lowbit(i)].push_back(i);
    while (sum)
    {
        LOW=lowbit(sum);
        i=LOW;
        sum-=LOW;
        while (i)
        {
            while (low[i].size())
            {
                res.push_back(low[i].back());
                low[i].pop_back();
                LOW-=i;
                if (!LOW) break;
            }
            if (!LOW) break;
            i>>=1;
        }
        if (LOW)
        {
            printf("-1");
            return 0;
        }
    }
    printf("%d\n", res.size());
    for (vi::iterator it=res.begin(); it != res.end(); it++)
        printf("%d ", *it);
}
