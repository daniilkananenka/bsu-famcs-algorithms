#include <iostream>
#include <vector>

int binarySearchRight(std::vector<int> &arr, int begin, int end, int target)
{
    if (end - begin == 0)
    {
        return -1;
    }
    if (end - begin == 1)
    {
        return begin;
    }
    int current = (begin + end) / 2;
    if (arr[current] <= target)
    {
        return binarySearchRight(arr, current, end, target);
    }
    else
    {
        return binarySearchRight(arr, begin, current, target);
    }
}

int reversedIndex(int index, int length)
{
    return length - index - 1;
}

int binarySearchLeft(std::vector<int> &arr, int begin, int end, int target)
{
    if (end - begin == 0)
    {
        return -1;
    }
    if (end - begin == 1)
    {
        return reversedIndex(begin, arr.size());
    }
    int current = (begin + end) / 2;
    if (arr[reversedIndex(current, arr.size())] >= target)
    {
        return binarySearchLeft(arr, current, end, target);
    }
    else
    {
        return binarySearchLeft(arr, begin, current, target);
    }
}

int main()
{
    int arrLength, requestsCount;
    std::cin >> arrLength;

    std::vector<int> arr(arrLength);
    for (int i = 0; i < arrLength; ++i)
    {
        std::cin >> arr[i];
    }

    std::cin >> requestsCount;
    int target;
    int left = -1;
    int right = -1;
    for (int i = 0; i < requestsCount; ++i)
    {
        std::cin >> target;
        if (arr.size() == 0)
        {
            std::cout << 0 << " " << 0 << " " << 0 << "\n";
            continue;
        }

        left = binarySearchLeft(arr, 0, arr.size(), target);
        right = binarySearchRight(arr, 0, arr.size(), target);

        if (arr[left] != target)
        {
            if (arr[left] < target)
            {
                std::cout << 0 << " " << left + 1 << " " << left + 1 << "\n";
                continue;
            }
            else
            {
                std::cout << 0 << " " << left << " " << left << "\n";
                continue;
            }
        }
        std::cout << 1 << " " << left << " " << right + 1 << "\n";

        left = -1;
        right = -1;
    }

    return 0;
}