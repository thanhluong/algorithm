#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

const int N=100000;

vector<int> even, odd, P[N], Q[N];
vector<int>::iterator it;
int n, p, q, a, i;
bool EXIT;

inline void gen_even()
{
    EXIT=false;
    int i, j;
    for (i=0; i < p; i++)
    {
        if (even.empty()) break;
        P[i].push_back(even.back());
        even.pop_back();
        if (i==p-1)
        {
            while (!even.empty())
            {
                P[i].push_back(even.back());
                even.pop_back();
            }
        }
    }
    if (i == p) return ;
    for (j=i; j < p; j++)
    {
        if (odd.size() < 2)
        {
            EXIT=true;
            return ;
        }
        P[j].push_back(odd.back());
        odd.pop_back();
        P[j].push_back(odd.back());
        odd.pop_back();
    }
}

inline void gen_odd()
{
    EXIT=false;
    if (!q)
    {
        if (odd.size()%2)
        {
            EXIT=true;
            return ;
        }
        else
            while (odd.size())
            {
                P[p-1].push_back(odd.back());
                odd.pop_back();
            }
        return ;
    }
    //cout << (even.size()) << endl;
    int i;
    for (i=0; i < q-1; i++)
    {
        if (odd.empty())
        {
            EXIT=true;
            return ;
        }
        Q[i].push_back(odd.back());
        odd.pop_back();
    }
    if (odd.size()%2)
        while (!odd.empty())
        {
            Q[q-1].push_back(odd.back());
            odd.pop_back();
        }
    else
    {
        EXIT=true;
        return ;
    }
    while (even.size())
    {
        Q[q-1].push_back(even.back());
        even.pop_back();
    }
}

inline void print_vector(vector<int> vi)
{
    vector<int>::iterator it;
    cout << vi.size();
    for (it=vi.begin(); it != vi.end(); it++) cout << " " << *it;
    cout << endl;
}

main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> q >> p;
    q-=p;
    if (p+q > n)
    {
        cout << "NO";
        return 0;
    }
    for (i=1; i <= n; i++)
    {
        cin >> a;
        if (a%2)
            odd.push_back(a);
        else
            even.push_back(a);
    }
    gen_even();
    if (EXIT)
    {
        cout << "NO";
        return 0;
    }
    gen_odd();
    if (EXIT)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;
    for (i=0; i < q; i++) print_vector(Q[i]);
    for (i=0; i < p; i++) print_vector(P[i]);
}
