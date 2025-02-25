#include <vector>
#include <iostream>

std::vector<int> A;
std::vector<int> B;
std::vector<std::vector<int>> matrix;
int MATRIX_DIM{};

std::vector<int> ARes;
std::vector<int> BRes;

int main()
{
    int n;
    std::cin >> n;

    A.resize(n);
    B.resize(n);

    MATRIX_DIM = n + 1;
    matrix.resize(MATRIX_DIM, std::vector<int>(MATRIX_DIM));

    for (int i{}; i < n; ++i)
    {
        std::cin >> A[i];
    }
    for (int i{}; i < n; ++i)
    {
        std::cin >> B[i];
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
    ARes.resize(len);
    BRes.resize(len);

    int cur{};
    int Ai = MATRIX_DIM - 1, Bi = MATRIX_DIM - 1;
    while (matrix[Ai][Bi] != 0)
    {
        if (A[Ai - 1] == B[Bi - 1])
        {
            ARes[cur] = Ai - 1;
            BRes[cur] = Bi - 1;
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
    std::cout << len << "\n";
    for (int i = len - 1; i >= 0; --i)
    {
        std::cout << ARes[i] << " ";
    }
    std::cout << "\n";
    for (int i = len - 1; i >= 0; --i)
    {
        std::cout << BRes[i] << " ";
    }
    std::cout << "\n";
    return 0;
}