#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

struct T_node
{
    int id, a, b, c;
    T_node(int A, int B, int C, int D)
    {
        id=A; a=B; b=C; c=D;
    }
};

const int N=1500+1;
const int KEY=103;

int x[N], y[N], s[N], n, a, b, c, d, i, j, max_cost=0;
vector<T_node> *points, hashs[KEY][KEY];

inline int abs(int n)
{
    return (n > 0 ? n : -n);
}

inline int gcd(int a, int b)
{
    return (a ? gcd(b%a, a) : b);
}

inline int HASH(int n)
{
    return abs(n)%KEY;
}

inline int COST(int ID)
{
    return s[ID]*s[ID]+5;
}

inline void INSERT(int ID, int a, int b, int c)
{
    points=&hashs[HASH(a)][HASH(b)];
    int cost=0;
    //cout << ID << " " << a << " " << b << " " << c << " " << HASH(a) << " " << HASH(b) << " " << HASH(c) << " ";
    for (vector<T_node>::iterator it=points->begin(); it!=points->end(); it++)
        if (it->a==a and it->b==b and it->c==c)
        {
            //cout << it->id << endl;
            if (it->id==ID) return ;
            cost+=COST(it->id);
            //cout << cost << "(" << it->id << ") ";
        }
    cost+=COST(ID);
    //cout << cost << endl;
    max_cost=max(max_cost, cost);
    points->push_back(T_node(ID, a, b, c));
    //cout << ID << " " << COST(ID) << " " << a << " " << b << " " << c << " " << HASH(a) << " " << HASH(b) << " " << HASH(c) << " " << cost << endl;
    //cout << points->size() << endl;*/
}

main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (i=1; i <= n; i++)
        scanf("%d%d%d", &x[i], &y[i], &s[i]);
    for (i=1; i < n; i++)
        for (j=i+1; j <= n; j++)
        {
            a=y[i]-y[j];
            b=x[j]-x[i];
            c=-a*x[i]-b*y[i];
            d=gcd(abs(a), gcd(abs(b), abs(c)));
            a/=d; b/=d; c/=d;
            //cout << i << " " << j << /*" " << a << " " << b << " " << c << */endl;
            INSERT(i, a, b, c);
            //cout << "inserted i" << endl;
            INSERT(j, a, b, c);
            //cout << i << " " << j << endl;
        }
    printf("%d", max_cost);
}
