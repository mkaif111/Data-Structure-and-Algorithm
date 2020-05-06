#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int,int> a , pair<int,int> b){
    if(a.first == b.first)
        return a.second < b.second;
    return a.first<b.first;
}

double dis(pair<int,int> x , pair<int,int> y){
    int x1 = x.first;
    int x2 = y.first;
    int y1 = x.second;
    int y2 = y.second;

    return sqrt(abs(x1-x2)*abs(x1-x2) + abs(y1-y2)*abs(y1-y2));
}

int main(){

    int n;
    cin>>n;

    pair<int,int> p[n];
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        p[i].first = x;
        p[i].second = y;
    }

    sort(p,p+n,comp);
    double d =0;
    for(int i=0;i<n;i++){
        
        cout<<p[i].first <<" ";
        cout<<p[i].second<<" ";
    }
    cout<<endl;
    for(int i=0;i+1<n;i=i+=2){

        d+= dis(p[i],p[i+1]);
        

    }

    cout<<d<<endl;


}