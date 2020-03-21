#include<bits/stdc++.h>
using namespace std;

int bS_L(int index,int n,int* arr){
  int l=0;
  int h = index;
  int *temp = new int[index+1];
  for(int i=0;i<=index;i++){
    temp[i] = arr[i];
  }
  sort(temp,temp+index+1);
  while(l<=h){
    int mid = (l+h)/2;
    if (mid-1>=0 && (temp[mid]>arr[index] && temp[mid-1]<=arr[index]) ){
      int d = temp[mid];
      delete temp;
      return d;
    }

    else if(temp[mid]>arr[index]){h=mid;}
    else{l=mid;}

  }
  int ans = temp[index];

  delete temp;
  return ans;
}
int bS_R(int index,int n,int* arr){
  int l=0;
  int h = n-index;
  int *temp = new int[h];
  for(int i=index;i<n;i++){
    temp[i] = arr[i];
  }
  sort(temp,temp+(n-index));
  int ans = temp[n-index-1];



  delete temp;
  return ans;
}

int main(){
  int n;
  cin>>n;

  int *arr = new int[n];
  // int *check = new int[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
    // check[i] =
  }

  int *dp = new int[n];

  dp[0] = arr[0];

  for(int i=1;i<n;i++){
    int left_side = bS_L(i,n,dp);
    int right_side = bS_R(i,n,arr);

    dp[i]=min(left_side,min(right_side,arr[i]));
  }



  for(int i=0;i<n;i++){
    cout<<dp[i]<<" ";
  }


  delete [] arr;
  delete [] dp;

  cout<<"Done"<<endl;



}
