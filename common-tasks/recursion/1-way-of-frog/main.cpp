#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> counts(n, 0);
    std::vector<int> steps(n, 0);

    for (int i = 0; i < n; ++i)
    {
        std::cin >> counts[i];
    }

    if (n == 1)
    {
        std::cout << counts[0] << "\n"
                  << 1;
        return 0;
    }
    if (n == 2)
    {
        std::cout << -1;
        return 0;
    }

    counts[1] = -1;
    for (int i = 2; i < n; ++i)
    {
        if (i >= 3 && counts[i - 2] < counts[i - 3])
        {
            counts[i] += counts[i - 3];
            steps[i] = i - 3;
        }
        else
        {
            counts[i] += counts[i - 2];
            steps[i] = i - 2;
        }
    }

    std::cout << counts[n - 1] << '\n';

    std::vector<int> res(n + 3, 0);
    int i = n - 1;
    int res_end = 0;
    while (i != 0)
    {
        res[res_end] = i;
        i = steps[i];
        ++res_end;
    }

    for (int j = res_end; j >= 0; --j)
    {
        std::cout << res[j] + 1 << " ";
    }

    return 0;
}