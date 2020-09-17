#include <iostream>
#include <stack>
using namespace std;

void insertBottom(stack<int> & s , int d){
    if(s.empty()){
        s.push(d);
        return ;

    }
    int x = s.top();
    s.pop();
    insertBottom(s,d);
    s.push(x);
    return ;

}

void reverseStack(stack<int> & s){
    if(s.empty()){
        return ;
   }
   int x = s.top();
   s.pop();
   reverseStack(s);
   insertBottom(s , x);
   return ;
}

void transfer(stack<int> &s1 , stack<int> &s2, int n){
    for(int i=0;i<n;i++){
        s2.push(s1.top());
        s1.pop();
    }
}

void revStack(stack<int> &s){
    int n = s.size();
    stack<int> s2;
    for(int i=0;i<n;i++){
        
        int x = s.top();
        s.pop();

        transfer(s , s2, n-1-i);
        s.push(x);
        transfer(s2 , s , n-1-i);
    }
}

int main(){

    stack<int> s1;
    stack<int> s2;
    // cout<<"hell0"<<" ";
    for(int i=0;i<5;i++){
        
        s1.push(i);
    }
    for(int i=5;i<10;i++){
        s2.push(i);
    }

    revStack(s1);
    reverseStack(s2);

    while(!s1.empty()){
        cout<<s1.top()<<" ";
        s1.pop();
    }
    cout<<endl;
    while(!s2.empty()){
        cout<<s2.top()<<" ";
        s2.pop();
    }




}