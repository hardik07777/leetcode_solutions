class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        int j = 0;
        int leftcnt = 0;
        string ans = "";
        for(int i = 0; i<n; i++){
            if(s[i] == '('){
                leftcnt++;
            }
            else{
                leftcnt--;
            }
            if(leftcnt  == 0){
                string x = s.substr(j+1 , i-j-1);
                j = i + 1;
                ans += x;
            
            }
        }
        return ans;
        
    }
};