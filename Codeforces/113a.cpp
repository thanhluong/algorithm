#include <iostream>
#include <cstdio>

using namespace std;

const int N=100000+1;

int n=0, i, gender;
string s[N], ans[]={"NO", "YES"};

inline bool is_adj(int l, int r, bool masculine)
{
    if (l > r) return true;
    int i, len;
    for (i=l; i <= r; i++)
    {
        len=s[i].length();
        if (masculine and len >= 4 and s[i].substr(len-4, 4)=="lios") continue;
        if (!masculine and len >= 5 and s[i].substr(len-5, 5)=="liala") continue;
        return false;
    }
    return true;
}

inline int check_noun(int i)
{
    int len=s[i].length();
    if (len >= 3 and s[i].substr(len-3, 3)=="etr") return 1;
    if (len >= 4 and s[i].substr(len-4, 4)=="etra") return 0;
    return -1;
}

inline bool is_verb(int l, int r, bool masculine)
{
    if (l > r) return true;
    int i, len;
    for (i=l; i <= r; i++)
    {
        len=s[i].length();
        if (masculine and len >= 6 and s[i].substr(len-6, 6)=="initis") continue;
        if (!masculine and len >= 6 and s[i].substr(len-6, 6)=="inites") continue;
        return false;
    }
    return true;
}

main()
{
    //freopen("input.txt", "r", stdin);
    while (true)
    {
        cin >> s[++n];
        if (!s[n].length())
        {
            n--;
            break;
        }
    }
    if (n==1)
    {
        cout << ans[is_adj(1, 1, 0) or is_adj(1, 1, 1) or check_noun(1)+1 or is_verb(1, 1, 0) or is_verb(1, 1, 1)];
        return 0;
    }
    for (i=1; i <= n; i++)
    {
        gender=check_noun(i);
        if (gender != -1)
        {
            cout << ans[is_adj(1, i-1, gender) and is_verb(i+1, n, gender)];
            return 0;
        }
    }
    cout << "NO";
}
