#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

const int N=100000+1;
const int one[]={0, 1, 11, 111, 1111, 11111, 111111};

int n, counted[2*N];

//11111-1111
//11
//111
//111-1
10*1=11-1
111-11
f[1]=1;
f[10]=3;
f[100]=5;
f[1000]=7
121=100+20+1=20
inline int COUNT(int n)
{
    counted[n]=true;
    printf("%d\n", n);
    int i=0, res;
    while (one[i] < n) i++;
    if (one[i]==n) return i;
    if (!counted[one[i]-n])
        return (i-1+COUNT(n-one[i-1]), i+COUNT(one[i]-n));
    else
        return i-1+COUNT(n-one[i-1]);
    /*printf("%d\n", res);
    return res;*/
}

main()
{
    memset(counted, false, sizeof(counted));
    scanf("%d", &n);
    printf("%d", COUNT(n));
}
