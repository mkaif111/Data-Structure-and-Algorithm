#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void pr_S(string s,int l , int r ){
  if (l==r){cout<<s<<" ";}
  else{
    for(int i=l;i<=r;i++){swap(s[l],s[i]); pr_S(s,l+1,r); swap(s[i],s[l]);}
  }
}

void print_S(string s , string curr="" , int index = 0){
  if (index ==s.length()) {
    if (curr==""){return;}
    else cout<<curr<<" "; return;

  }
  print_S(s,curr,index+1);
  print_S(s,curr+s[index],index+1);


}

int main(){
  string s;
  cin>>s;
  cout<<"Subsets"<<endl;
  print_S(s);
  cout<<"Permutation"<<endl;
  pr_S(s,0,s.length()-1);


}
