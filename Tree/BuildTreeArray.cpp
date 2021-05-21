#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d){
        data = d;
        left = right = NULL;
    }
};

node* buildTree(int arr[],int l, int h){
    if(l>h){
        return NULL;
    }
    int mid = (l+h)/2;
    node* root = new node(arr[mid]);
    root->left = buildTree(arr,l,mid-1);
    root->right = buildTree(arr,mid+1,h);

    return root;
}
void preorder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    return;
}

int main()
{   int n; cin>>n;
    int arr[n]; for(int i=0;i<n;i++) cin>>arr[i];
    node* root = buildTree(arr,0,n-1);
    preorder(root);
    return 0;
}