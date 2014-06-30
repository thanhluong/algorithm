#include <iostream>

using namespace std;

struct t_node
{
    t_node* child['z'+1];
} sentinel, *null, *root;

inline t_node *new_node()
{
    t_node *node = new t_node;
    for (char chr='@'; chr <= 'z'; chr++)
        node->child[chr] = null;
    return node;
}

inline void insert_trie(string s)
{
    t_node *p = root;
    for (string::iterator chr=s.begin(); chr != s.end(); chr++)
    {
        p = p->child[*chr];
        if (p == null)
            p = new_node();
    }
}

main()
{
    null = &sentinel;
    root = new_node();
    string s, suffix = "@";
    cin >> s;
    for (int i=s.length()-1; i >= 0; i--)
    {
        insert_trie(suffix);
        suffix = s[i]+suffix;
    }
}
