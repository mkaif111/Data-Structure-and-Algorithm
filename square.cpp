#include<iostream>
using namespace std;

#define ll long long int

int main(){

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        int* arr = new int[n];

        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        ll count=0;

        for(int i=0;i<n;i++){
            ll re = 1;
             

            for(int j=i;j<n;j++){
                re = re*arr[j];
                if(re%4 != 2)
                   {    
                       count++;
                   }
            }
        }

        cout<<count<<endl;


    }  //while loop ended

    
}