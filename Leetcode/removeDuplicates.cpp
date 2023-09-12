class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // track unique element
        int k = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i] == nums[k]){
                // increment i till it other unique element found
                while(i+1<nums.size() and nums[i+1] == nums[k]) i++;

            }
            else{
                // increment k to next unique element index
                nums[++k] = nums[i];
            }
        }

        return k+1;
    }
};