#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

const int N=100000+1;

typedef pair<int, int> ii;

vector<int> Ox[N], Oy[N];
map<ii, bool> exist;
int n, i, j, x, y, xx, yy, h, w, id, b[N], res=0;

main()
{
    cin >> n;
    for (i=1; i <= n; i++)
    {
        cin >> x >> y;
        Oy[x].push_back(y);
        Ox[y].push_back(x);
        exist[ii(x, y)]=true;
    }
    for (x=0; x < N; x++) sort(Oy[x].begin(), Oy[x].end());
    for (y=0; y < N; y++) sort(Ox[y].begin(), Ox[y].end());
    memset(b, 0, sizeof(b));
    for (x=0; x < N; x++)
        for (id=0; id < Oy[x].size(); id++)
        {
            y=Oy[x][id];
            if (Ox[y][b[y]] < x) b[y]++;
            i=id+1; j=b[y]+1;
            while (i < Oy[x].size() and j < Ox[y].size())
            {
                xx=Ox[y][j]; yy=Oy[x][i];
                h=yy-y;
                w=xx-Ox[y][b[y]];
                if (h==w)
                {
                    //cout << Ox[y][b[y]] << " " << y << " " << xx << " " << yy <<endl;
                    res += exist[ii(Ox[y][j], Oy[x][i])];
                    i++; j++;
                }
                else if (h < w)
                    i++;
                else
                    j++;
            }
        }
    cout << res;
}
