#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    string ans = "Yes";
    // int count=1;
    for(int i=0;i<n-1;i++){
        if(arr[i+1]==arr[i]-1){
            int temp = arr[i+1];
            arr[i+1]=arr[i];
            arr[i]=temp;
            }

    }

    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){ans ="No";break;}
    }
    cout<<ans<<endl;}
	return 0;
}
