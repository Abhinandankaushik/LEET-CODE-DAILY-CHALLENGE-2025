class Solution {
public:
    int maxDifference(string s) {
        
        map<int,int>mp;
        for(auto&it : s)
        mp[it]++;

        int a1 = 0, a2 = INT_MAX;

        for(auto&it : mp){
             
             if(it.second&1){
                a1 = max(a1,it.second);
             }
             else {
                a2 = min(a2,it.second);
             }
        }

        

        return a1-a2;
    }
};
