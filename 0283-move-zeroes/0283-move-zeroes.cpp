class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() <= 1) 
        {
            return;
        }
        int i=0, j=0;
        while (j < nums.size()) 
        {
            if (nums[j] != 0) 
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
            }
            j++;
        }
    }
};