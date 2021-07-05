#include<bits/stdc++.h>
using namespace std;

void rotateAnti(vector<vector<int>> &arr,int s){
    int n = arr.size()-1-s;
    int m = arr[0].size()-1-s;
    int temp = arr[s][m];
    
    // top backward
    for(int i=m;i>=s;i--){
        int t = arr[s][i];
        arr[s][i] = temp;
        temp = t;
    }
    
    //top downward
    for(int i=s+1;i<=n;i++)
    {
        int t = arr[i][s];
        arr[i][s] = temp;
        temp = t;
    }
 
    // bottom forward<<endl;
    for(int i=s+1;i<=m;i++){
        int t = arr[n][i];
        arr[n][i] = temp;
        temp = t;
    }
    // top upward
    
    for(int i=n-1;i>=s;i--){
        int t = arr[i][m];
        arr[i][m] = temp;
        temp = t;
    }
}

void display(vector<vector<int>> arr){
    for(auto IT:arr){
        for(auto it:IT)
            cout<<it<<" ";
        cout<<endl;
    }
}

void sol(vector<vector<int>> &arr,int s, int r){

    for(int i=0;i<r;i++)
      {  rotateAnti(arr,s-1);
         display(arr);
      }
}
int main(){
    int n,m; cin>>n>>m;
    vector<vector<int>> arr(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>arr[i][j];
    }

    int s,r; cin>>s>>r;
    sol(arr,s,r);

    return 0;
}