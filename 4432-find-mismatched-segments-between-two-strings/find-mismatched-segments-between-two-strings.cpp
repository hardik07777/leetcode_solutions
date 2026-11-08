class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        vector<vector<string>> ans;
        int n = s1.size();
        int i = 0;
        while(i < n){
            string one = "";
            string two = "";
            vector<string>empty;
            while(i < n and s1[i] != s2[i]){
                one.push_back(s1[i]);
                two.push_back(s2[i]);
                i++;

            }
            if(!one.empty()){
            empty.push_back(one);
            empty.push_back(two);
            ans.push_back(empty);
            }
            i++;
            
            
        }
        return ans;
        
    }
};