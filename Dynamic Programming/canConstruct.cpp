#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
Question : can target string s can be generate using given words.
*/

bool check(string s, string p){
    for(int i=0;i<p.length();i++){
        if(p[i]!=s[i])
            return false;
    }
    return true;
}

bool canConstruct(string s, string *words, int n){
    if(s.length() == 0) return true;
    
    for(int i=0;i<n;i++){
        if(!check(s,words[i]))
            continue;
        int len = words[i].length();
        // cout<<len<<endl;
        bool tempAns = canConstruct(s.substr(len),words,n);
        if(tempAns)
            return true;
            
    }
    return false;
}

int main(){

    string s = "kaif";
    string words[5] = {"f","ai","k","e","f"};
    int n = 5;
    cout<<canConstruct(s,words,n);
}