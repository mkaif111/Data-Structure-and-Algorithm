#include <iostream>
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
        left = NULL;
        right = NULL;
    }
};
void printPreorder(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
    return;
}
int height(node* root){
    if(root == NULL){
        return 0;
    }
    return max(height(root->left),height(root->right)) + 1;
}
void printKthLevel(node *root, int h, int height){
    if(root==NULL)
        return ;
    if(h==height){
        cout<<root->data<<" ";
    }
    printKthLevel(root->left,h,height-1);
    printKthLevel(root->right,h,height-1);
    return ;
}

node *buildTree()
{
    int d;
    cin >> d;
    if (d == -1)
        return NULL;
    node *root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void LevelOrderPrint(node* root){
    if(root==NULL)
        return ;
    int h = height(root);
    for(int i=h;i>=1;i--){
        printKthLevel(root,i,h);
        cout<<endl;
    }
    return;
}

int main()
{
    // int n;
    // cin >> n;
    node *root = buildTree();
    cout<<height(root)<<endl;
    LevelOrderPrint(root);
}