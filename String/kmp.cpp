#include<bits/stdc++.h>
using namespace std;

int* getPS(string p){

    int len = p.length();
    int *lps = new int[len];

    int i=1;
    int j=0;

    lps[j] = 0;

    while(i<len){
        if(p[i]==p[j]){
            lps[i]=j+1;
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


bool kmp(string text , string pattern){

    int lentex = text.length();
    int lenpat = pattern.length();
    int* lps = getPS(pattern);
    int i=0,j=0;
    while(i<lentex && j<lenpat){
        if(pattern[j]==text[i]){
            i++,j++;
        }
        else{
            if(j!=0){
                j = lps[j-1];
            }
            else{
                i++;
            }
        }
    }

    if(j==lenpat)
        return true;
    return false;

}




int main(){

    string text;
    cin>>text;

    string pat;
    cin>>pat;

    cout<<kmp(text,pat)<<endl;



}