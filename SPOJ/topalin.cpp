#include <iostream>
#include <cstring>

using namespace std;

char par['z'+1];

inline char find_set(char u)
{
    if (par[u]==u)
        return u;
    else
        return (par[u] = find_set(par[u]));
}

inline void join(char u, char v)
{
    par[find_set(u)] = find_set(v);
}

main()
{
    int i, j, d['z'+1], sum['z'+1], max['z'+1], res = 0;
    char u, v;
    memset(d, 0, sizeof(d));
    string::iterator chr;
    string inp;
    cin >> inp;
    for (chr=inp.begin(); chr != inp.end(); chr++)
        d[*chr]++;
    for (u='0'; u <= 'z'; u++)
    {
        par[u]=u;
        sum[u]=0; max[u] = 0;
    }
    i = 0; j = inp.size()-1;
    while (i < j)
    {
        join(inp[i], inp[j]);
        i++; j--;
    }
    for (u='0'; u <= 'z'; u++)
    {
        v = par[u];
        sum[v] += d[u];
        if (max[v] < d[u])
            max[v] = d[u];
    }
    for (u='0'; u <= 'z'; u++)
        res += sum[u]-max[u];
    cout << res;
}
