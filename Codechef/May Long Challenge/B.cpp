#include<bits/stdc++.h>
using namespace std;

#define ll long long int 

int main(){

    int t;
    cin>>t;

    while(t--){
        int n,q;
        cin>>n>>q;

        string s;
        cin>>s;

        map<char,ll> m;

        for(int i=0;i<n;i++){
            char c = s[i];
            if (m.count(c)>0){
                m[c] = m[c] + 1;
            }
            else{
                m[c] = 1;
            }
        }

       

        for(int i=0;i<q;i++){
            long long int c;
            cin>>c;
            ll ans = 0;
            auto it1=m.begin();
            while(it1!=m.end()){
                if(it1->second>1)
                {ans+= max(it1->second-c,(ll)0);}
                it1++;
            }
            if(c==0){ans = s.length();}
            cout<<ans<<endl;
        }
        
    }//end while loop
}