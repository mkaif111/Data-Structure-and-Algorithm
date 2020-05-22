#include<iostream>
#include<string>
using namespace std;

struct TrieNode{
    TrieNode *child[26];
    bool isEnd;
    TrieNode(){
        for(int i=0;i<26;i++){
            child[i] = NULL;
        }
        isEnd = false;
    }
};
void dfs(TrieNode* root,string key){
    if(root->isEnd)
        cout<<key<<endl;
    for(int i=0;i<26;i++){
        if(root->child[i])
            {   string newkey = key + (char)((int)'a'+i);
                dfs(root->child[i],newkey);
                }
    }
}
void insert(TrieNode* root,string key){
    TrieNode* curr = root;
    
    for(int i=0;i<key.length();i++){

        int index = key[i]-'a';
        if(!curr->child[index])
            curr->child[index] = new TrieNode();

        curr = curr->child[index];
    }
    curr->isEnd = true;
}

int autosuggestion(TrieNode *root , string key){
    TrieNode* curr = root;
    for(int i=0;i<key.length();i++){
        int index = key[i]-'a';
        if(curr->child[index]==NULL)
            return -1;
        curr = curr->child[index];

    }
    
    dfs(curr,key);
    return 0;
}

int main(){
    int m,n;
    cin>>n;
    TrieNode* root = new TrieNode();
    while(n--)
    {
        string s;
        cin>>s;
        insert(root,s);
    }
    cin>>m;
    while(m--){
        string prefix;
        cin>>prefix;
        int x = autosuggestion(root,prefix);
        if(x==-1)
        {
         cout<<"No suggestions"<<endl;
         insert(root,prefix); // insert new word;
        }
    }


}