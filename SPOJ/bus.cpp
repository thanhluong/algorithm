#include <fstream>

using namespace std;

ifstream fin ("bus.inp");
ofstream fout ("bus.out");

inline int calc(int i, int j)
{
    if (i <= 0) return 0;
    if (i%j)
        return i/j+1;
    else
        return i/j;
}

main()
{
    int n, d, t_0, s;
    fin >> n >> d >> t_0;
    while (n--)
    {
        fin >> s;
        fout << calc(s-t_0, d)+1 << " ";
    }
    fin.close(); fout.close();
}
