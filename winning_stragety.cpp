#include<bits/stdc++.h>
using namespace std;
int main() {

	// Write your code here
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];

    }

    int count = 0;
    bool flag=true;
    for(int i=n-1;i>=1;i--){
        if(arr[i]==i+1){continue;}
        else if(arr[i-1]==i+1){swap(arr[i],arr[i-1]); count++;}
        else if(arr[i-2]==i+1){ arr[i-2]=arr[i-1]; arr[i-1]=arr[i]; arr[i]=i+1; count+=2; }
        else{
            flag=false;
            break;
        }
    }

    if(flag){cout<<"YES"<<endl;
            cout<<count<<endl;}
    else{cout<<"NO";}

}
