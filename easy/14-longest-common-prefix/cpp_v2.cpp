// Pushed: 2026-10-09 21:01:10 UTC
// Difficulty: Easy
// Runtime: 0 ms
// Memory: 12.1 MB

class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        if (s.empty()) return "";

        sort(s.begin(), s.end());
        string ans = "";
        int i = 0;
        while (i < s[0].length() &&
               i < s[s.size() - 1].length() &&
               s[0][i] == s[s.size() - 1][i]) {
            ans += s[0][i];
            i++;
        }
        return ans;
    }
};