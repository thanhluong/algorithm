#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>

using namespace std;

ifstream fin ("lem3.txt");

const int oo = 1000000000;
const int max_n = 16+1;

int n, min_cost = oo, cost, c[max_n][max_n], min_c=oo, remain;
bool free[max_n];

inline void visit(int i)
{
    if (remain==1)
    {
        cout << min_cost << " " << cost << endl;
        min_cost = min(min_cost, cost);
        return ;
    }
    remain--;
    if (cost+remain*min_c > min_cost) return ;
    free[i] = false;
    for (int j=1; j <= n; j++)
        if (free[j])
        {
            cost += c[i][j];
            visit(j);
            cost -= c[i][j];
        }
    free[i] = true;
    remain++;
}

inline void start(int s)
{
    memset(free, true, sizeof(free));
    cost = 0; remain = n;
    visit(s);
}

main()
{
    fin >> n;
    int i, j;
    for (i=1; i <= n; i++)
        for (j=1; j <= n; j++)
        {
            fin >> c[i][j];
            if (i != j) min_c = min(min_c, c[i][j]);
        }
    for (i=1; i <= n; i++) start(i);
    cout << min_cost;
}
