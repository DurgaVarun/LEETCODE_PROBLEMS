class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n=nums.size();

        long long valid=0;
        int invalidIndex=-1;
        int minIndex=-1;
        int maxIndex=-1;


        for(int i=0;i<n;i++)
        {
            
            if(nums[i]==minK)
            minIndex=i;

            if(nums[i]==maxK)
            maxIndex=i;


if(nums[i]<minK || nums[i]>maxK)
invalidIndex=i;
            int count = max(min(minIndex,maxIndex)-invalidIndex,0);
            valid+=count;
        }
        return valid;
    }
};