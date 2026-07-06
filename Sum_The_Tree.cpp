#include <iostream>
#include <cassert>

struct node
{
    int value;
    node *left;
    node *right;
};

int sumTheTreeValues(node *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int leftSum = sumTheTreeValues(root->left);
    int rightSum = sumTheTreeValues(root->right);

    return root->value + leftSum + rightSum;
}

int main()
{
    // Easy
    node easyNode = {10, new node{1, nullptr, nullptr}, new node{2, nullptr, nullptr}};
    assert(sumTheTreeValues(&easyNode) == (13));

    // Unbalanced
    node unbalancedNode = {11, new node{0, nullptr, nullptr}, new node{0, nullptr, new node{1, nullptr, nullptr}}};
    assert(sumTheTreeValues(&unbalancedNode) == (12));

    return 0;
}