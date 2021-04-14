// https://leetcode.com/problems/permutations-ii/
class Solution {
public:
    void fun(vector<int> nums, set<vector<int>> &s,int index){
        if(index == nums.size()){
            // sort(nums.begin(),nums.end());
            s.insert(nums);
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[i],nums[index]);
            fun(nums,s,index+1);
            swap(nums[index],nums[i]);
        }
        
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        // ans.push_back(nums);
        set<vector<int>> s;
        sort(nums.begin(),nums.end());
        
        fun(nums,s,0);
        bool flag = false;
        for(auto it : s){
            ans.push_back(it);
        }
        // sort(ans.begin(),ans.end());
        
        return ans;
        
    }
};