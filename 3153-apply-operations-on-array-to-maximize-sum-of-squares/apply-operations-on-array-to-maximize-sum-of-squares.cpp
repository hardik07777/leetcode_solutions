class Solution {
public:
    void helper(int a ,  unordered_map<int,int> & freq){
        for(int i = 0; i<32; i++){
            if(((a >> i)&1) == 1){
                freq[i]++;
            }
        }
    }
    int maxSum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>freq;
        for(int i = 0; i<n; i++){
            helper(nums[i] , freq);
        }
        int ans = 0;
        int mod = 1e9 + 7;
        for(int i = 0; i<k; i++){
            int num = 0;
            for(int j = 0; j<32; j++){
                int x = 1;
                if(freq[j] == 0){
                    continue;
                }
                if(j == 0 and freq[0] > 0){
                    num += 1;
                    freq[0]--;
                    continue;
                }
                if(freq[j] > 0){
                    for(int p = 1; p<=j; p++ ){
                        x *= 2;
                    }
                }
                freq[j]--;
                num += x;
            }
            ans = (ans +  ((1ll * num * num) % mod))% mod;


        }
        return ans;
    }
};