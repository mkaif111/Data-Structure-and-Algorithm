/*
https://leetcode.com/problems/rotate-array/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
public:
    void reverse(int l, int r, vector<int>& nums){
        while(l<=r){
            swap(nums[l],nums[r]);
            l++;
            r--;
        }
    }
    void print_arr(vector<int> arr){
        for(auto it:arr)
            cout<<it<<" ";
        cout<<endl;
    }
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        // cout<<k<<endl;
        reverse(nums.size()-k,nums.size()-1,nums);
        // print_arr(nums);
        reverse(0,nums.size()-k-1,nums);
        // print_arr(nums);
        reverse(0,nums.size()-1,nums);
        // print_arr(nums);
    }
};