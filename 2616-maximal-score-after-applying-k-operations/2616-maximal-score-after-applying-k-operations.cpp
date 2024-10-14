class Solution {
    #define ll long long
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<ll> maxheap(nums.begin(),nums.end());

        ll score = 0;
        while(k--){
            ll curr = maxheap.top();
            maxheap.pop();
            score = score + curr;
            curr = ceil((double)curr/3);
            maxheap.push(curr);
        }
        return score;
    }
};