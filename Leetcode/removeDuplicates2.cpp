/*
👇
https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/submissions/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // track length of desired duplicates
        int k = 0;
        for(int i=0;i<nums.size();i++){
            int cnt = 1;
            int temp = nums[i];
            while(i+1<nums.size() and nums[i+1] == temp )
                {
                    i++;
                    cnt++;
                }
            // increment twice as we need 2 duplicate of element
            nums[k++] = temp;
            if (cnt>1)
                nums[k++] = temp;
            

        }

        return k;
    }
}    