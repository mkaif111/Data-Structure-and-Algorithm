#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool solve(int *arr, int n, int sum, vector<int> v){
    if(sum == 0 and v.size()>=1){
        return true;
    }
    if(n==0)
        return false;
    bool ex = solve(arr,n-1,sum,v);
    if(ex)
        return true;
    v.push_back(arr[n-1]);
    bool inc  = solve(arr,n-1,sum+arr[n-1],v);
    if(inc)
        return true;
    
    return false;
}

int main(){
    int t; cin>>t;
    for(int T = 1; T<=t;T++){
        int n; cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<int> v;
        bool ans = solve(arr,n,0,v);
        if(ans)
            printf("Yes \n");
        else 
            printf("No \n");
    }
    return 0;
}