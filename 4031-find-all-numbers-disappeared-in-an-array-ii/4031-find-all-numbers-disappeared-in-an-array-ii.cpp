class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        set<int> s(nums.begin(), nums.end());
        vector<vector<int>> ans;

        long long start = lower;

        for (int x : s) {
            if (x < lower || x > upper)
                continue;

            if (start < x) {
                ans.push_back({(int)start, x - 1});
            }

            start = (long long)x + 1;
        }

        if (start <= upper) {
            ans.push_back({(int)start, upper});
        }

        return ans;
    }
};