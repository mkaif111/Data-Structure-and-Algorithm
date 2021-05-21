class Solution
{
public:
    int findSubArraySum(int Arr[], int N, int k)
    {
        // code heret
        unordered_map<int, int> m;
        int cnt = 0;
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            sum += Arr[i];
            if (sum == k)
                cnt++;
            if (m.find(sum - k) != m.end())
                cnt += m[sum - k];

            m[sum]++;
        }

        return cnt;
    }
};