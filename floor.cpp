#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        int n,q;
        cin>>n>>q;

        int prev_src,prev_des;
        cin>>prev_src>>prev_des;

        long long int res=0;
        res+= abs(prev_des-prev_src)+ prev_src;
        

        q--;

        while(q--){

            int curr_src,curr_des;
            cin>>curr_src>>curr_des;

            res = res + abs(curr_src - prev_des) + abs(curr_src - curr_des);

            prev_des = curr_des;
            prev_src = curr_src;
            

        }

        cout<<res<<endl;
    }
}