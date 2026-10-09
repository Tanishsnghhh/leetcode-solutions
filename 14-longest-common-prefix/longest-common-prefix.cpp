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