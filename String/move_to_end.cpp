// move x to end

#include<iostream>
#include<string>
using namespace std;

string sol(string s , int n){
    if(n==s.length() || s.length()==0)
        return s;
    string x = sol(s, n+1);
    if(x[n]=='x'){
        x = x.substr(0,n) + x.substr(n+1) + "x";
    }

    return x;
}

int main(){
    string s; cin>>s;
    cout<<sol(s,0)<<endl;
}