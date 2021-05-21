class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {

        int ans = 0;
        unordered_map<int, int> m;
        int sum = 0;
        m[0] = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            sum = (sum + nums[i]) % k;
            sum = (sum + k) % k;
            ans += m[sum];
            m[sum]++;
        }

        return ans;
    }
};