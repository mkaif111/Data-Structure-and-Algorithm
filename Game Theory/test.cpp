#include<bits/stdc++.h>
using namespace std;

int mex(unordered_set<int> Set){
    int m=0;

    while(Set.find(m) != Set.end())
        { 
            m++;
            
        }

    return m;
}

int cal_grundy(int n , int grundy[]){
    grundy[0] = 0;
    grundy[1] = 1;
    grundy[2] = 2;
    grundy[3] = 3;
    
    

    if(grundy[n] !=-1){
        return grundy[n];
    }

    unordered_set<int> St;
    St.insert(cal_grundy(n/2,grundy));
    St.insert(cal_grundy(n/3,grundy));
    St.insert(cal_grundy(n/6,grundy));

    grundy[n] = mex(St);

    return grundy[n];


    
}

int main(){


    int n;
    cin>>n;
    int* grundy= new int[n+1];
    for(int i=0; i<=n; i++){
        grundy[i] = -1;
    }
    
    cout<<cal_grundy(n,grundy)<<endl;

}