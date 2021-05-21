
vector<int> preOrder(Node* root)
{
    //code here
    vector<int> v;
    if(root == NULL)
        return v;
    stack<Node *> s;
    s.push(root);
    while(!s.empty()){
        Node * r = s.top();
        s.pop();
        v.push_back(r->data);
        if(r->right)
            s.push(r->right);
        if(r->left)
            s.push(r->left);
        
    }
    
    return v;
}