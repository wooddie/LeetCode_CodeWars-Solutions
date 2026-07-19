#include <iostream>
#include <cassert>

struct Node
{
    int val;
    Node *left = nullptr;
    Node *right = nullptr;
};

bool search(int n, Node *root)
{
    if (root == nullptr)
        return false;

    if (root->val == n)
    {
        return true;
    }

    return search(n, root->left) || search(n, root->right);
}

int main()
{
    bool expected = false;
    bool actual = search(1, nullptr);
    assert(actual == (expected));

    expected = true;
    actual = search(2, new Node{2});
    assert(actual == (expected));

    expected = false;
    actual = search(1, new Node{2});
    assert(actual == (expected));

    return 0;
}