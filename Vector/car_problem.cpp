#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

class Car{

    public :
    string name;
    int x;
    int y;
    
    Car(){

    }

    Car(string name , int x, int y){
        this->name = name;
        this->y = y;
        this->x = x;

    }

    int dist(){
        return x*x+y*y;
    }

};

bool comp(Car p1 , Car p2){

    int d1 = p1.dist();
    int d2 = p2.dist();

    if(d1==d2){
        return p1.name < p2.name;  // lexicographically sort
    }

    return d1<d2;

}

int main(){

    int n;
    cin>>n;

    // use vector as array

    vector<Car> arr(n,{"",0,0}); // n element has first and second value is 0 .

    for(int i=0;i<n;i++){

        
        cin>>arr[i].name>>arr[i].x>>arr[i].y;

    }

    sort(arr.begin(),arr.end(),comp);

    cout<<"sort vector"<<endl;

    for(auto i:arr){
        cout<<i.name<<" " <<i.x<<" "<<i.y<<" Distance : "<<i.dist()<<endl;

    }







}