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
    }
};

Node *lca(Node *root, Node *a, Node *b)
{
    if (root == NULL)
        return NULL;
    if (root == a or root == b)
        return root;
    Node *left = lca(root->left, a, b);
    Node *right = lca(root->right, a, b);
    if (left != NULL and right != NULL)
        return root;
    if (left != NULL)
        return left;
    return right;
}
int levelOfNode(Node *root, Node *a, int level)
{
    if (root == NULL)
        return -1;
    if (root == a)
        return level;
    int left = levelOfNode(root->left, a, level + 1);
    if (left != -1)
        return left;
    return levelOfNode(root->right, a, level + 1);
}
int shortestDistanceNode(Node *root, Node *a, Node *b)
{
    if (root == NULL)
        return -1;
    Node *l = lca(root, a, b);
    int aD = levelOfNode(l, a, 0);
    int bD = levelOfNode(l, b, 0);
    return aD + bD;
}

int main()
{
    /* Tree
            1
           2   7
         4  5
           6  3
    */
   
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(3);

    // shortest distance b/w 4 and 3 which is 3.
    int ans = shortestDistanceNode(root, root->left->left, root->left->right->right);
    cout << ans << endl;

    return 0;
}