#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int d)
    {
        data = d;
    }
};
int sumLeaf(Node *root)
{
    // Code here
    int sum = 0;
    if (root == NULL)
        return 0;

    if (root->left == NULL and root->right == NULL)
        return root->data;
    sum += sumLeaf(root->left);
    sum += sumLeaf(root->right);

    return sum;
}

int main()
{

    return 0;
}