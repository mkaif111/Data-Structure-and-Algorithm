#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<map>
#include<utility>
#include<unordered_set>

using namespace std;
#define ll long long int

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
node *buildTree()
{
    int d;
    cin >> d;
    if (d == -1)
        return NULL;
    node *root = new node(d);
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *r = q.front();
        cin >> d;
        if (d != -1)
        {
            r->left = new node(d);
            q.push(r->left);
        }
        cin >> d;
        if (d != -1)
        {
            r->right = new node(d);
            q.push(r->right);
        }
    }
    return root;
}
void bottomView(node* root){
    map<int , int> m;
    queue<pair<int, node*>> q;
    q.push({0,root});
    while(!q.empty()){
        int hd = q.front().first;
        node* r = q.front().second;
        q.pop();
        m[hd] = r->data;
        if(r->left){
            q.push({hd-1,r->left});
        }
        if(r->right){
            q.push({hd+1,r->right});
        }
    }
    for(auto it: m){
        cout<<it.second<<" ";
    }
    cout<<endl;
}
int main(){
    node* root = buildTree();
    bottomView(root);
    return 0;
}