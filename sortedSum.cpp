#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

int mod = 1000000007;
int sol(vector<int> arr){

    int sum = 0;
    for(int i=0;i<arr.size();i++){
        int n = i+1;
        int N = (n*(n+1))/2;
        sum = (sum%mod + (arr[i]%mod)*(N%mod)) % mod;
    }

    return sum;

}

int main(){

    int n; cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    sort(arr.begin(),arr.end());

    int sum = sol(arr);
    cout<<sum<<endl;
}