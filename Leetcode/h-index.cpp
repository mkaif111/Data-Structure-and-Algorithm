
/*

 🌍 https://leetcode.com/problems/h-index/?envType=study-plan-v2&envId=top-interview-150

*/


class Solution {
public:
    int hIndex(vector<int>& citations) {
        // take time to understand ques
        // ques said -> max value  h (which can be max value of element and low value can be 0)
        // such that there is h atleast elements which have atleast h value on it
        sort(citations.begin(),citations.end());
        int n = citations.size();
        for(int i=citations[n-1];i>=1;i--){
            int cnt = 0;
            // this part can be optimises by binary search algorithm
            for(int j=n-1;j>=0;j--){
                if(citations[j]>=i)
                    cnt++;
            }
            if(cnt>=i)
                return i;

        }

        return 0;
    }
};