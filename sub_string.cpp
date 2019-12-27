#include<bits/stdc++.h>
using namespace std;

int subs(string s1,string output[]){
  if(s1.empty()){
    output[0]="";
  return 1;}

  string small_string = s1.substr(1);

  int small_op = subs(small_string,output);
  for(int i=0;i<small_op;i++){
    output[i+small_op] = s1[0]+output[i];
  }
  return 2*small_op;
}

int main(){
  string s1;
  cin>>s1;

  string* output = new string[1000];
  int count = subs(s1,output);
  for(int i=0;i<count;i++){
    cout<<output[i]<<endl;
  }
