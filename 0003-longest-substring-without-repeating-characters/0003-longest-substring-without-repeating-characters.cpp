class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastIndex;

        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < s.length(); right++) {

            // Character already exists in current window
            if (lastIndex.count(s[right]) && lastIndex[s[right]] >= left) {
                left = lastIndex[s[right]] + 1;
            }

            // Store latest position
            lastIndex[s[right]] = right;

            // Update answer
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};