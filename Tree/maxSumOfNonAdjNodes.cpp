#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*left,*right;
    Node(int d){
        data = d;
        left =right = NULL;
    }
};

// define func blueprint so that func call in any sequence
int sumOfGrandChildren(Node* root,unordered_map<Node*,int> &m);
int MaxSum(Node* root,unordered_map<Node* ,int> &m);

int MaxSum(Node* root,unordered_map<Node*,int> &m){
    if(root == NULL)
        return 0;
    
    if(m.find(root) != m.end())
        return m[root];
    // include current node
    int inc = root->data + sumOfGrandChildren(root,m);
    // exc current node
    int exc = MaxSum(root->left,m) + MaxSum(root->right,m);
    m[root] = max(inc,exc);
    return m[root];
}
int sumOfGrandChildren(Node* root,unordered_map<Node*,int> &m){
    int sum = 0;
    if(root == NULL)
        return sum;
    if(root->left)
        sum += MaxSum(root->left->left,m) + MaxSum(root->left->right,m);
    if(root->right)
        sum += MaxSum(root->right->left,m)+ MaxSum(root->right->right,m);
    return sum;
}
int sol(Node* root){
    if(root == NULL)
        return 0;
    unordered_map<Node*,int> m;
    return MaxSum(root,m);
}
int main(){
    /* 
            1
        2*       3
              4*     56 * 
    ans = 64 -> 2, 4, 56
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(56);
    cout<<sol(root)<<endl;
    return 0;
}