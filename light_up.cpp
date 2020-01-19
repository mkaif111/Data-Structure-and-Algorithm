#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long x,y;
    cin>>x>>y;

    string num;
    cin>>num;
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i] = num[i]-'0';
    }
    // cout<<num;
    int c = 0;

    if (arr[0]==0){c++;}
    // cout<<c<<endl;

    for(int i=0;i<n-1;i++){
        if (arr[i]==1 && arr[i+1]==0){
            c++;
        }
    }
    // cout<<c<<endl;
    if(c==0){cout<<c<<endl;}

    else{cout<<(c-1)*min(x,y)+y<<endl;}



	return 0;
}
