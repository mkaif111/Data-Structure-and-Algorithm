#include<bits/stdc++.h>
using namespace std;

void print_sub(string input, string output){
  if(input.length()==0){
    cout<<output<<endl;
    return;

  }
  string s = input.substr(1);
  print_sub(s,output);
  print_sub(s,output+input[0]);

}

int main(){
  string n;
  cin>>n;
  print_sub(n,"");
}
