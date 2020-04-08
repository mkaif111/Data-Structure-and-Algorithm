#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        int a[n]; 
        int b[n];

        for(int i=0;i<n;i++)
            cin>>a[i];

        for(int i=0;i<n;i++)
            cin>>b[i];

        vector<int> m;
        string ans="YES";

        for(int i=0;i<n;i++){
            if( (a[i] != b[i]) && i==0)
                {
                    ans="NO";
                    break;
                }
            else if( a[i] == b[i] )
                m.push_back(a[i]);
            
            else if( a[i] != b[i] )
            {
                if(a[i]>b[i]){
                    vector<int>:: iterator it = find(m.begin(),m.end(),-1);
                    if(it !=m.end())
                        {ans="NO";
                        break;}
                if(a[i]<b[i]){
                    vector<int>:: iterator  it = find(m.begin(),m.end(),1);
                    if(it!=m.end()){
                        ans="NO";
                        break;
                    }
                }
                }
                
            }
        }

        cout<<ans<<endl;
    }
}