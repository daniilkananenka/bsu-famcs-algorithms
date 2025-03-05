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
    std::vector<int64_t> arr(n);
    for (int64_t i = 0; i < n; ++i)
    {
        fin >> arr[i];
    }

    int64_t left = 0;
    int64_t right = 0;
    for (int64_t i = 0; i < n; ++i)
    {
        left = 2 * i + 1;
        right = 2 * i + 2;
        if (left < n && arr[left] < arr[i])
        {
            fout << "No";
            return 0;
        }
        if (right < n && arr[right] < arr[i])
        {
            fout << "No";
            return 0;
        }
    }
    fout << "Yes";

    return 0;
}