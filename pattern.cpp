#include<bits/stdc++.h>
using namespace std;

int main(){
  int row;
  cin>>row;
  int space=1;
  bool flag=true;
  int n = row;

 for(int i=0;i<n;i++){
   if (i==0){
     for(int j=0;j<n;j++){
       cout<<"*";
     }
     cout<<endl;
   }
   else{
     int count = row/2 + 1;

     for(int j=0;j<n;j++){
       if (j==count){
         for(int w=0;w<space;w++){
         cout<<" ";}
       }
       else{
         cout<<"*";
       }
     }
     row = row-1;
     space+=2;
   }
   cout<<endl;

 }
}
