#include <fstream>

using namespace std;

ofstream f ("test.txt");

main()
{
    for (int i=1; i <= 300000000; i++) f << "A";
    f.close();
}
