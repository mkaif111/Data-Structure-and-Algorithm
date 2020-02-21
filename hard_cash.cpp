#include<bits/stdc++.h>
using namespace std;


int solution(int arr[], int n , int k){


    int ans = INT_MAX;
    // cout<<ans;



    for(int i=1;i<n;i++)
    // { cout<<i<<" ";
       int c = 0;

      for(int j=0;j<=i;j++){
        c +=arr[j]%k;
        // cout<<c<<" ";

      }


      for(int j =i+1;j<n;j++){
        if (arr[j]%k!=0)
        {
        if(c-(k-arr[j]%k)<0){c=-1;break;}
        else{c-=(k-arr[j]%k);
            // cout<<c<<"this is - "<<" ";
        }
       }
      }


      if (c>=0 && c<ans)
      { ans = c; }




    }


    cout<<endl;

    return ans;
}

int main(){

  int t;
  cin>>t;
  while(t--)
  {
    int n,k;
    cin>>n>>k;

    int divisible =0;

    int* arr = new int[n];
    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
      if (arr[i]%k==0){divisible++;}
    }

    // int ans = ;

    if (divisible==n)
    {

      delete [] arr;
      cout<<'0'<<endl;
    }

    else{
    int v = solution(arr,n,k);

    delete [] arr;
    cout<<v<<endl;}






  }







}
