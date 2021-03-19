 int pivotElement(vector<int> nums){
        int l = 0;
        int r = nums.size()-1;
        
        while(l<=r){
            int mid = (l+r)/2;
            if(mid>l and nums[mid]<nums[mid-1])
                return mid;
            if(mid<r and nums[mid]>nums[mid+1])
                return mid+1;
            if(nums[mid]>=nums[l])
                l = mid+1;
            else
                r = mid-1;
        }
        return -1;
    }
    int findMin(vector<int>& nums) {
        int pivot = pivotElement(nums);
      
        
        return (pivot!=-1)?nums[pivot]:nums[0];
    }