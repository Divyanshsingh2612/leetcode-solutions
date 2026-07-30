class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int pos[128];
        memset(pos, -1, sizeof(pos));

        int left = 0, ans = 0;

        for (int right = 0; right < s.size(); right++) {
            if (pos[s[right]] >= left)
                left = pos[s[right]] + 1;

            pos[s[right]] = right;

            if (right - left + 1 > ans)
                ans = right - left + 1;
        }

        return ans;
    }
};