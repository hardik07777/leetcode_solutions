class Solution {
public:
    int n;
    int m;
    int dp[1001][1001];
    int helper(int i , int j , string &s , string & t){
        if( j == m){
            return 1;
        }
        if( i == n){
            return 0;
        }
        if(dp[i][j]!= -1){
            return dp[i][j];
        }
        int nottake = helper(i+1 , j , s , t);
        int take = 0;
        if(s[i] == t[j]){
             take = helper(i+1 , j+1, s , t);
        }
        return dp[i][j] =  take + nottake;
    }
    int numDistinct(string s, string t) {
        n = s.size();
        m = t.size();
        memset(dp , -1 , sizeof(dp));
        return helper(0 ,0, s , t);
        
    }
};