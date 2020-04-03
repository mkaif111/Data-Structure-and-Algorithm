#include<bits/stdc++.h>
using namespace std;

string GoCorona(int n, int arr[]){
    for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((arr[i]==1 && arr[j]==1) && j-i<6){
                    return "NO";
                    
                }
            }
        }

    return "YES";
}

int main(){

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        int arr[n];
        int count=0;
        string ans = "YES";
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        cout<<GoCorona(n,arr)<<endl;
    }
}