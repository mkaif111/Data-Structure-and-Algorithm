#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int minSwaps(int* arr, int n) 
{ 
	// Create an array of pairs where first 
	// element is array element and second element 
	// is position of first element 
	pair<int, int> arrPos[n]; 
	for (int i = 0; i < n; i++) 
	{ 
		arrPos[i].first = arr[i]; 
		arrPos[i].second = i; 
	} 

	// Sort the array by array element values to 
	// get right position of every element as second 
	// element of pair. 
	sort(arrPos, arrPos + n); 

	// To keep track of visited elements. Initialize 
	// all elements as not visited or false. 
	vector<bool> vis(n, false); 

	// Initialize result 
	int ans = 0; 

	// Traverse array elements 
	for (int i = 0; i < n; i++) 
	{ 
		// already swapped and corrected or 
		// already present at correct pos 
		if (vis[i] || arrPos[i].second == i) 
			continue; 

		// find out the number of node in 
		// this cycle and add in ans 
		int cycle_size = 0; 
		int j = i; 
		while (!vis[j]) 
		{ 
			vis[j] = 1; 

			// move to next node 
			j = arrPos[j].second; 
			cycle_size++; 
		} 

		// Update answer by adding current cycle. 
		if (cycle_size > 0) 
		{ 
			ans += (cycle_size - 1); 
		} 
	} 

	// Return result 
	return ans; 
}

int main(){

    freopen("output.txt", "w", stdout);

    int t;
    scanf("%d",&t);

    while(t--){
        int n,k;
        scanf("%d %d",&n,&k);
        int * arr = new int[n];

        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);

        }
        int * drr = arr;
        
        vector<pair<int,int>> p;
        for(int i=0;i<k;i++){
            int x,y;
            cin>>x>>y;
            x--;
            y--;
            p.push_back(make_pair(x,y));

            if(arr[x]>arr[y]){
                int temp = arr[x];
                arr[x] = arr[y];
                arr[y] = temp; 
            }


        }
        // cout<<count2<<endl;
        // cout<<count<<endl;

        // for(int i=0;i<n;i++){
        //     cout<<arr[i]<<" ";
        // }

        // cout<<endl;
        int ans = minSwaps(drr,n);
        int ans1 = minSwaps(arr,n);

        cout<<min(ans,ans1)<<endl;
        
    }//  while loop end

    return 0;
}