#include <bits/stdc++.h>
using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n){
	//Your Code goes here
    int max_length,start;
    max_length=0;
    start = arr[0];

    unordered_map<int,bool> m ;
    unordered_map<int,int> index;

    // int indx = 0;
    for(int i=0;i<n;i++){m[arr[i]] = true; index[arr[i]]=i;}
    int curr_max=0;
    int st=arr[0];
    for(int i=0;i<n;i++){
        curr_max=0;
        int j=1;
        while(m[arr[i]]){
            if (m.find(arr[i]+j)!=m.end()){curr_max++;
                                           m[arr[i]+j] = false;
                                          st=arr[i];
                                          j++;
                                           }
            else{ break;}

        }
        j=1;
         while(m[arr[i]]){
            if (m.find(arr[i]-j)!=m.end()){curr_max++;
                                           m[arr[i]-j] = false;
                                          st=arr[i]-j;
                                          j++;}
            else{ break;}

        }
        m[arr[i]]=false;
        if (curr_max>max_length){max_length=curr_max;start=st;}
        else if (curr_max==max_length){if (index[start]>st) max_length = curr_max; start = st;}


    }
    // cout<<"this is start"<<start<< "this is length" <<max_length<<endl;



    vector<int>v;
    int i=start;
    while(i<=start+max_length){v.push_back(i);i++;}
    // cout<<start<<" "<<max_length;

    return v;



}
