// Pushed: 2026-08-27 21:25:21 UTC
// Difficulty: Easy
// Runtime: 0 ms
// Memory: 9.7 MB

class Solution {
public:
    bool isPalindrome(string s) {

        int left = 0;
        int right = s.length() - 1;

        while (left < right) {

            // Left side se special character skip karo
            if (!isalnum(s[left])) {
                left++;
                continue;
            }

            // Right side se special character skip karo
            if (!isalnum(s[right])) {
                right--;
                continue;
            }

            // Dono characters ko compare karo
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            // Next characters par jao
            left++;
            right--;
        }

        return true;
    }
};