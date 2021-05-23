#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node* right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
void printKthLevel(Node *root, int k)
{
    if (root == NULL)
        return;
    if (k == 0)
    {    cout << root->data << " ";
         return;
    }
    printKthLevel(root->left, k - 1);
    printKthLevel(root->right, k - 1);
    return;
}
int kDistanceFromTarget(Node* root,Node* target,int k){
    if(root == NULL)
        return -1;
    if(root == target)
    {
        printKthLevel(target,k);
        return 0;
    }
    // Ancestors
    int DL = kDistanceFromTarget(root->left,target,k);
    if(DL!=-1){
        if(DL+1 == k)
            cout<<root->data<<" ";
        else
            printKthLevel(root->right,k-2-DL);
        return DL+1;
    }
    int DR = kDistanceFromTarget(root->right,target,k);
    if(DR!=-1){
        if(DR+1 == k)
            cout<<root->data<<" ";
        else
            printKthLevel(root->left,k-2-DR);
        return DR+1;
    }
    return -1;
}


int main(){
//      1
//     2 3
//    4 5
//      6 7 
//       8
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);
    root->left->right->right->left = new Node(8);
    int d = kDistanceFromTarget(root,root->left->right,1);



    return 0;
}