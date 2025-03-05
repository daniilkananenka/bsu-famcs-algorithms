#include <iostream>
#include <vector>
#include <fstream>
#include <cstdint>

std::ifstream fin("input.txt");
std::ofstream fout("output.txt");

int main()
{
    int64_t n;
    fin >> n;

    int i = 0;
    while (n != 0)
    {
        if (n & 1 == 1)
        {
            fout << i << "\n";
        }
        n >>= 1;
        ++i;
    }

    return 0;
}