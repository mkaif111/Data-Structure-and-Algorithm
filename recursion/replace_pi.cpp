#include<iostream>
#include<string>
using namespace std;

string sol(string s, int i){
	if(s.length()<1){
		return s
	}
	if(i==s.length()){
		return s;
	}
	string res = sol(s,i+1);
	if(res[i]=='x'){
		res = res.substr(0,i) + "3.14" + res.substr(i+1);
	}
	return res;
}
int main() {
	string s; cin>>s;
	cout<<sol(s,0)<<endl;
	return 0;
}