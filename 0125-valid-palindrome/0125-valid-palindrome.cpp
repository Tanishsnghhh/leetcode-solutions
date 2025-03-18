class Solution {
public:
    bool isPalindrome(string s) {
        string cleanStr = "";
        for (char c : s) if (isalnum(c)) cleanStr += tolower(c);
        int left = 0, right = cleanStr.size() - 1;
        while (left < right) if (cleanStr[left++] != cleanStr[right--]) return false;
        return true;
    }
};
