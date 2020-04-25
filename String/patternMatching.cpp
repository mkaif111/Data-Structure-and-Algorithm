#include<bits/stdc++.h>
using namespace std;

bool patternM(string s,string p){
    int n = s.length();
    int m = p.length();

    for(int i=0;i<=(n-m);i++){
        bool foundtrue = true;
        for(int j=0;j<m;j++){
            if(s[i+j]!=p[j]){
                foundtrue = false;
                break;
            }
        }

        if(foundtrue)
            return true;
    }

    return false;
}

int main(){

    string s,p;
    cin>>s>>p;

    cout<<patternM(s,p)<<endl;

    return 0;
    
}