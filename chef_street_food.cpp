#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
  int  max_ = INT_MIN;
    while(n--){
      int s,v,p;
      cin>>s>>v>>p;
      if ((v*p)%(s+1)==0){
        if ((p*v)/(s+1)>=max_){
          max_ = (p*v)/(s+1);
          // cout<<"this is "<<max_<<endl;
        }
      }
      else{
        if((p/(s+1))*(v)>=max_){max_ = (p/(1+s))*(v);}
      }

    }
    cout<<max_<<endl;
  }
}
