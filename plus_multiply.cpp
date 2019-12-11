#include<bits/stdc++.h>
using namespace std;
int fun(long long arr[] , int size){
  int count=0;
  for(int i=0;i<size;i++){
    for(int j=i+1;j<size;j++){
      if (arr[i]+arr[j]==arr[i]*arr[j]){
        count++;
      }
    }
  }

  return count;
}

int main(){
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    long long arr[n];

    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
    }
    
    cout<<fun(arr,n)<<endl;


  }

}
