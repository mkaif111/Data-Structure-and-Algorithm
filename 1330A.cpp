#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--)
    {
    int n,x;
    cin>>n>>x;
    unordered_set<int> s;
    for(int i=0;i<n;i++)
    {   int y;
        cin>>y;
        s.insert(y);
    }
    int count=1;
    while(x>0){
        if (s.find(count)==s.end()){
            x--;
        }
        count++;
    }
    while(s.find(count)!=s.end()){
        count++;
    }

    cout<<count-1<<endl;
    
    
    
    }

}