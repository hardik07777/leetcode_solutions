
class Solution {
public:
    int minInsertions(string s) {
        int cnt = 0;
        int n = s.size();
        int i = 0;
        int result = 0;

        while (i < n) {
            if (s[i] == ')') {
                if (cnt > 0) {
                    if (i + 1 < n && s[i + 1] == ')') {
                        cnt--;
                        i += 2;
                    } else {
                        result++;
                        cnt--;
                        i++;
                    }
                } else {
                    if (i + 1 < n && s[i + 1] == ')') {
                        result++;
                        i += 2;
                    } else {
                        result += 2;
                        i++;
                    }
                }
            } else {
                cnt++;
                i++;
            }
        }

        result += 2 * cnt;
        return result;
    }
};
