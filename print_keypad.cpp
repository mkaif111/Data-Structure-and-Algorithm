#include <iostream>
#include <string>
using namespace std;

void print_s(int num, string output){

    if(num==0){
        cout<<output<<endl;
        return;
    }

  int small_n = num%10;
    string s;
    if (small_n==2){
     s = "abc";

    }
    else if(small_n==3){ s = "def";}
    else if(small_n==4){s = "ghi";}
    else if(small_n==5){s = "jkl";}
    else if(small_n==6){s = "mno";}
    else if(small_n==7){ s= "pqrs";}
    else if(small_n==8){s = "tuv";}
    else if(small_n==9){s = "wxyz";}

    for(int i=0;i<s.size();i++){
        // cout<<s[i]+output<<"--"<<endl;
        print_s(num/10,s[i]+output);
    }
    return;

}
void printKeypad(int num){
    print_s(num,"");





}
