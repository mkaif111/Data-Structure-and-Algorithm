class Solution
{
public:
    int lowerBound(vector<int> nums, int target)
    {
        int l = 0;
        int h = nums.size() - 1;
        while (l <= h)
        {
            int mid = l + (h - l) / 2;
            if (nums[mid] >= target)
                h = mid - 1;
            else
                l = mid + 1;
        }

        return l;
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int lower = lowerBound(nums, target);
        int upper = lowerBound(nums, target + 1) - 1;
        if (lower < nums.size() and nums[lower] == target)
            return {lower, upper};
        else
            return {-1, -1};
    }
};