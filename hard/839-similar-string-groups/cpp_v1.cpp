// Pushed: 2026-08-22 13:30:54 UTC
// Difficulty: Hard
// Runtime: 147 ms
// Memory: 112.6 MB

class Solution {
public:
    vector<int> par;

    int findPar(int i) {
        if (i == par[i]) {
            return i;
        }
        return findPar(par[i]);
    }

    bool isSimilar(string str1, string str2) {
        int count = 0;
        for (int i = 0; i < str1.size(); i++) {
            if (str1[i] != str2[i] && ++count > 2) {
                return false;
            }
        }
        return true;
    }

    int numSimilarGroups(vector<string>& strs) {
        for (int i = 0; i < strs.size(); i++) {
            par.push_back(i);
        }

        int group = strs.size();
        for (int i = 0; i < strs.size(); i++) {
            for (int j = i + 1; j < strs.size(); j++) {
                if (isSimilar(strs[i], strs[j])) {
                    int p1 = findPar(i);
                    int p2 = findPar(j);

                    if (p1 != p2) {
                        par[p1] = p2;
                        group--;
                    }
                }
            }
        }
        return group;
    }
};