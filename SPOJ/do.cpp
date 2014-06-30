#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n, a, s, i, l, COUNT[8];
long long res=0;

main()
{
    char input[4000000];
    scanf("%s", &input);
    l=strlen(input);
    for (i=0; i < l; i++)
    {
        a=input[i]-'0';
        s=(s+a)%8;
        res+=COUNT[s];
        if (a) COUNT[s]++; else res++;
    }
    printf("%d", res);
}
