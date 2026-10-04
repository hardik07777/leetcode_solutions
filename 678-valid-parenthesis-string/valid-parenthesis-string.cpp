class Solution {
public:
  int dp[101][101];
    bool helper(string &s , int i , int n , int opencnt){
        if(i == n){
            if(opencnt == 0){
                return true;
            }
            return false;
        }
        if(dp[i][opencnt] != -1){
            return dp[i][opencnt];
        }
        bool left = false;
        bool right = false;
        bool empty = false;
        if(s[i] == '*'){
             left = helper(s , i+1 , n , opencnt +1);
             if(opencnt > 0){
             right = helper(s , i+1 , n , opencnt -1);
             }
             empty = helper(s , i+1 , n , opencnt);
        }
        else if(s[i] == '('){
             left = helper(s , i+1 , n , opencnt +1);

        }
        else{
            if(opencnt > 0){
             right = helper(s , i+1 , n , opencnt -1);
            }
        }
        return dp[i][opencnt] =  (right | ( left | empty));
    }
    bool checkValidString(string s) {
        int n = s.size();
        memset(dp , -1 , sizeof(dp));
        return helper( s , 0 , n , 0);
        
    }
};