// Question --> https://www.spoj.com/problems/EKO/
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
#define ll long long int

bool isPossible(vector<ll> T , ll height,ll wood){
    
    ll curr_wood = 0;
    for(auto t:T){

        curr_wood += max(t-height,(ll)0);
    }

    return curr_wood>=wood ? 1 : 0;

}

ll bs( vector<ll> T , ll wood ){

    int n = T.size();
    ll low = INT_MAX;
    ll high = INT_MIN;
    ll ans = 0;
    for(int i=0; i<n; i++) {low = min(low,T[i]); high = max(high,T[i]);}

    while(low<=high){
        ll mid = (low)+(high-low)/2;
        if(isPossible(T,mid,wood)){
            low = mid+1;
            ans = max(mid,ans);
        }
        else{
            high = mid-1;
        }
    }

    return ans;
}

int main(){

    int n; cin>>n;
    ll wood; cin>>wood;
    vector<ll> T;

    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        T.push_back(x);
    }
    cout<<bs(T,wood)<<endl;

}