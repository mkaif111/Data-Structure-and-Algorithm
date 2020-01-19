#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    int n,m;
    cin>>n>>m;
    int arr[m];
    int cat[n];
    for(int i=0;i<m;i++){
      cin>>arr[i];
    }
    for(int i=0;i<n;i++){
      cat[i]=0;
    }
    bool flag= true;
    for(int i=0;i<m;i++){
      for(int j=0;j<n;j++){
        if(cat[arr[i]-1]>cat[j]){
          flag = false;
        }
      }
      cat[arr[i]-1]+=1;
    }
    if(flag){cout<<"YES"<<endl;}
    else cout<<"NO"<<endl;
    

  }




  return 0;
}
