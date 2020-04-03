#include<bits/stdc++.h>
using namespace std;


void moveTower(int n , string start , string finish , string temp,int& count){

    if(n==1){
        cout<<start<<" --> "<<finish<<endl;
        count++;
        return;

    }
    else{

        moveTower(n-1 , start , temp , finish ,count);
        cout<<start<<" --> "<<finish<<endl;
        count++;
        moveTower(n-1 ,temp,finish ,start ,count);



    }



}



int main(){

    int n;
    cin>>n;
    cout<<endl;

    string A,B,C;
    cout<<"start "<<" finish "<<"temp"<<endl;

    cin>>A>>B>>C;
    int count=0;
    moveTower(n,A,B,C,count);
    cout<<count<<endl;


}