class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) return "";

        string res = "";
        int remaining = sum;

        for (int i = 0; i < num; i++) {
            int digit = min(9, remaining);  
            res += char(digit + '0');
            remaining -= digit;
        }

        return res;
        
    }
};