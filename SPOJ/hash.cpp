#include <stdio.h>
#include <string.h>

const int SMALL = 29;
const int BIG = 1000012309;

struct modulo {
    long long x;
    long long base;
    void ensure(){ x=x%base; while (x<0) x+=base; }
    modulo(long long X){ base=BIG; x=X; ensure(); }
    modulo(){ base=BIG; }
    modulo operator + (modulo a){ return modulo(x+a.x); }
    modulo operator - (modulo a){ return modulo(x-a.x); }
    modulo operator * (modulo a){ return modulo(x*a.x); }
    bool operator ==(modulo a){ return x==a.x; }
};

char a[1230997];
modulo H[1230997];
modulo pow_small[1230997];
int n;

modulo hash(char a[]){ // one-based
    int i;
    n = strlen(a+1);
    pow_small[0]=1;
    for (i=1; i<=n; i++)
    pow_small[i]=pow_small[i-1]*SMALL;
    for (i=1; i<=n; i++)
    H[i]=H[i-1]*SMALL+(a[i]%(SMALL-1)+1);
    return H[n];
}

modulo hash(int ll, int rr){
    return H[rr]-H[ll-1]*pow_small[rr-(ll-1)];
}

char sub[1230997];
char str[1230997];

main(){
    int i, l;
    scanf("%s%s", str+1, sub+1);
    modulo sub_hash = hash(sub);
    l = strlen(sub+1);
    hash(str);

    int j=0;
    for (i=1; i+l-1<=n; i++)
    if (hash(i, i+l-1) == sub_hash)
    printf(j++?" %d":"%d", i);
    printf("\n");
}
