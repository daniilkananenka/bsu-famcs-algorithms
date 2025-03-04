#include <iostream>
#include <fstream>
#include <vector>

std::ifstream fin("input.txt");
std::ofstream fout("output.txt");

std::vector<int> arr;
std::vector<std::vector<int>> multDict;
std::vector<std::vector<int>> pfDict;
std::vector<std::vector<int>> results;

////////////////////// Get Weight of station-path in [begin-station, end-station)
int getPathSum(int begin, int end)
{
    int pfBegin = begin + 1;
    int pfEnd = end + 1;
    return pfDict[pfEnd - 1][pfEnd - 1] - pfDict[pfBegin - 1][pfEnd - 1] - pfDict[pfEnd - 1][pfBegin - 1] + pfDict[pfBegin - 1][pfBegin - 1];
}

int main()
{
    int n, m;
    fin >> n >> m;

    arr.resize(n);

    for (int i{}; i < n; ++i)
    {
        fin >> arr[i];
    }

    ////////////////////// Create matrix of unique mults
    multDict.resize(n, std::vector<int>(n, 0));

    for (int i{}; i < n; ++i)
    {
        for (int j{}; j < n; ++j)
        {
            if (i >= j)
            {
                multDict[i][j] = 0;
            }
            else
            {
                multDict[i][j] = arr[i] * arr[j];
            }
        }
    }

    ////////////////////// Create prefix-sum dict
    pfDict.resize(n + 1, std::vector<int>(n + 1, 0));

    for (int i{}; i < n + 1; ++i)
    {
        for (int j{}; j < n + 1; ++j)
        {
            if (i == 0 || j == 0)
            {
                pfDict[i][j] = 0;
            }
            else
            {
                pfDict[i][j] = pfDict[i][j - 1] + pfDict[i - 1][j] - pfDict[i - 1][j - 1] + multDict[i - 1][j - 1];
            }
        }
    }

    ////////////////////// Count optimal
    results.resize(n, std::vector<int>(m + 1, -1));

    int countElements = 0;
    int countIntervals = 0;

    for (int i = 0; i < n; ++i)
    { // number of elements
        for (int j = 0; j < m + 1; ++j)
        { // number of intervals
            countElements = i + 1;
            countIntervals = j + 1;

            if (countIntervals == 1)
            {
                results[i][j] = getPathSum(0, countElements);
                continue;
            }
            if (countIntervals > countElements)
            {
                results[i][j] = -1;
                continue;
            }

            for (int k = i - 1; k >= 0 && results[k][j - 1] != -1; --k)
            {
                int cur = results[k][j - 1] + getPathSum(k + 1, i + 1);
                if (results[i][j] == -1 || results[i][j] > cur)
                {
                    results[i][j] = cur;
                }
            }
        }
    }
    fout << results[n - 1][m];

    return 0;
}