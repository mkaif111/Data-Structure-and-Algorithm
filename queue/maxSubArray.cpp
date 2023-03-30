#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void maxSubArray(vector<int> arr,int k){
    deque<int> q(k);
    int i;
    int n = arr.size();
    for(i=0;i<k;i++){
        while(!q.empty() and arr[q.front()]<arr[i])
            q.pop_back();
        q.push_back(i);
    }
    for(;i<n;i++){
        cout<<arr[q.front()]<<" ";
        // remove which is not in k window (i-k because i is 0 index K is 1 index )
        while(!q.empty() and q.front()<= i-k)
            q.pop_front();
        while(!q.empty() and arr[q.front()]<=arr[i])
            q.pop_back();
        q.push_back(i);
    }
    cout<<arr[q.front()]<<" ";
}

int main(){
    int n; cin>>n;
    int k; cin>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    } 
    maxSubArray(arr,k);
    return 0;

}
