class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers and numbers ending in 0 (except 0 itself) can't be palindromes
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        long reverted = 0;  // long avoids overflow when reverted grows
        while (x > reverted) {
            reverted = reverted * 10 + x % 10;
            x /= 10;
        }

        // Even digit count: x == reverted
        // Odd digit count: middle digit doesn't matter, drop it via reverted / 10
        return x == reverted || x == reverted / 10;
    }
};