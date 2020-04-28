#include<bits/stdc++.h>
using namespace std;


int main(){

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;
        int *arr = new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        vector<int> result;
        bool sign = true;
        if(arr[0]<0) sign = false;

        int mx = INT_MIN;
        int min = INT_MAX;

        for(int i=0;i<n;i++){

            if(arr[i]>0 && sign){
                if(arr[i]>mx)
                    mx = arr[i];
            }
            else if(arr[i]<0 && sign==false){
                 if(arr[i]>min)
                    min = arr[i];

            }

            if(arr[i]>0 && sign==false )
                    result.push_back(min),sign=true;
            if(arr[i]<0 && sign==true)
                    result.push_back(mx),sign=false;
            if(i==n-1){
                if(arr[i]>0 && sign){
                if(arr[i]>mx)
                    mx = arr[i];
                    result.push_back(mx);

            }
            else if(arr[i]<0 && sign==false){
                 if(arr[i]>min)
                    min = arr[i];
                    result.push_back(min);
            }

            }


        }

        for(auto i:result){
            cout<<i<<" ";
        }
        cout<<endl;


    }
}