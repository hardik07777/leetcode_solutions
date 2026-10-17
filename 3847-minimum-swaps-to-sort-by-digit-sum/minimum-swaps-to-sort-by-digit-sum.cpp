class Solution {
public:
    int helper(int a) {
        int num = 0;
        while (a > 0) {
            num += a % 10;
            a /= 10;
        }
        return num;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> sorted(n), unsorted(n);

        for (int i = 0; i < n; i++) {
            sorted[i] = {helper(nums[i]), nums[i]};
            unsorted[i] = {helper(nums[i]), nums[i]};
        }

        sort(sorted.begin(), sorted.end());

        unordered_map<int, int> expected, current, index;

        for (int i = 0; i < n; i++) {
            expected[i] = sorted[i].second;
            current[i] = unsorted[i].second;
            index[unsorted[i].second] = i;
        }

        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (current[i] == expected[i]) {
                continue;
            }

            swaps++;

            int x = current[i];
            int j = index[expected[i]];

            current[i] = expected[i];
            current[j] = x;

            index[current[i]] = i;
            index[current[j]] = j;
        }

        return swaps;
    }
};