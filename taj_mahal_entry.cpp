#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    int ans[n];
    int val=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if((arr[i]-1)%n!=0 && arr[i]-i>0){
            val = (arr[i]-1)/n + 1;
        }
        else{
            val = (arr[i]-1)/n;
        }
        ans[i] = i+ val*n;
    }
    int index;
    index = 0;
    for(int i=1;i<n;i++)
    {
        if(ans[i]<ans[index])
        {
            index = i;
            // cout<<index<<endl;
        }
    }

    cout<<index+1<<endl;;

	return 0;
}
