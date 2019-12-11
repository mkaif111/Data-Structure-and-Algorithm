#include<bits/stdc++.h>
using namespace std;

bool check(int cow , long long position[] , int n , long long value){

  long long last_position = position[0];
  int count=1;
  for(int i=1;i<n;i++){
    if (position[i]-last_position>=value){
      last_position = position[i];
      count++;
    }
    if(count == cow){return true;}
  }
  return false;
}

int main(){
  int t;
  cin>>t;
  while(t--){
    int n,c;
    cin>>n>>c;
    long long position[n];
    for(int i=0;i<n;i++){cin>>position[i];}
    sort(position,position+n);
    long long start=0;
    long long end =position[n-1]-position[0];

    long long ans = -1;
    while(start<=end){
      long long mid = start + (end-start)/2 ;
      if(check(c,position,n , mid)){ ans = mid;
      start = mid+1;
    }
    else{end=mid-1;}
    }
    cout<<ans<<endl;
  }

}
