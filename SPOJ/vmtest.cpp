#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

inline bool is_num(string s)
{
    for (string::iterator chr=s.begin(); chr != s.end(); chr++)
        if (((*chr >= 'a') and (*chr <= 'z')) or ((*chr >= 'A') and (*chr <= 'Z')))
            return false;
    return true;
}

inline double val(string s)
{
    double res;
    stringstream ss (s);
    ss >> res;
    return res;
}

inline void process_line(string line)
{
    string token = "", sum_str = "";
    int count_token = 0, count_num = 0, count_str = 0;
    double sum_num = 0;
    line += ' ';
    for (string::iterator chr=line.begin(); chr != line.end(); chr++)
        if (*chr == ' ')
        {
            if (token.length())
            {
                count_token++;
                if (is_num(token))
                {
                    count_num++;
                    sum_num += val(token);
                }
                else
                {
                    count_str++;
                    sum_str += token;
                }
            }
            token = "";
        }
        else
            token += *chr;
    if (count_num == count_token)
        cout << sum_num;
    else if (count_str == count_token)
        cout << sum_str;
    else
        cout << "Error!";
    cout << endl;
}

main()
{
    cout << fixed << setprecision(6);
    string line;
    while (true)
    {
        getline(cin, line);
        if (cin.eof()) break ;
        process_line(line);
    }
}
