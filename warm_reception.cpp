#include <bits/stdc++.h>
#inlude <iostream>
using namespace std;

int fun(int arr[] , int d[], int n){
  sort(arr,arr+n);
  sort(d,d+n);
  int chair =1 ;
  int result =1;
  int i=1;
  int j=0;
  while (i<n && j<n){
    if (arr[i]<=dep[j]){chair++;i++;
    if (chair>result){result = chair;}}

    else{chair--; j++;}
  }
  return result;

}
int main(){
  int n;
  cin>>n;
  int* arr = new int[n];
  int* d = new int[n];
  for(int i=0;i<n;i++){cin>>arr[i];}
  for(int i=0;i<n;i++){cin>>d[i];}
  cout<<fun(arr,d,n)<<endl;
  return 0;
}
