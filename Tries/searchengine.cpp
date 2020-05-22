#include<bits/stdc++.h>
using namespace std;

struct TrieNode{
    TrieNode *child[26];
    bool isEnd;
    int weight[26];

    TrieNode(){
        for(int i=0;i<26;i++){
            child[i] = NULL;
            weight[i] = 0;
            
        }
        isEnd = false;
    }

};
void insert(TrieNode *root,string key,int weight){

    TrieNode *curr = root;
    for(int i=0;i<key.length();i++){
        int index = key[i]-'a';
        if(curr->child[index]==NULL)
            {
            curr->child[index] = new TrieNode();
            
            
                
            }
        
        curr->weight[index] = max(weight,curr->weight[index]);    
        curr = curr->child[index];
        
            
    }
    curr->isEnd = true;
}

int f(string key,TrieNode *root){
    TrieNode *curr = root;
    int maxx;
    for(int i=0;i<key.length();i++)
        {
            int index = key[i]-'a';
            if(!curr->child[index])
                return -1;
            maxx = curr->weight[index];
            curr = curr->child[index];
        	
        }

    return maxx;

}

int main(){
    TrieNode *root = new TrieNode();
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        string s;
        int w;
        cin>>s>>w;
        insert(root,s,w);
    }
    while(q--)
    {
        string s;
        cin>>s;

        cout<<f(s,root)<<endl;
    }
   
 


}