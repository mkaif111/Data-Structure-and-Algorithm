#include <iostream>
#include <vector>
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

node *createTreeFromTrav(int *preorder, int *inorder, int s, int e)
{
    static int i = 0;
    if (s >= e)
    {
        return NULL;
    }

    node *root = new node(preorder[i]);

    int index = -1;
    for (int j = s; j <= e; j++)
    {
        if (preorder[i] == inorder[j])
        {
            index = j;
            break;
        }
    }
    i++;
    root->left = createTreeFromTrav(preorder, inorder, s, index - 1);
    root->right = createTreeFromTrav(preorder, inorder, index, e);

    return root;
}

// Print level order by BFS
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

int main()
{
    int n;
    cin >> n;
    int preorder[n];
    for (int i = 0; i < n; i++)
        cin >> preorder[i];
    int inorder[n];
    for (int i = 0; i < n; i++)
        cin >> inorder[i];
    node *root = createTreeFromTrav(preorder, inorder, 0, n - 1);
    BFS(root);
}