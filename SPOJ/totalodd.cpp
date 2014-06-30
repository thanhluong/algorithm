#include <iostream>

using namespace std;

const int max_n = 1000000;
const int max_x = 100000000;
const int oo    = 1000000000;

int n, b[max_n];

inline void initialize()
{
    b[0] = 0; n = 0; int m, new_n, cur = 0; short i; bool stop = false;
    while (true)
    {
        m = b[cur];
        for (i=0; i < 5; i++)
        {
            new_n = m*10+2*i+1;
            if (new_n > max_x)
            {
                stop = true;
                break;
            }
            b[++n] = new_n;

        }
        if (stop) break; cur++;
    }
}

inline int find(int x)
{
    int l = 1, f = n, middle;
    while (l+1 != f)
    {
        middle = (l+f)/2;
        //cout << b[middle] << " " << l << " " << middle << " " << f << endl;
        if (b[middle]+1 < x) l = middle; else f = middle;
    }
    return f;
}

inline int process(int x)
{
    int i, j, res = oo;
    j = find(x); i = 1;
    while (i <= j && b[i] < res)
    {
        while (j > 1 && b[i]+b[j-1] >= x) j--;
        if (b[i]+b[j] < res)
        {
            res = b[i]+b[j];
            //cout << b[i] << " " << b[j] << " " << res << endl;
        }
        if (res==x) break;
        i++;
    }
    return res;
}

main()
{
    initialize();
    string tag; int x;
    do
    {
        cin >> tag;
        if (tag == "[CASE]")
        {
            cin >> x;
            cout << process(x) << endl;
        }
    } while (tag != "[END]");
}
/*
a+b >= x
a_max
a+b >= m+n >= x*/

