// https://codeforces.com/problemset/problem/1513/A
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int k; cin>>k;
        vector<int> ans(n+1);
        int num = n;
        for(int i=2;i<n;i+=2){
            if(!k) break;
            ans[i] = num--;
            k--;
        }
        if(k){
            cout<<-1<<endl;
        }
        else{
            int curr = 1;
            for(int i=1;i<=n;i++){
                if(ans[i] == 0)
                    ans[i] = curr++;
                cout<<ans[i]<<" ";
            }
            cout<<endl;
            
        }
    }
}