class Solution {
public:
    vector<vector<int>> factors;

    void getFactors(int x) {
        vector<int> f;

        for (int p = 2; p * p <= x; p++) {
            if (x % p == 0) {
                f.push_back(p);

                while (x % p == 0)
                    x /= p;
            }
        }

        if (x > 1)
            f.push_back(x);

        factors.push_back(f);
    }

    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        factors.clear();

        for (int x : nums)
            getFactors(x);

        unordered_map<int, int> freq;

        int left = 0;
        int distinct = 0;
        int ans = 0;

        for (int right = 0; right < n; right++) {

            for (int p : factors[right]) {
                if (freq[p] == 0)
                    distinct++;

                freq[p]++;
            }

            while (distinct > k) {
                for (int p : factors[left]) {
                    freq[p]--;

                    if (freq[p] == 0)
                        distinct--;
                }

                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};