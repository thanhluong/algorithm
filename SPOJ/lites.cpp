#include <cstdio>
#include <cstring>

using namespace std;

const int N=100000+1;
const int LIMIT=10*N;

int n_change[LIMIT], sum[LIMIT], n, m, q, s, e, res=0;

inline void update(int id, int l, int r)
{
    if (e < l or r < s) return ;
    if (s <= l and r <= e)
    {
        n_change[id]++;
        sum[id]=r-l+1-sum[id];
        //cout << id << " " << l << " " << r << " " << sum[id] << endl;
        return ;
    }
    update(id*2, l, (l+r)/2);
    update(id*2+1, (l+r)/2+1, r);
    sum[id]=sum[id*2]+sum[id*2+1];
    sum[id]=(n_change[id]%2 ? r-l+1-sum[id] : sum[id]);
    //cout << id << " " << l << " " << r << " " << sum[id] << endl;
}

inline void query(int id, int l, int r, int NUMBER_CHANGE)
{
    if (e < l or r < s) return ;
    if (s <= l and r <= e)
    {
        //cout << id << " " << l << " " << r << " " << sum[id] << endl;
        res+=(NUMBER_CHANGE%2 ? r-l+1-sum[id] : sum[id]);
        return ;
    }
    NUMBER_CHANGE+=n_change[id];
    query(id*2, l, (l+r)/2, NUMBER_CHANGE);
    query(id*2+1, (l+r)/2+1, r, NUMBER_CHANGE);
}

main()
{
    memset(sum, 0, sizeof(sum));
    memset(n_change, 0, sizeof(n_change));
    scanf("%d%d", &n, &m);
    while (m--)
    {
        scanf("%d%d%d", &q, &s, &e);
        if (q)
        {
            res=0;
            query(1, 1, n, 0);
            printf("%d\n", res);
        }
        else
            update(1, 1, n);
    }
}
