class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int count=0;
        vector<int> a;
        for(int i=0;i<nums.size();i++){
            if(pivot>nums[i]){
                a.push_back(nums[i]);
            }
            else if(pivot==nums[i]){
                count++;
            }

        }
        for(int i=0;i<count;i++){
            a.push_back(pivot);
        }
        for(int i=0;i<nums.size();i++){
            if(pivot<nums[i]){
                a.push_back(nums[i]);
            }
        }
        return a;
    }
};