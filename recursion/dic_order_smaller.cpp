#include<iostream>
#include<string>
#include<set>
using namespace std;

set<string> s;

void dic_order_small(string input, int i){
    if(i == input.length()){
        s.insert(input);
        return;
    }
    for(int j=i;j<input.length();j++){
        swap(input[j],input[i]);
        dic_order_small(input,i+1);
        swap(input[i],input[j]);
    }
    return;
}

int main(){
    string input; cin>>input;
    dic_order_small(input,0);
    for(auto str: s){
        if(str == input){
            break;
        }
        cout<<str<<"\n";
    }
    
}