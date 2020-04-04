#include<bits/stdc++.h>
using namespace std;

void listPermutaion(string prefix , string s, int& count){
    if(s.length()==0){
        cout<<prefix<<" ";
        count++;
    }
    else{

        for(int i=0;i<s.length();i++){
            char pref = s[i];

            string rem_string = s.substr(0,i)+s.substr(i+1);

            listPermutaion(prefix+pref , rem_string,count);
        }
    }
}

int main(){

    string s;
    cin>>s;
    int count=0;
    listPermutaion("",s,count);
    cout<<count<<endl;


}