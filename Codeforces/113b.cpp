#include <iostream>
#include <cstdio>
#include <cstring>

#define base 257
#define modulo 7000121

using namespace std;

const int LEN=2000;

typedef char str[LEN];

str s, s_begin, s_end;
int i, j, res=0, len_s, len_begin, len_end, min_len;
long long hash_begin, hash_end, hash_s, hash_b, hash_e, pow[LEN], h[LEN];
bool exist[modulo];

inline void init_pow()
{
    int i;
    pow[0]=1;
    for (i=1; i < LEN; i++)
    {
        pow[i]=(pow[i-1]*base)%modulo;
        if (pow[i] < 0) pow[i]+=modulo;
        //cout << "*" << i << " " << pow[i] << endl;
    }
}

inline long long HASH(str s)
{
    long long i, len=strlen(s);
    h[0]=s[0];
    for (i=1; i < len; i++)
    {
        h[i]=(h[i-1]*base+s[i])%modulo;
        //cout << i << " " << h[i] << endl;
    }
    return h[len-1];
}

inline long long hash_substr(int l, int r)
{
    long long res=(h[r]-(l ? h[l-1]*pow[r-l+1] : 0))%modulo;
    if (res < 0) res+=modulo;
    return res;
}
//1234
main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    memset(exist, false, sizeof(exist));
    init_pow();
    scanf("%s%s%s", &s, &s_begin, &s_end);
    len_s=strlen(s);
    len_begin=strlen(s_begin);
    len_end=strlen(s_end);
    min_len=max(len_begin, len_end);
    if (len_s < min_len)
    {
        printf("0");
        return 0;
    }
    hash_begin=HASH(s_begin);
    hash_end=HASH(s_end);
    HASH(s);
    //cout << min_len-1 << endl;
    //cout << hash_begin << " " << hash_end << endl;
    for (i=0; i < len_s; i++)
        for (j=i+min_len-1; j < len_s; j++)
        {
            hash_s=hash_substr(i, j);
            hash_b=hash_substr(i, i+len_begin-1);
            hash_e=hash_substr(j-len_end+1, j);
            //cout << i << " " << j << " " << hash_s << " " << hash_b << " " << hash_e << endl;
            if (hash_b==hash_begin and hash_e==hash_end)
                exist[hash_s]=true;
        }
    for (i=0; i < modulo; i++)
        res+=exist[i];
    printf("%d", res);
}
