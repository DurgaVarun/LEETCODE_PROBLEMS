class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int min=nums[0];
        for(int i=1;i<nums.size();i++){
            if(abs(min)>abs(nums[i]) || abs(min)==abs(nums[i]) && nums[i]>min){
                min=nums[i];
            }
        }
        return min;
    }
};