#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N=50;

int test, n;
char a[N][N];
string res[N][N];

inline int optimize()
{
    int i, j, I, J; bool exist;
    string candidate;
    for (i=n-2; i >= 0; i--)
        for (j=i+1; j <= n; j++)
        {
            exist=false;
            for (I=i+1; I < j; I++)
                for (J=I; J < j; J++)
                    if (a[i][I]==a[J][j])
                    {
                        exist=true;
                        candidate=a[i][I]+res[I][J]+a[J][j];
                        if (candidate.length() > res[i][j].length() or (candidate.length()==res[i][j].length() and candidate < res[i][j]))
                            res[i][j]=candidate;
                    }
            if (!exist) res[i][j]=a[i][j];
        }
}

inline void load_data()
{
    int i, j;
    cin >> n;
    for (i=0; i < n; i++)
        for (j=0; j < n; j++)
        {
            res[i][j]="";
            cin >> a[i][j];
        }
}

main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> test;
    while (test--)
    {
        load_data();
        //cout << get_f(1, 3);
        //cout << f[1][3];
        optimize();
        cout << res[0][n-1] << endl;
    }
}
