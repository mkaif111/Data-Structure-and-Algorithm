#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int mah(vector<int> height)
    {
        if (height.size() == 0)
            return 0;
        int n = height.size();

        vector<int> left;
        vector<int> right;

        stack<pair<int, int>> s;
        s.push({height[0], 0});

        left.push_back(-1);

        for (int i = 1; i < n; i++)
        {
            if (s.size() == 0)
                left.push_back(-1);

            else if (s.size() > 0 and s.top().first < height[i])
            {
                left.push_back(s.top().second);
            }

            else
            {
                while (s.size() > 0 and s.top().first >= height[i])
                    s.pop();
                if (s.size() == 0)
                    left.push_back(-1);
                else
                    left.push_back(s.top().second);
            }
            s.push({height[i], i});
        }
        right.push_back(n);
        while (!s.empty())
            s.pop();

        s.push({height[n - 1], n - 1});
        for (int i = n - 2; i >= 0; i--)
        {
            if (s.size() == 0)
                right.push_back(n);
            else if (s.size() > 0 and s.top().first < height[i])
                right.push_back(s.top().second);
            else
            {
                while (s.size() > 0 and s.top().first >= height[i])
                    s.pop();
                if (s.size() == 0)
                    right.push_back(n);
                else
                    right.push_back(s.top().second);
            }
            s.push({height[i], i});
        }

        vector<int> width(n);
        reverse(right.begin(), right.end());
        for (int i = 0; i < n; i++)
            width[i] = right[i] - left[i] - 1;
        int ans = -1;
        for (int i = 0; i < n; i++)
            ans = max(width[i] * height[i], ans);
        return ans;
    }
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (matrix.size() == 0)
            return 0;
        vector<int> height(matrix[0].size());
        int ans = INT_MIN;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] == '0')
                    height[j] = matrix[i][j] - '0';
                else
                    height[j] += matrix[i][j] - '0';
            }

            ans = max(ans, mah(height));
        }

        return ans;
    }
};

int main()
{
    return 0;
}