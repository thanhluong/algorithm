#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstring>

#define x first
#define y second

using namespace std;

const int N=300;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

vi line;
vii point;
vvi res;
int X, Y;
bool avail[N][N];

inline void update(vi v)
{
    int i, j;
    for (i=0; i < v.size(); i++)
        for (j=i-1; j >= 0; j--) avail[v[j]][v[i]]=false;
    res.push_back(v);
}

inline void process()
{
    //cout << "Number of point: " << point.size() << endl;
    int i, j, k, a, b, c;
    sort(point.begin(), point.end());
    memset(avail, true, sizeof(avail));
    for (i=0; i < point.size()-2; i++)
        for (j=i+1; j < point.size()-1; j++)
            if (avail[i][j])
            {
                a=point[j].y-point[i].y;
                b=point[i].x-point[j].x;
                c=-a*point[i].x-b*point[i].y;
                line=vi();
                line.push_back(i);
                line.push_back(j);
                for (k=j+1; k < point.size(); k++)
                    if (a*point[k].x+b*point[k].y+c==0)
                        line.push_back(k);
                if (line.size() >= 3) update(line);
            }
    if (res.size())
    {
        cout << "The following lines were found:" << endl;
        for (vvi::iterator v=res.begin(); v != res.end(); v++)
        {
            for (vi::iterator it=v->begin(); it != v->end(); it++)
                cout << "(" << setw(4) << point[*it].x << "," << setw(4) << point[*it].y << ")";
            cout << endl;
        }
    }
    else
        cout << "No lines were found" << endl;
    res=vvi();
}

main()
{
    while (true)
    {
        cin >> X >> Y;
        if (!X and !Y) break;
        point=vii();
        while (X or Y)
        {
            point.push_back(ii(X, Y));
            cin >> X >> Y;
        }
        process();
    }
}
