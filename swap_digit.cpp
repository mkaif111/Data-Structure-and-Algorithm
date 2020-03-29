#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;

    while(t--){
        string f,s;
        cin>>f>>s;

        int sum=0;

        int arr[4];
        int k=0;
        for(int i=0;i<f.length();i++){
            arr[k] = f[i]-'0';
            k++;
        }
        for(int i=0;i<s.length();i++){
            arr[k] = s[i]-'0';
            k++;
        }
        // cout<<k;

        sort(arr,arr+4);

        if(k==4){
            
            sum = arr[3]*10 + arr[2] + arr[1]*10 + arr[0];
            if(arr[0]==0 && arr[1]==0)
            {
                sum = max(sum,arr[3]*10 + arr[2]*10);
            }
            if(arr[0]==0 && arr[1]!=0){
                sum = max(sum,arr[3]*10 + arr[2]*10 + arr[1]);
            }
            cout<<sum<<endl;
        }
        else if (k==3){
            
            sum = arr[2]*10 + arr[1] + arr[0];
            cout<<sum<<endl;
        }

        else if(k==2){
            sum = arr[0] + arr[1];
            cout<<sum<<endl;
        }

        
    }
}