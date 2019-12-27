#include<iostream>
using namespace std;

long long merge(int A[],int left , int mid , int right){
  int i=left,j=mid,k=0;

  int temp[right-left+1];
  long long count=0;
  while(i<mid && j<=right)
  {
    if(A[i]<A[j]){
        count += (right-j+1)*A[i];
      temp[k++]= A[i++];

    }
    else{
      temp[k++] = A[j++];

    }
  }
  while(i<mid){
    temp[k++]=A[i++];
  }
  while(j<=right){
    temp[k++]=A[j++];

  }
  for(int i=left,k=0;i<=right;i++,k++){
    A[i] = temp[k];
  }
  return count;


}

long long merge_sort(int A[],int left ,int right){
  long long count=0;
  if(right>left){
    int mid = (left+right)/2;
    long long countleft = merge_sort(A,left,mid);
    long long countright = merge_sort(A,mid+1,right);
    long long my_count = merge(A,left,mid+1,right);
    return my_count + countleft + countright;
  }
  return count;
}


long long solve(int A[],int n){
  long long ans = merge_sort(A,0,n-1);
  return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){cin>>A[i];}

        cout<<solve(A,n)<<endl;
    }

}
