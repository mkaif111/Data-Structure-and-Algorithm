#include<iostream>
#include<vector>

using namespace std;



int main(){


    vector<int> a;

    vector<int> b(5,10); // -->(size,value);

    vector<int>c(b.begin(),b.end()); // copying the vector

    vector<int> d{1,2,2,2}; //manually initialize

    // Iterate over vector

    //using iterator

    vector<int> :: iterator itr;

    for(itr =b.begin();itr!=b.end();itr++){
        cout<< *itr <<" ";
    }

    cout<<endl;

    for(auto i=c.begin();i!=c.end();i++){
        cout<< (*i) <<" ";
    }
    cout<<endl;

    // using simple loop 

    for(int i=0;i<b.size();i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;

    // automatic iterator 

    for(auto i:c){
        cout<<i<<" ";
    }


    /////////////////////////////// take input push to vector ///////////////////////////////////////////////////


    int n;
    cout<<"Size of vector"<<endl;

    cin>>n;

    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        a.push_back(num);
    }

    cout<<endl;

    for(auto i:a){
        cout<<i<<" ";
    }







    return 0;

}