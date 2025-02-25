#include <iostream>
#include <set>
#include <unordered_set>
#include <fstream>

int main()
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    std::set<long long> numbers;

    long long num = 0;
    while (fin >> num)
    {
        numbers.insert(num);
    }

    long long res = 0;
    for (auto i : numbers)
    {
        res += i;
    }
    fout << res << std::endl;

    return 0;
}