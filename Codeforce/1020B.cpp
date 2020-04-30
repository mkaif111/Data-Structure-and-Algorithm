#include<bits/stdc++.h>
using namespace std;



int dfs(int start, bool* visited,int* arr){
    visited[start] = true;
    
    
        
    if(visited[arr[start]]==false)
    {   
        dfs(arr[start],visited,arr);}
    else{return arr[start];}
        
    

    
}



int main(){

    int n;
    cin>>n;
    int arr[n+1];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    

    for(int i=1;i<=n;i++){
        bool* visited = new bool[n+1]();
        int culprit = dfs(i,visited,arr);
        

        cout<<culprit<<" ";
    }
    cout<<endl;



}