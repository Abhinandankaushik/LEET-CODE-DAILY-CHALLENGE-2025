class Solution {
public:
    int countSubarrays(vector<int>& nums) {

        int i = 0;
        int j = i + 2;
       
        int n = nums.size();
        int count = 0;
        while (j < n) { //T.C : O(n)  & S.C : O(1)
            double sum = (double)(nums[i] + nums[j]);
            count += (((double)nums[j - 1]/2) == sum) ? 1 : 0;
            i++;
            j++;
        }
        return count;
    }
};
