#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

std::ifstream fin("input.txt");
std::ofstream fout("output.txt");

std::vector<int> A;
std::vector<int> B;

int main()
{
    int n;
    fin >> n;

    A.resize(n);
    B.resize(n, 0);

    for (int i{}; i < n; ++i)
    {
        fin >> A[i];
    }

    int bEnd = 0;

    for (int i{}; i < n; ++i)
    {
        std::vector<int>::iterator it = std::upper_bound(B.begin(), B.begin() + bEnd, A[i]);
        std::cout << (it >= B.begin() + 1);
        if (it >= B.begin() + 1)
        {
            if (*(it - 1) == A[i])
            {
                continue;
            }
        }
        *it = A[i];
        if (it == B.begin() + bEnd)
        {
            ++bEnd;
        }
    }

    fout << bEnd;

    return 0;
}