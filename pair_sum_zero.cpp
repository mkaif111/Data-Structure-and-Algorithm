#include <bits/stdc++.h>
using namespace std;
	void PairSum(int *input, int n) {

        sort(input,input+n);
     	unordered_map<int,int> m;
        for (int i=0; i<n;i++){
            if (m.find(-input[i])!=m.end()){
                int x = m[-input[i]];
                while(x--){cout<<-input[i]<<" "<<input[i]<<endl;}
                m[input[i]]++;
            }
            else
            {
               m[input[i]]++;
            }
        }

 	}
