#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool comp(pair<int,int>p1 , pair<int,int>p2){

    int d1 = p1.first * p1.first + p1.second * p1.second ;
    int d2 = p2.first * p2.first + p2.second * p2.second ;

    if(d1==d2){
        return p1.first<p2.first;
    }

    return d1<d2;

}

int main(){

    int n;
    cin>>n;

    // use vector as array

    vector<pair<int,int>> arr(n,{0,0}); // n element has first and second value is 0 .

    for(int i=0;i<n;i++){

        
        cin>>arr[i].first>>arr[i].second;

    }

    sort(arr.begin(),arr.end(),comp);

    cout<<"sort vector"<<endl;

    for(auto i:arr){
        cout<<i.first<<" "<<i.second<<endl;

    }







}