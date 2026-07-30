class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int lastSeen[128];

        for (int i = 0; i < 128; i++)
            lastSeen[i] = -1;

        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < s.size(); right++) {
            left = max(left, lastSeen[s[right]] + 1);
            lastSeen[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};