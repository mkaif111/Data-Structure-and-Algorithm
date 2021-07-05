#include<bits/stdc++.h>
using namespace std;

void sol(vector<int> arr){
    int n = arr.size();
    vector<int> ans;
    unordered_map<int,int> m;
    for(auto it: arr){
        if(m.find(it) == m.end()){
            cout<<it<<" ";
            m[it] = 1;
        }
        
    }
    cout<<endl;
    
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr(2*n);
        for(int i=0;i<2*n;i++)
            cin>>arr[i];
        sol(arr);
    }
}