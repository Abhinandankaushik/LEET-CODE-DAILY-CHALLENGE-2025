class Solution {
public:
    string triangleType(vector<int>& nums) {

        map<int, int> mp;

         int sum = 0 ;
         sum = nums[0]+nums[1]+nums[2];

         for(int i = 0 ; i< 3 ;i++){ //T.C : O(1)  , S.C : O(1) --> lenght of nums always == 3
              
              if(nums[i] >= sum-nums[i]){
                return "none";
              }
              mp[nums[i]]++;
         }

        if (mp.size() == 1) {
            return "equilateral";
        } else if (mp.size() == 2) {
            return "isosceles";
        }

        

        return "scalene";
    }
};
