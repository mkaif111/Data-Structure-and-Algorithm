int Solution::searchInsert(vector<int> &A, int B) {
   int l = 0;
   int h = A.size()-1;
   int ans=-1;
   while(l<=h){
       int mid = (l+h)/2;
       if(A[mid]==B){
           ans = mid;
           break;
       }
       if(A[mid]<B){
           ans = mid;
           l = mid+1;
       }
       else{
           h = mid-1;
       }
   }
   
   if(A[ans]==B){
       return ans;
   }
   return ans+1;
}
