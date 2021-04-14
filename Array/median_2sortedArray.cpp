class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> arr;
        int i=0;
        int j=0;
        
        while(i<n and j<m){
            if(nums1[i]<nums2[j]){
                arr.push_back(nums1[i]);
                i++;
            }
            else{
                arr.push_back(nums2[j]);
                j++;
            }
        }
        
        for(;i<n;i++){
            arr.push_back(nums1[i]);
        }
        for(;j<m;j++){
            arr.push_back(nums2[j]);
        }
        
        for(auto it: arr){
            cout<<it<<" ";
        }
        cout<<endl;
        int N = arr.size();
        cout<<N<<endl;
        if(N%2==0){
            cout<<arr[N/2]<<" "<<arr[N/2 -1]<<endl;
            double ans = (arr[N/2] + arr[N/2 - 1]);
           cout << setprecision(5) << ans << '\n';
            return ans/2;
        }
        return arr[N/2];
    }
};