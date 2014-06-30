#include <fstream>
#include <cstdlib>

using namespace std;

ifstream fin ("average.inp");
ofstream fout ("average.out");

struct t_node
{
    int key, pos, priority;
    t_node *p, *l, *r;
} sentinel, *null, *root;

inline int rand_p()
{
    return rand() % 1000000001;
}

inline void append(t_node *par, t_node *child, bool in_left)
{
    child->p = par;
    if (in_left)
        par->l = child;
    else
        par->r = child;
}

inline void up_tree(t_node *x)
{
    t_node *y = x->p;
    t_node *z = y->p;
    t_node *branch;
    if (x==y->l)
    {
        branch = x->r;
        append(y, branch, true);
        append(x, y, false);
    }
    else
    {
        branch = x->l;
        append(y, branch, false);
        append(x, y, true);
    }
    append(z, x, (y==z->l));
    if (root==y) root = x;
}

inline void insert_key(int k, int p)
{
    t_node *x = root, *y = null, *new_node = new t_node;
    new_node->key = k;
    new_node->pos = p;
    new_node->priority = rand_p();
    new_node->p = null;
    new_node->l = null;
    new_node->r = null;
    if (root==null)
    {
        root = new_node;
        return ;
    }
    while (x != null)
    {
        y = x;
        if (k==x->key) return ;
        if (k < x->key)
            x = x->l;
        else
            x = x->r;
    }
    x = new_node;
    append(y, x, (k < y->key));
    while (true)
    {
        y = x->p;
        if (y == null or y->priority >= x->priority) return ;
        up_tree(x);
    }
}

inline int find_j(int x)
{
    t_node *node = root;
    while (node != null)
    {
        if (node->key==x) return node->pos;
        if (x < node->key)
            node = node->l;
        else
            node = node->r;
    }
    return -1;
}

main()
{
    null = &sentinel; root = null;
    int n;
    fin >> n;
    int tmp, t, i, j, ir = 0, jr = 0;
    insert_key(0, 0);
    for (i=1; i <= n; i++)
    {
        fin >> tmp;
        t += tmp;
        j = find_j(t);
        if (j >= 0 and i-j > ir-jr)
        {
            ir = i; jr = j;
        }
        insert_key(t, i);
    }
    if (ir)
        fout << jr+1 << " " << ir;
    else
        fout << -1;
    fin.close(); fout.close();
}
