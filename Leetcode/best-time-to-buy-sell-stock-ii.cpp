/*


https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/?envType=study-plan-v2&envId=top-interview-150

*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int hold_i = 0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<=prices[hold_i]){
                hold_i = i;
            }
            else{
                // check until it is increasing  and increment
                while(i+1<prices.size() and prices[i+1]>=prices[i] and prices[i+1]>=prices[hold_i])
                i++;
                ans += max(0,prices[i]-prices[hold_i]);
                hold_i = i+1;
            }
        }
        return ans;
    }
};




