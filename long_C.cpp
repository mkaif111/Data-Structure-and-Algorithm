#include <bits/stdc++.h>
using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n){
    unordered_map<int, bool> ump;
    for(int i=0;i<n;i++)
    {
        ump[arr[i]] = true;
    }
    int maxlength=1,start=arr[0],end=arr[0];
    //int last_start_index,current_start_index;
    for(int i=0;i<n;i++)
    {
        if(ump.find(arr[i]-1) == ump.end())
        {
            int currlength=1;
            //ump[arr[i]] = false;
            int t=arr[i]+1;
            int q=arr[i]-1;
            while(true)
            {
                if(ump.find(t) != ump.end() )//&& ump[t]!=false)
                {
                    //ump[t]=false;
                    currlength+=1;
                    t+=1;

                }
                else
                {
                    break;
                }
            }

            if(currlength > maxlength)
            {
                maxlength=currlength;
                start = q+1;
                end=t-1;

                //last_start_index = index[q+1];
            }

        }
    }
    vector<int>ans;
    for(int i=start;i<=end;i++)
    {
        ans.push_back(i);
    }
    return ans;
}
