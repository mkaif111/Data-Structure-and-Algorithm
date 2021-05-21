#include <iostream>
#include <vector>
#include <utility>
#include <unordered_set>
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
bool pairSum(int sum, node *root, unordered_set<int> &s)
{

    if (root == NULL)
        return false;

    if (pairSum(sum, root->left, s))
    {
        return true;
    }
    if (s.find(sum - root->data)!=s.end())
        return true;
    else
    {
        s.push(root->data);
    }
    return pairSum(sum, root->right, s);
}

int main(){
    node* root = buildTree();
    int sum = 0;
    unordered_set<int> s;
    cout<<pairSum(sum,root,s)<<endl;
}