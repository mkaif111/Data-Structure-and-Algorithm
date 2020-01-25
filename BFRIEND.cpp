#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;

  while(t--){
  int n;
  long long a, b, c;
  cin>>n>>a>>b>>c;
  long long arr[n];
  bool flag = false;
  long long ans;
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
    if ((arr[i]>=a && arr[i]<=b) || (arr[i]<=a && arr[i]>=b)){
      ans = abs(a-b)+c;
      flag = true;
    }
  }
  if (flag){cout<<ans<<endl;}
  else{
    sort(arr,arr+n);
    if (arr[0]>b){
      ans = abs(arr[0]-b)+abs(arr[0]-a)+c;
      cout<<ans<<endl;
    }
    else{
      ans = abs(arr[n-1]-b)+abs(arr[n-1]-a)+c;
      cout<<ans<<endl;
    }
  }


  }
}
