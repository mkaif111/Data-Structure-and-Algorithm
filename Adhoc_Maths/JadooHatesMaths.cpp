#include<bits/stdc++.h>
using namespace std;
bool check(int n){
    if(n%3 == 0)
        return false;
    while(n>0){
        if(n%10 == 3)
            return false;
        n = n/10;
    }

    return true;
}
int main(){
    int n; cin>>n;
    n++;
    while(true){
        if(check(n)){
            cout<<n<<endl;
            break;
        }
        n++;
    }
}