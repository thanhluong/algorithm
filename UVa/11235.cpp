#include <cstdio>
#include <iostream>

using namespace std;

const int N=100000;

int n, q, i, j, res, LEFT, v_LEFT, a[10*N], s[2*N+1], f[2*N+1], L[10*N], R[10*N], MAX[10*N];

inline int get_intersection(int s_1, int f_1, int s_2, int f_2)
{
    if (f_1 < s_2 or f_2 < s_1) return 0;
    return (s_1 <= s_2 ? f_1-s_2 : f_2-s_1)+1;
}

inline void load_data()
{
    int i;
    scanf("%d", &q);
    for (i=1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        a[i]+=N;
    }
    s[a[1]]=1; f[a[n]]=n;
    for (i=2; i <= n; i++)
        if (a[i] != a[i-1])
        {
            f[a[i-1]]=i-1;
            s[a[i]]=i;
        }
}

inline void build_tree(int id, int l, int r)
{
    if (l==r)
    {
        L[id]=1;
        R[id]=1;
        MAX[id]=1;
        return ;
    }
    int m=(l+r)/2;
    build_tree(id*2, l, m);
    build_tree(id*2+1, m+1, r);
    MAX[id]=max(MAX[id*2], max(MAX[id*2+1], (a[m]==a[m+1] ? R[id*2]+L[id*2+1]:0)));
    L[id]=get_intersection(s[a[l]], f[a[l]], l, r);
    R[id]=get_intersection(s[a[r]], f[a[r]], l, r);
    //cout << l << " " << r << " " << L[id] << " " << R[id] << " " << MAX[id] << endl;
}

inline void query(int id, int l, int r, int i, int j)
{
    if (r < i or j < l) return ;
    if (i <= l and r <= j)
    {
        res=max(res, max(MAX[id], L[id]+(v_LEFT==a[l] ? LEFT : 0)));
        if (v_LEFT==a[r])
            LEFT += r-l+1;
        else
        {
            LEFT = R[id];
            v_LEFT = a[r];
        }
        cout << l << " " << r << " " << v_LEFT-N << " " << LEFT << endl;
        return ;
    }
    query(id*2, l, (l+r)/2, i, j);
    query(id*2+1, (l+r)/2+1, r, i, j);
    cout << l << " " << r << " " << v_LEFT-N << " " << LEFT << endl;
}

main()
{
    while (true)
    {
        scanf("%d", &n);
        if (!n) break;
        load_data();
        build_tree(1, 1, n);
        while (q--)
        {
            scanf("%d%d", &i, &j);
            LEFT=0; v_LEFT=-1; res=0;
            query(1, 1, n, i, j);
            printf("%d\n", res);
        }
    }
}
