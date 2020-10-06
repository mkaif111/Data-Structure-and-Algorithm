#include<bits/stdc++.h>
using namespace std;


void moveTower(int n , string start , string finish , string temp,int& count){

    if(n==1){
        cout<<"Moving ring "<<n<<" from "<<start<<" to "<<finish<<endl;
        count++;
        return;

    }
    else{

        moveTower(n-1 , start , temp , finish ,count);
        cout<<"Moving ring "<<n<<" from "<<start<<" to "<<finish<<endl;
        count++;
        moveTower(n-1 ,temp,finish ,start ,count);



    }



}



int main(){

    int n;
    cin>>n;
   
    int count=0;
    moveTower(n,"A","B","C",count);
    // cout<<count<<endl;


}