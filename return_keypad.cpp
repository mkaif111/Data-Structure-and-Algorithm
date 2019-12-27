#include <string>
using namespace std;

int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */

    if(num==0 || num==1) {
        output[0]="";
        return 1;
    }
    int small_n = num%10;
    num = num/10;
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


    int count = keypad(num,output);


    //duplicate
    int duplicate =count;
    int index=count;
    while(duplicate<count*s.size()){
        for(int i=0;i<count;i++){
        output[duplicate+i]=output[i];

        }
    duplicate+=index;

    }
    // for(int i=0;i<count*s.size();i++){cout<<"1";}cout<<endl;

    index =0;

    // cout<<count;

    for(int i=0;i<s.size();i++){
        for(int j=0;j<count;j++){
            output[index+j]=output[index+j]+s[i];

            // cout<<output[index];
        }

        index+=count;
    }
    // cout<<endl;


    return s.size()*count;

}
