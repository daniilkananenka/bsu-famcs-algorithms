#include <vector>
#include <fstream>

std::ifstream fin("bst.in");
std::ofstream fout("bst.out");

const long long LEFT_BOUND = -3000000000;
const long long RIGHT_BOUND = 3000000000;

int main()
{
    long long n;
    fin >> n;
    std::vector<long long> nodes(n);
    std::vector<long long> leftBounds(n);
    std::vector<long long> rightBounds(n);

    long long rootVal;
    fin >> nodes[0];
    leftBounds[0] = LEFT_BOUND;
    rightBounds[0] = RIGHT_BOUND;

    long long m, p;
    char c;
    for (long long i = 1; i < n; ++i)
    {
        fin >> m >> p >> c;
        nodes[i] = m;
        if (c == 'L')
        {
            leftBounds[i] = leftBounds[p - 1];
            rightBounds[i] = nodes[p - 1];
        }
        if (c == 'R')
        {
            leftBounds[i] = nodes[p - 1];
            rightBounds[i] = rightBounds[p - 1];
        }

        if (nodes[i] < leftBounds[i] || nodes[i] >= rightBounds[i])
        {
            fout << "NO";
            return 0;
        }
    }

    fout << "YES";

    return 0;
}