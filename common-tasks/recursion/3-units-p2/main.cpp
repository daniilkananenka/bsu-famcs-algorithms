#include <iostream>
#include <vector>

int MOD = 1000000007;

int power(long long a, long long n)
{
    int res = 1;
    while (n != 0)
    {
        if (n & 1)
        {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}

int main()
{
    long long n, k;
    std::cin >> n >> k;

    long long a = 1;
    for (long long i = k + 1; i <= n; ++i)
    {
        a = ((i % MOD) * (a % MOD)) % MOD;
    }

    long long b = 1;
    for (long long i = 1; i <= n - k; ++i)
    {
        b = ((i % MOD) * (b % MOD)) % MOD;
    }
    long long c = power(b, MOD - 2);

    std::cout << ((a * c) % MOD);

    return 0;
}