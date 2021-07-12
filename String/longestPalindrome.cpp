//https://codeforces.com/contest/1304/problem/B
#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,m; cin>>n>>m;
    unordered_set<string> S;
    vector<string> s,left,right;
    for(int i=0;i<n;i++){
        string st; cin>>st;
        s.push_back(st);
        S.insert(st);
    }
    string mid = "";
    for(int i=0;i<n;i++){
        string t = s[i];
        reverse(t.begin(),t.end());
        if(t == s[i]){
            mid = t;
        }
        else if(S.find(t)!=S.end()){
            left.push_back(s[i]);
            right.push_back(t);
            S.erase(t);
            S.erase(s[i]);
        }
    }
    cout<<2*left.size()*m+mid.length()<<endl;
    for(auto it:left)
        cout<<it;
    cout<<mid;
    reverse(right.begin(),right.end());
    for(auto it:right)
    cout<<it;
    cout<<endl;

    return 0;

}