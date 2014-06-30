#include <iostream>
#include <cstring>

using namespace std;

main()
{
    int i, j, k, s_1, s_2, s_3, appear[82];
    cin >> s_1 >> s_2 >> s_3;
    memset(appear, 0, sizeof(appear));
    for (i=1; i <= s_1; i++)
        for (j=1; j <= s_2; j++)
            for (k=1; k <= s_3; k++)
                appear[i+j+k]++;
    j = 3;
    for (i=3; i <= 81; i++)
        if (appear[i] > appear[j]) j = i;
    cout << j;
}
