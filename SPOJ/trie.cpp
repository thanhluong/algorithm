#include <iostream>

using namespace std;

struct trie
{
    trie *child[256];
} sentinel, *root, *null;

string s, sub;
int t;

inline trie *new_node()
{
    trie *node=new trie;
    for (int c=0; c < 256; c++) node->child[c]=null;
    return node;
}

inline void INSERT(string s)
{
    trie *node=root, *par;
    for (string::iterator chr=s.begin(); chr != s.end(); chr++)
    {
        par=node; node=node->child[*chr];
        if (node==null)
        {
            node=new_node();
            par->child[*chr]=node;
        }
    }
}

inline void build_suffix_trie()
{
    string t="";
    for (string::reverse_iterator chr=s.rbegin(); chr != s.rend(); chr++)
    {
        t=*chr+t;
        INSERT(t);
    }
}

inline bool check(string s)
{
    trie *node=root;
    for (string::iterator chr=s.begin(); chr != s.end(); chr++)
    {
        node=node->child[*chr];
        if (node==null) return false;
    }
    return true;
}

inline void inorder_traversal()
{
}

main()
{
    null=&sentinel; root=new_node();
    cin >> s;
    s += '@';
    build_suffix_trie();
    cin >> t;
    while (t--)
    {
        cin >> sub;
        cout << "is " << (check(sub) ? "" : "not ") << "substring" << endl;
    }
}
