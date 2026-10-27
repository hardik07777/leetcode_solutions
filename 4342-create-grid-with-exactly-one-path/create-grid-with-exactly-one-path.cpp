class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>ans;
        if( m == 1 ){
            string res = "";
            for(int i = 0; i<n; i++){
                res += ".";
            }
            ans.push_back(res);
            return ans;

        }
        if(n == 1){
            string res = ".";
            for(int i = 0; i<m; i++){
                ans.push_back(res);
            }
            return ans;
        }
        string a = ".";
        string b = ".";
        for(int i = 0; i<n-1; i++){
            a += "#";
            b+= ".";
        }
        for(int i = 0; i<m-1; i++){
            ans.push_back(a);


        }
        ans.push_back(b);
        return ans;

        
    }
};