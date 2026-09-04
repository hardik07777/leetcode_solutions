class Solution {
public: 
    int n;
    int dp[1001][1001];
    int helper(int left , int right , vector<vector<int>> & pair){
        if(right >= n){
            return 0;
        }
        if(left != -1 and dp[left][right] != -1){
            return dp[left][right];

        }
        int nottake = helper(left , right +1 , pair);
        int take = 0;
        if(left == -1 or pair[right][0] > pair[left][1]){
            take = 1 + helper(right , right +1 , pair);

        }
        if(left != -1){
            dp[left][right] = max(take , nottake);
        }
        return  max(nottake , take);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin() , pairs.end());
        n = pairs.size();
      memset(dp , -1 , sizeof(dp));
        int x =  helper(-1 , 0 , pairs);
       
        return x;
        
    }
};