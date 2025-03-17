class Solution {
public:
    bool divideArray(vector<int>& nums) {
         
         unordered_map<int,int>mp; //S.C : O(n)

         for(int i = 0 ; i < nums.size() ;i++){ //T.C : O(n)
             mp[nums[i]]++;
         }

         for(auto it : mp){
            if(it.second % 2 != 0) 
            return false;
         }

         return true;
    }
};
