#include <iostream>
#include <utility>
#include<queue>
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
    }
};
node *createTreeFromTrav(int *preorder, int *inorder, int s, int e)
{
    static int i = 0;
    if (s > e)
    {
        return NULL;
    }

    node *root = new node(preorder[i]);
    if (s == e)
        return root;

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
    root->right = createTreeFromTrav(preorder, inorder, index + 1, e);

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
void preorder_print(node *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->right != NULL and root->left != NULL)
    {
        cout << root->left->data << " => " << root->data << " <= " << root->right->data << endl;
        return preorder_print(root->left);
    }
    if (root->left != NULL and root->right == NULL)
    {
        cout << root->left->data << " => " << root->data << " <= "
             << "END" << endl;
        return preorder_print(root->left);
    }
    if (root->right != NULL and root->left == NULL)
    {
        cout << "END"
             << " => " << root->data << " <= " << root->right->data << endl;
        return preorder_print(root->right);
    }
    if (root->left == NULL and root->right == NULL)
    {
        cout << "END"
             << " => " << root->data << " <= "
             << "END" << endl;
        return;
    }

    return;
}
int main()
{
    int n;
    cin >> n;
    int preorder[n];
    for (int j = 0; j < n; j++)
    {
        cin >> preorder[j];
    }
    cin >> n;
    int inorder[n];
    for (int j = 0; j < n; j++)
    {
        cin >> inorder[j];
    }
    for (int j = 0; j < n; j++)
    {
        cout <<"( "<< preorder[j]<<" "<<inorder[j]<<" )"<<" ";
    }
    cout<<endl;
    node *root = createTreeFromTrav(preorder, inorder, 0, n - 1);
    BFS(root);
    
    preorder_print(root);

    return 0;
}