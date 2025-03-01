class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {

        int n = nums.size();
        for (int i = 0; i < n; i++) { //T.C : O(n)

            if (i + 1 < n && nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        int i = 0, j = 1;
       
       //Using Two - Pointer to mentain order of numbers 
        while (i < n && j < n) { //T.C : O(n)
 
            if (nums[i] == 0 && nums[j] != 0) {
                swap(nums[i], nums[j]);
                i++;
                j++;
            } else if (nums[i] == 0 && nums[j] == 0) {
                j++;
            } else {
                i++;
                j++;
            }
        }

        //overal T.C : O(2*n) --> O(n)
        // S.C : O(1)
        
        return nums;
    }
};
