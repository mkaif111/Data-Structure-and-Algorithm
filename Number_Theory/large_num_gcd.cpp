#include<iostream>
using namespace std;

int gcd(int a, int b){
    
    return (b==0)?a:gcd(b,a%b);
}

int main(){

    int t;
    cin>>t;
    
    while(t--){
    string s;
    int a;
    cin>>a>>s;
        
    if(a==0){
        for(int i=0;i<s.size();i++){
            cout<<s[i];
        }
        cout<<endl;
        continue;
    }
    
    int sum=0;
    
    for(int i=0;i<s.size();i++){
        sum = ((sum*10)%a + (s[i]-'0')%a)%a;
        
        
    }
    
    cout<<gcd(max(sum,a),min(a,sum))<<endl;
    }
    
	return 0;
}