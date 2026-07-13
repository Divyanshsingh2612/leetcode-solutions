class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);                 // opening bracket
            } else {
                if (st.empty()) return false; // closing bracket
                char top = st.top();
                st.pop();
                if ((ch == ')' && top != '(') ||
                    (ch == ']' && top != '[') ||
                    (ch == '}' && top != '{')) {
                    return false;             
                }
            }
        }

        return st.empty();
    }
};