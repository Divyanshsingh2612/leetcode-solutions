class Solution {
public:
    bool isValid(string s) {
        if (s.length() % 2 != 0) return false;   // fail fast

        unordered_map<char, char> pairs = {
            {')', '('}, {']', '['}, {'}', '{'}
        };
        stack<char> st;

        for (char ch : s) {
            if (pairs.count(ch)) {                // closing bracket
                if (st.empty() || st.top() != pairs[ch]) return false;
                st.pop();
            } else {                              // opening bracket
                st.push(ch);
            }
        }

        return st.empty();
    }
};