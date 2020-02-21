#include<bits/stdc++.h>
using namespace std;

int main(){

  int t;
  cin>>t;

  while(t--){
    int m1,y1;
    cin>>m1>>y1;
    int m2,y2;
    cin>>m2>>y2;
    int count = 0;
    while(y1<=y2 || m1<=m2){
      // cout<<"hi"<<endl;
      if(m1%13==0){y1++;m1=1;}
      if(m1>m2 && y1>=y2){break;}
      if(m1==2 && ((y1%400==0 || y1%4==0) && y1%100!=0)){ count++; }
      m1++;
    }
    cout<<count<<endl;

  }

}
