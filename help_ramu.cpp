#include<iostream>
using namespace std;

int main(){
  int t;
  cin>>t;
  int c1,c2,c3,c4,n,m;
  int r[1005];
  int c[1005];

  while(t--){
    cin>>c1>>c2>>c3>>c4;
    cin>>n>>m;
    for(int i=0;i<n;i++){
      cin>>r[i];
    }
    for(int i=0;i<m;i++){
      cin>>c[i];
    }
    int r_cost = 0;
    for(int i=0;i<n;i++){
      r_cost +=min(c1*r[i],c2);
    }
    r_cost = min(r_cost,c3);

    int c_cost=0;
    for(int i=0;i<m;i++){
      c_cost +=min(c1*c[i],c2);
    }
    c_cost = min(c_cost,c3);

    int ans = min(c4,r_cost+c_cost);
    cout<<ans<<endl;
  }

}
