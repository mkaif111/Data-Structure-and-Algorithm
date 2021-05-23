#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        right = left = NULL;
    }
};

pair<int, int> maxSumPath(Node *root)
{
    pair<int, int> p;
    p.first = 0;
    p.second = 0;
    if (root == NULL)
        return p;
    // first -> maxSum
    // second -> max branch sum
    pair<int, int> left = maxSumPath(root->left);
    pair<int, int> right = maxSumPath(root->right);

    int op1 = root->data;
    int op2 = root->data + left.second;
    int op3 = root->data + right.second;
    int op4 = root->data + left.second + right.second;

    int curr_max = max(max(op1, op2), max(op3, op4));

    p.second = max(left.second, max(0, right.second)) + root->data;
    p.first = max(max(left.first, right.first), curr_max);

    return p;
}

int main()
{
    /*
        1
       2  3
     23 -100
    */
    Node *root = new Node(1);
    root->right = new Node(3);
    root->left = new Node(2);
    root->left->left = new Node(23);
    root->left->right = new Node(-100);
    pair<int, int> ans = maxSumPath(root);
    cout << ans.first << " " << ans.second << endl;

    return 0;
}