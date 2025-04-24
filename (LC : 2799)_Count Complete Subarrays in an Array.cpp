class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {

        set<int> st; //S.C : O(n)
        for (auto& it : nums) { //T.c : O(n*log(n))
            st.insert(it);
        }
        int n = nums.size();
        map<int, int> mp;
        int ans = 0;

        int i = 0, j = 0;
        int count = 0 ;
        while (j < n) {
         
         mp[nums[j]]++;

         while( mp.size() == st.size()){
            ans +=(n-j);
            mp[nums[i]]--;
            if(mp[nums[i]] == 0){
                mp.erase(nums[i]);
            }
            i++;
         }
         j++;
        }
        return ans;
    }
};
