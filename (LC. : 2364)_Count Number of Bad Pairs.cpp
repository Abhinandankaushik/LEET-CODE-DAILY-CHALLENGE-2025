class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int,int>map; //S.C : O(n)

        long long bad = 0;

        for(int i = 0 ;i < n ;i++){ // T.C : O(n)

            int dif = i - nums[i];     

            int good =  map[dif] ;

             bad += i - good ;

             map[dif]++;

        }
        return bad;
    }
};
