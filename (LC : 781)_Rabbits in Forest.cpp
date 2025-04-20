class Solution {
public:
    int numRabbits(vector<int>& answers) {
        
        unordered_map<int,int>mp; //S.C : O(n)
        int ans = 0;
        for(auto& it : answers){ //T.C : O(n)
             
             if(it == 0){
                ans++;
             }
             else if(mp.find(it) == mp.end()){
                ans+=(it+1);
                mp[it]=it;
             }else{
                mp[it]--;
                if(mp[it] == 0)
                mp.erase(it);
             }
             
        }
        return ans;
      
    }
};
