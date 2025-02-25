#include <vector>
#include <iostream>
#include <fstream>
#include <string>

std::ifstream fin("input.txt");
std::ofstream fout("output.txt");

std::vector<char> A;
std::vector<char> B;
std::vector<std::vector<int>> matrix;
int MATRIX_DIM{};

std::vector<char> res;

int main()
{
    std::string str;
    fin >> str;

    int n = str.length();

    A.resize(n);
    B.resize(n);

    MATRIX_DIM = n + 1;
    matrix.resize(MATRIX_DIM, std::vector<int>(MATRIX_DIM));

    for (int i{}; i < n; ++i)
    {
        A[i] = str[i];
    }
    for (int i{}; i < n; ++i)
    {
        B[i] = str[n - 1 - i];
    }
    for (int i{}; i < MATRIX_DIM; ++i)
    {
        for (int j{}; j < MATRIX_DIM; ++j)
        {
            if (i == 0 || j == 0)
            {
                matrix[i][j] = 0;
                continue;
            }
            if (A[i - 1] == B[j - 1])
            {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            }
            else
            {
                matrix[i][j] = std::max(matrix[i - 1][j], matrix[i][j - 1]);
            }
        }
    }

    int len = matrix[MATRIX_DIM - 1][MATRIX_DIM - 1];
    res.resize(len);

    int cur{};
    int Ai = MATRIX_DIM - 1, Bi = MATRIX_DIM - 1;
    while (matrix[Ai][Bi] != 0)
    {
        if (A[Ai - 1] == B[Bi - 1])
        {
            res[cur] = A[Ai - 1];
            --Ai;
            --Bi;
            ++cur;
        }
        else
        {
            if (matrix[Ai][Bi] == matrix[Ai - 1][Bi])
            {
                --Ai;
            }
            else
            {
                --Bi;
            }
        }
    }
    fout << len << "\n";
    for (int i{}; i < len; ++i)
    {
        fout << res[i];
    }
    fout << "\n";
    return 0;
}