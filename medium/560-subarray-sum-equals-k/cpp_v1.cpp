// Pushed: 2026-10-06 21:31:42 UTC
// Difficulty: Medium
// Runtime: 31 ms
// Memory: 45.6 MB

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sumCountMap;
        sumCountMap[0] = 1;
        int result = 0;
        int prefixSum = 0;
        for (int num : nums)
        {
            prefixSum += num;
            if (sumCountMap.find(prefixSum - k) != sumCountMap.end())
            {
                result += sumCountMap[prefixSum - k];
            }
            sumCountMap[prefixSum]++;
        }
        return result;
    }
};