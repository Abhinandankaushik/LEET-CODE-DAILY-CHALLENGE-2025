class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
         
         unordered_map<int,int>mp; //S.C : O(n)

         for(auto &it : nums){ //T.C : O(n)
            
            if(it < k) return -1;
            
            if(it > k)
             mp[it]++;
         }
            
       
         return mp.size();
    }
};
