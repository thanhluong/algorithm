#include <iostream>
#include <cstring>

using namespace std;

const char C=max('X', '0')+1;

main()
{
    int i, j, count[C], diagonal_1[4][4][C], diagonal_2[4][4][C], row[4][4][C], column[4][4][C];
    char cell;
    memset(diagonal_1, 0, sizeof(diagonal_1));
    memset(diagonal_2, 0, sizeof(diagonal_2));
    memset(column, 0, sizeof(column));
    memset(row, 0, sizeof(row));
    count['X']=count['0']=0;
    for (i=1; i <= 3; i++)
        for (j=1; j <= 3; j++)
        {
            cin >> cell;
            if (cell != '.')
            {
                count[cell]++;
                diagonal_1[i][j][cell]=diagonal_1[i-1][j-1][cell]+1;
                diagonal_2[i][j][cell]=diagonal_2[i-1][j+1][cell]+1;
                column[i][j][cell]=column[i-1][j][cell]+1;
                row[i][j][cell]=row[i][j-1][cell]+1;
            }
        }
    if (count['0'] > count['X'] or count['X']-count['0'] >= 2)
    {
        cout << "illegal";
        return 0;
    }
    for (i=1; i <= 3; i++)
        for (j=1; j <= 3; j++)
        {
            if (diagonal_1[i][j]['X']==3 or diagonal_2[i][j]['X']==3 or column[i][j]['X']==3 or row[i][j]['X']==3)
            {
                cout << (count['X']==count['0']+1 ? "the first player won" : "illegal");
                return 0;
            }
            if (diagonal_1[i][j]['0']==3 or diagonal_2[i][j]['0']==3 or column[i][j]['0']==3 or row[i][j]['0']==3)
            {
                cout << (count['X']==count['0'] ? "the second player won" : "illegal");
                return 0;
            }
    }
    if (count['X']+count['0']==9)
    {
        cout << "draw";
        return 0;
    }
    if (count['X']==count['0'])
        cout << "first";
    else
        cout << "second";
}
