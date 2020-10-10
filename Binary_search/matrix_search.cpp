int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    // cout<<B<<endl;
    int m = A[0].size()-1;
    for(int i=0;i<A.size();i++){
        int l = 0;
        int h =m;
        
        while(l<=h){
            
            int mid = (l+h)/2;
            // cout<<A[i][mid]<<" mid "<<mid<<" ";
            if(A[i][mid] == B)
                {return 1;}
            if(A[i][mid]<B){
                l = mid+1;
            }
            else{
                h = mid-1;
            }
        }
    }
    return 0;
    
}
