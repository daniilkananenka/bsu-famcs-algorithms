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

    Node *add(int val)
    {
        if (val == value)
            return this;
        if (val < value)
        {
            if (left == nullptr)
            {
                left = new Node(val);
                return left;
            }
            return left->add(val);
        }
        if (val > value)
        {
            if (right == nullptr)
            {
                right = new Node(val);
                return right;
            }
            return right->add(val);
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

Node *findMin(Node *root)
{
    while (root->left != nullptr)
    {
        root = root->left;
    }
    return root;
}

Node *removeNode(Node *root, int key)
{
    if (root == nullptr)
    {
        return root;
    }

    if (key < root->value)
    {
        root->left = removeNode(root->left, key);
    }
    else if (key > root->value)
    {
        root->right = removeNode(root->right, key);
    }
    else
    {
        Node *temp = nullptr;
        if (root->left == nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            Node *temp = findMin(root->right);
            root->value = temp->value;
            root->right = removeNode(root->right, temp->value);
        }
    }

    return root;
}

int main()
{
    int key;
    fin >> key;

    Node *root = nullptr;

    int current = 0;
    while (fin >> current)
    {
        if (root == nullptr)
        {
            root = new Node(current);
            continue;
        }
        Node *newNode = root->add(current);
    }

    Node *newRoot = removeNode(root, key);
    newRoot->print();

    return 0;
}