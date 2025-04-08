class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        

        int n = nums.size();

        vector<bool>haveSeen(101,false); //S.C : O(101)

        for(int i = n-1; i >= 0 ;i--){ //T.C : O(n)

              if(haveSeen[nums[i]]){
                return i/3+1;
              }

              haveSeen[nums[i]] = true;
        }

        return 0;
    }
};
