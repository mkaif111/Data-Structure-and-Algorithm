#include<bits/stdc++.h>
using namespace std;

// O(nLogn) + O(N)
int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	// sort basis on arrival time
    	vector<pair<int,char>> train;
    	for(int i=0;i<n;i++){
    	    train.push_back({arr[i],'a'});
    	    train.push_back({dep[i],'d'});
    	}
    	sort(train.begin(),train.end());
    	int count =0;
    	int ans = 1;
        for(auto it:train){
            if(it.second == 'a')
                count++;
            else
                count--;
            ans = max(ans,count);
        }
        
        return ans;
    }