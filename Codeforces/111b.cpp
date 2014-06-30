#include <iostream>
#include <map>
#include <cstdio>

using namespace std;

const int N=100000;
const int DIVISOR=317;

int n, i, j, x, y, COUNT=0, div;
map<int, int> d[N];

main()
{
    scanf("%d", &n);
    for (i=1; i <= n; i++)
    {
        scanf("%d%d", &x, &y);
        COUNT=0; div=0;
        for (j=1; j <= DIVISOR; j++)
        {
            d[i][j]=d[i-1][j];
            if (x%j==0)
            {
                div++;
                //cout << "*" << endl;
                if (d[i-1][j] != d[i-y-1][j])
                    cout << j << " " << d[i-1][j] << " " << d[i-y-1][j] << endl;
                COUNT+=(d[i-1][j]==d[i-y-1][j]);
                d[i][j]++;
            }
        }
        if (x > DIVISOR)
        {
            COUNT+=(d[i-1][x]==d[i-y-1][x]);
            d[i][x]=d[i-1][x]+1;
        }
        printf("%d %d\n", COUNT, div);
    }
}
