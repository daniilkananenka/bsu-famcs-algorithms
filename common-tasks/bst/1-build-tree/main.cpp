#include <iostream>
#include <vector>
#include <fstream>

std::ifstream fin("input.txt");
std::ofstream fout("output.txt");

class Node
{
public:
    Node *left = nullptr;
    Node *right = nullptr;
    int value;

    Node(int val)
    {
        value = val;
    }

    void add(int val)
    {
        if (val == value)
            return;
        if (val < value)
        {
            if (left == nullptr)
            {
                left = new Node(val);
                return;
            }
            left->add(val);
            return;
        }
        if (val > value)
        {
            if (right == nullptr)
            {
                right = new Node(val);
                return;
            }
            right->add(val);
            return;
        }
    }

    void print()
    {
        fout << value << "\n";
        if (left != nullptr)
        {
            left->print();
        }
        if (right != nullptr)
        {
            right->print();
        }
    }
};

int main()
{
    int n;

    Node *root = nullptr;

    int current = 0;
    while (fin >> current)
    {
        if (root == nullptr)
        {
            root = new Node(current);
            continue;
        }
        root->add(current);
    }
    root->print();

    return 0;
}