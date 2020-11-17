#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data = d;
        left = right = NULL;
    }
};
void BFS(node *root)
{
    if (root == NULL)
        return;
    queue<node *> q;
    q.push(root);
    // For new line
    q.push(NULL);

    while (!q.empty())
    {
        node *f = q.front();
        if (f == NULL)
        {
            cout << "\n";
            q.pop();
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << f->data << " ";
            q.pop();
            if (f->left)
                q.push(f->left);
            if (f->right)
                q.push(f->right);
        }
    }

    return;
}

node *BuildTree()
{
    int d;
    cin >> d;
    if (d == -1)
    {
        return NULL;
    }
    node *root = new node(d);
    root->left = BuildTree();
    root->right = BuildTree();
    return root;
}
void rightView(node *root, int level, int &maxlevel)
{
    if (root == NULL)
        return;
    if (maxlevel < level)
    {
        cout << root->data << " ";
        maxlevel = level;
    }
    rightView(root->right, level + 1, maxlevel);
    rightView(root->left, level + 1, maxlevel);
    return;
}

int main()
{
    node *root = BuildTree();
    int maxlevel = -1;
    BFS(root);
    rightView(root, 0, maxlevel);
}