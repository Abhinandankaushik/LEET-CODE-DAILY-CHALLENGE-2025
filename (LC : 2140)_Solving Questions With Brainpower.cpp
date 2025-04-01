class Solution {
public:
      
      //Rec + Mem
    unordered_map<long long , long long >mp;
    long long solve(vector<vector<int>>& questions , int index ){

         if(index >= questions.size()) return 0;
         
         if(mp.find(index) != mp.end())
         return mp[index];
      
         long long inc = questions[index][0] + solve(questions, index + questions[index][1]+1 );
        
         long long exc = solve(questions, index+1);

         mp[index] = max(inc,exc);
         return mp[index];
    }

     //Bottum up dp 
      long long Tabulation(vector<vector<int>>& questions ){
          
          int n = questions.size();
          vector<long long> dp(n+1,0);

         for(int index = n-1 ; index >= 0 ;index--){
         
         long long inc = questions[index][0] + (index + questions[index][1]+1 >= n ? 0 : dp[index + questions[index][1]+1] );
        
         long long exc = dp[index+1];

         dp[index] = max(inc,exc);
        
         }  

         return dp[0];
         
    }
  
    long long mostPoints(vector<vector<int>>& questions) {
        // return solve(questions,0);
        return Tabulation(questions);

    }
};
