#include <iostream>
#include <cstdlib>

using namespace std;

struct t_node
{
    int key, priority;
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

inline void insert_key(int k)
{
    t_node *x = root, *y = null, *new_node = new t_node;
    new_node->key = k;
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

inline void inorder_traversal(t_node *node)
{
    if (node==null) return ;
    inorder_traversal(node->l);
    cout << node->key << " ";
    inorder_traversal(node->r);
}

main()
{
    null = &sentinel; root = null;
    insert_key(20); insert_key(4); insert_key(5); insert_key(1); insert_key(2); insert_key(3);
    inorder_traversal(root);
}
