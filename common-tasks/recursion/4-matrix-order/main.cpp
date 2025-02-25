#include <iostream>
#include <vector>
#include <fstream>

std::ifstream fin("input.txt");
std::ofstream fout("output.txt");
std::vector<std::vector<int>> memo;
std::vector<std::pair<int, int>> matrixes;

int getResByInterval(int begin, int end)
{
    return memo[end - begin - 1][begin];
}

void countTurple(int begin, int end)
{
    if (end - begin == 1)
    {
        memo[0][begin] = 0;
        return;
    }
    if (end - begin == 2)
    {
        memo[1][begin] = matrixes[begin].first * matrixes[begin].second * matrixes[end - 1].second;
        return;
    }

    int minRes = -1;
    for (int i = 0; begin + i < end - 1; ++i)
    {
        int left = getResByInterval(begin, begin + i + 1);
        int right = getResByInterval(begin + i + 1, end);
        int res = left + right + matrixes[begin].first * matrixes[begin + i].second * matrixes[end - 1].second;
        if (minRes == -1 || res < minRes)
        {
            minRes = res;
        }
    }

    memo[end - begin - 1][begin] = minRes;
}

int main()
{
    int n;
    fin >> n;

    memo.resize(n, std::vector<int>(n, -1));
    matrixes.resize(n);

    for (int i = 0; i < n; ++i)
    {
        fin >> matrixes[i].first >> matrixes[i].second;
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < n - i + 1; ++j)
        {
            countTurple(j, j + i);
        }
    }

    fout << getResByInterval(0, n) << std::endl;

    return 0;
}