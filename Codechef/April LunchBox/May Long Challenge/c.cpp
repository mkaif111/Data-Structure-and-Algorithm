#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){
        int n, k;
        cin>>n>>k;

        int *arr=new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        bool* visited = new bool[n]();
        vector<int> index,value;

        for(int i=1;i<=n;i++){
            

                if(i != arr[i-1]){

                index.push_back(i);
                value.push_back(arr[i-1]);

                }

               
 
        }

        for(int i=1;i+2<=n;i++){
            printf("%d %d %d \n",i,i+1,i+2);
        }




    }
}