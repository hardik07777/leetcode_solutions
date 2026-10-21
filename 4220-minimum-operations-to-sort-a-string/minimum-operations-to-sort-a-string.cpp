class Solution {
public:
    int minOperations(string s) {
        string temp = s;
        int n = s.size();
        sort(temp.begin() , temp.end());
        if(s== temp){
            return 0;
        }
        if(s.size() == 2 and s != temp){
            return -1;
        }
        if(s[0] == temp[0] or s[n-1] == temp[n-1]){
            return 1;
        }
        int mn = temp[0];
        int maxi = temp[n-1];
        int cntmn = 0;
        int cntmaxi = 0;
        for(int i = 0; i<n; i++){
            if(s[i] == mn){
                cntmn++;
            }
            if(s[i] == maxi){
                cntmaxi++;
            }
        }
        if(s[0] == maxi and s[n-1] == mn){
            if(cntmn == 1 and cntmaxi == 1){
            return 3;
            }
        }
        return 2;
    }
};