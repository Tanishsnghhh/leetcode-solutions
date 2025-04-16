class Solution {
public:
    int strStr(string str, string target) {
        int n = str.length();
        int m = target.length();

        for (int i = 0; i <= n - m; i++) {
            for (int j = 0; j < m; j++) {
                if (str[i + j] != target[j]) {
                    break;
                }
                if (j == m - 1) {
                    return i; 
                }
            }
        }
        return -1; 
    }
};
