#include <iostream>
#include <fstream>
#include <vector>

std::ifstream fin("input.txt");
std::ofstream fout("output.txt");

std::vector<int> arr;
std::vector<std::vector<int>> multDict;
std::vector<std::vector<int>> pfDict;

////////////////////// Get Weight of station-path in [begin-station, end-station)
int getPathSum(int begin, int end)
{
    int pfBegin = begin + 1;
    int pfEnd = end + 1;
    return pfDict[pfEnd - 1][pfEnd - 1] - pfDict[pfBegin - 1][pfEnd - 1] - pfDict[pfEnd - 1][pfBegin - 1] + pfDict[pfBegin - 1][pfBegin - 1];
}

int optimal(int begin, int end, int boomCount)
{
    if (end - begin == 1)
    {
        return getPathSum(begin, end);
    }
    if (boomCount == 0)
    {
        return getPathSum(begin, end);
    }

    int min = -1;
    int current = 0;
    for (int i = begin + 1; i < end - boomCount + 1; ++i)
    {
        current = optimal(begin, i, 0) + optimal(i, end, boomCount - 1);
        if (min > current || min == -1)
        {
            min = current;
        }
    }
    return min;
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
    int res = optimal(0, n, m);

    fout << res;

    return 0;
}