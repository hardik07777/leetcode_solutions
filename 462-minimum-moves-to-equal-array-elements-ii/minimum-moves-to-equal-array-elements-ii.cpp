class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin() , nums.end());
        int cnt = 0;
        int idx = n/2;
        for(int i = 0; i<n; i++){
            cnt += abs(nums[idx] - nums[i]);
        }
        return cnt;
    }
};