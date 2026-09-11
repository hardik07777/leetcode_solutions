class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_map<int,int>freq;
        int n = digits.size();
        for(int i = 0;i < n; i++){
            freq[digits[i]]++;
        }
        int ans = 0;
        for(int i = 100; i<= 999; i++){
            if(i%2 == 0){
                string b = to_string(i);
                int firstd = b[0] - '0';
                int secondd = b[1] - '0';
                int thirdd = b[2] - '0';
                
                if(freq[firstd] == 0 or (freq[secondd] == 0 or freq[thirdd] == 0)){
                    continue;
                }
                else if(firstd == secondd and firstd == thirdd){
                    if(freq[firstd] >= 3){
                        ans++;
                    }
                }
                else if(firstd == secondd or firstd == thirdd){
                    if(freq[firstd] >= 2){
                        ans++;
                    }
                }
                else if(secondd == thirdd){
                    if(freq[secondd] >= 2){
                        ans++;
                    }

                }
                else{
                    ans++;
                }
            }
        }
        return ans;
       
    }
};