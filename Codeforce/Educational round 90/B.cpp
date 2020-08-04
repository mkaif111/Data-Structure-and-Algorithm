#include<iostream>
#include<string>
using namespace std;
int count_d(string s, int count){
    if (s.length()<=1){
        return count;
    }
    if(s[0]!=s[1]){
        return count_d(s.substr(1,s.length()),count+1);
    }

    
    
}

int main(){
    int t;
    cin>>t;

    while(t--){
        string s;
        cin>>s;
        int i=0;
        int count=0;
        while(i<s.length()){
            if(s[i]!=s[i+1]){
                count++;
                i+=2;
            }
            else{
                i++;
            }
            if (i==s.length()-1){
                break;
            }
        }

        if(count%2==0){
            cout<<"NET"<<endl;
        }
        else{
            cout<<"DA"<<endl;
        }
    }
}