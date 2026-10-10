class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long cnt = 0;
        vector<int>pre(1e5 + 1 , 0);
        long long ans = 0;
        for(int i = 0; i<n; i++){
            pre[abs(nums1[i] - nums2[i])]++;
        }
        int k = k1 + k2;
        for(int i = 1e5; i>0 && k > 0; i--){
            int curr_ops = min(pre[i] , k);
            pre[i] -= curr_ops;
            pre[i-1] += curr_ops;
            k-= curr_ops;

        }
        
        for(int j = 0; j<=1e5; j++){
           ans += 1ll * j * j * pre[j];
        }
        
       
        return ans;
        
    }
};