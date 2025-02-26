#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

std::ifstream fin("in.txt");
std::ofstream fout("out.txt");

int main()
{
    // x - delete; y - insert; z - replace
    size_t x, y, z;
    fin >> x >> y >> z;

    std::string a, b;
    fin >> a >> b;

    size_t n = a.size();
    size_t m = b.size();
    std::cout << n;

    std::vector<std::vector<size_t>> matrix(n + 1, std::vector<size_t>(m + 1));

    for (size_t i = 0; i < n + 1; ++i)
    {
        for (size_t j = 0; j < m + 1; ++j)
        {
            if (i == 0)
            {
                matrix[i][j] = j * y;
            }
            else if (j == 0)
            {
                matrix[i][j] = i * x;
            }
            else
            {
                matrix[i][j] = std::min(matrix[i - 1][j] + x, std::min(matrix[i][j - 1] + y, matrix[i - 1][j - 1] + (a[i - 1] == b[j - 1] ? 0 : z)));
            }
        }
    }

    fout << matrix[n][m];

    return 0;
}