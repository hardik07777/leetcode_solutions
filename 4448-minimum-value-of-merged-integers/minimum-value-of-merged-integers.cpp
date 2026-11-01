class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int mini = INT_MAX;
        int n = nums.size();
        for(int i = 0; i < n; i+= 2){
            string first = to_string(nums[i]);
            string second = to_string(nums[i+1]);
            string final = first + second;
             mini = min(mini , stoi(final));
        }
        return mini;
    }
};