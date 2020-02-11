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

    sort(arr,arr+n);

    int a = arr[n-1];
    int b = arr[n-2];
    int c = arr[n-3];
    // cout<<a<<b<<c;
    if ((b+c)>a){

        // cout<<"yes";
        cout<<c<<" "<<b<<" "<<a;}
    else{

    for(int i=n-1;i>=2;i--)
    {
        a = arr[i];
        b = arr[i-1];
        c = arr[i-2];

        if (b+c>a)
        {    cout<<c<<" "<<b<<" "<<a<<endl;
            break;}
        else if(i==2){cout<<-1<<endl;}
    }
    }

}
