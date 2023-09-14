/*

https://leetcode.com/problems/majority-element-ii/

*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
    
        for(int i =0 ;i<nums.size();i++){
            int curr = i;
            
            while(i+1<nums.size() and nums[i+1] == nums[curr]){
                i++;
            }
            if(i-curr + 1>nums.size()/3)
                ans.push_back(nums[curr]);
        }

        return ans;
    }
};