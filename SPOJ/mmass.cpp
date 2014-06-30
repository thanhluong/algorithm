#include <iostream>
#include <stack>

using namespace std;

inline void refine(string &s)
{
    int lim = s.length()-1;
    for(int i=lim-1; i >= 0; i--)
        if (s[i+1] == ' ') s.erase(i+1, 1);
    s = '('+s+')';
}

bool isNum(char x)
{
    return (x >= '2' && x <= '9');
}

main()
{
    string molecule;
    cin >> molecule;
    //refine(molecule);
    molecule = '('+molecule+')';
    stack<int> st; int sum; short ord['P']; ord['C'] = 12; ord['H'] = 1; ord['O'] = 16; ord['('] = 0;
    for(int i=0; i < molecule.length(); i++)
        if (molecule[i] == ')')
        {
            sum = 0;
            while (st.top() != 0)
            {
                sum += st.top();
                st.pop();
            }
            st.pop(); //remove '('
            st.push(sum);
        }
        else
            if (isNum(molecule[i]))
            {
                sum = st.top(); st.pop();
                st.push((molecule[i]-'0')*sum);
            }
            else st.push(ord[molecule[i]]);
    cout << st.top();
}

