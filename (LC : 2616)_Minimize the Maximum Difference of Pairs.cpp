class Solution {
public: 

   int find(vector<int>&nums, int t){

       int count = 0;

       for(int i = 0  ; i < nums.size() -1;){

            if(nums[i+1] - nums[i] <= t)
            {
                count++;
                i++;
            }
            i++;
       }

       return count;
   }
    int minimizeMax(vector<int>& nums, int p) {

        sort(nums.begin(), nums.end());
        int n = nums.size();

        int s = 0;
        int e = nums[n - 1] - nums[0];

       

        while (s < e) {

            int mid = (s + e) / 2;

            if (find(nums,mid) >= p) {
                e = mid;
            } else {
                s = mid + 1;
            }
        }

        return s;
    }
};
