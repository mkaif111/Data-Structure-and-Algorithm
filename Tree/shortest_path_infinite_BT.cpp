#include<bits/stdc++.h>
using namespace std;

class Solution{   
public:
    int shortestPath( int x, int y){ 
        // code here 
        if(x<y)
            swap(x,y);
        int cnt = 0;
        while(x!=y)
        {
            if(x>y)
                x = x/2;
            cnt++;
            if(y>x)
            {
                y = y/2;
                cnt++;
            }
            
        }
        
        return cnt;
    }
};