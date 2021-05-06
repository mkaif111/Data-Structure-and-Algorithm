#include<bits/stdc++.h>
using namespace std;

int findP(vector<int> arr){
    int r = arr.size()-1;
    int l = 0;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(mid + 1<=r and arr[mid]>arr[mid+1])
            return mid;
        if(mid-1>=l and arr[mid-1]>arr[mid])
            return mid-1;
        if(arr[mid]>=arr[l])
            l = mid+1;
        else 
            r = mid-1;
    }
    return -1;
}
int bs(vector<int> v,int k,int l, int r){
    
    while(l<=r){
        int mid = l + (r-l)/2;
        if(v[mid] == k)
            return mid;
        if(v[mid]>k){
            r=mid-1;
        }
        else
            l = mid+1;
            
    }
    
    return -1;
    
}
int Search(vector<int> vec, int K) {
    //code here
    int pIndex = findP(vec);
    // cout<<pIndex<<endl;
    if(pIndex == -1)
        return bs(vec,K,0,vec.size()-1);
    int ans1 = bs(vec,K,0,pIndex);
    if(ans1 != -1)
        return ans1;
    return bs(vec,K,pIndex+1,vec.size()-1);
    
    
}
int main(){

    return 0;
}