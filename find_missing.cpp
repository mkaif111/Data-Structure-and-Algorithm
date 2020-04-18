#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        
        cin>>arr[i];
        
    }

    int missing=1;
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        if(arr[i]<=0)
            continue;
        else{
            if(arr[i]!=missing)
                break;
            else{
                missing++;
            }
        }
    }

    cout<<missing<<endl;
}