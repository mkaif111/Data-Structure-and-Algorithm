class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> num3 ;
        int i=0,j=0;
        while(i<nums1.size() and j<nums2.size()){
        	if(nums1[i]<nums2[j]){
        		num3.push_back(nums1[i]);
        		i++;
        	}
        	else{
        		num3.push_back(nums2[j]);
        		j++;
        	}
        }

        while(i<nums1.size()){
        	num3.push_back(nums1[i]);
        	i++;
        }
        while(j<nums2.size()){
        	num3.push_back(nums2[j]);
        	j++;
        }

        i = 0;
        for(auto it:num3)
        	nums1[i] = it;
    }
};