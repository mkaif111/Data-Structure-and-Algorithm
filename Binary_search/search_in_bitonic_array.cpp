int asc_bs(vector<int> A , int low , int high,int key){
    
    while(low<=high){
        int mid = (low+high)/2;
        if(A[mid]==key)
            return mid;
        if(A[mid]>key)
            high = mid-1;
        else
            low = mid+1;
    }
    return -1;
}

int des_bs(vector<int> A, int low, int height ,int key){
    while(low<=high){
        int mid = (low+high)/2;
        if(A[mid]==key)
            return mid;
        if(A[mid]<key)
            high = mid-1;
        else
            low = mid+1;
    }
    return -1;
}

int findpivot(vector<int> arr){
    int n = arr.size();
    int low = 0;
    int high = n-1;
    
    while(low<=high){
        if(arr[mid]>arr[low] and arr[mid]<arr[mid-1])
            return mid-1;
        if(arr[mid]>arr[high] and arr[mid]>arr[mid+1])
            return mid;
        if(arr[mid]>=arr[low])
            low = mid+1;
        else
            high = mid-1;
    }
    
    return -1;
}

int Solution::solve(vector<int> &A, int B) {
    
    int n = A.size();
    int h = n-1;
    int l = 0;
    int idx = findpivot(A);
    if(idx==-1){
        return asc_bs(A,0,n-1,B);
    }
    else{
        int t = asc_bs(A,0,indx-1,B);
        if(t!=-1)
            return t;
        return des_bs(A,indx+1,n-1,B);
            
    }
    
}
