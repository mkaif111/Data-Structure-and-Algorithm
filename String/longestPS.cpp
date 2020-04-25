#include<bits/stdc++.h>
using namespace std;

int* getPS(string p){
    int len = p.length();
    int* lps = new int[len];

    lps[0] = 0;
    int j=0;
    int i=1;

    while(i<len){
        if(p[i]==p[j]){
            lps[i] = j+1;
            i++;
            j++;

        }
        else{
            if(j!=0){
                j = lps[i-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

int main(){

    int* arr = getPS("ada");
    for(int i=0;i<3;i++){
        
        cout<<arr[i]<<endl;
    }

}