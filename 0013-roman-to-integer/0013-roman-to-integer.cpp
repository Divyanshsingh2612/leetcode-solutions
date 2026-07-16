class Solution {
public:
    int romanToInt(string s) {
        static int val[91] = {};
        static bool init = [](int* v) {
            v['I'] = 1; v['V'] = 5; v['X'] = 10;
            v['L'] = 50; v['C'] = 100; v['D'] = 500; v['M'] = 1000;
            return true;
        }(val);

        int total = 0, prev = 0;
        for (int i = (int)s.size() - 1; i >= 0; i--) {
            int curr = val[(unsigned char)s[i]];
            total += (curr < prev) ? -curr : curr;
            prev = curr;
        }
        return total;
    }
};