class Solution {
public:

   //Approach - 1 : Only Recursion 
    bool isPunishmentNumber(int i, long long sum, string& s, int index ) { 
       
        if(index == s.length())
        return i == sum ;

        if (sum > i)
            return false;
      

        bool ans = false;
        int total = 0;

        for (int j = index; j < s.length(); j++) {
            string st = s.substr(index, j - index + 1);
            total = stoi(st);
            ans = ans || isPunishmentNumber(i, sum + total, s, j + 1);
            if (ans)
                return true;
        }
        return ans;
    } 

    //Apporach - 2 : Rec + Mem
      bool isPunishmentNumberMem(int i,int sum, string& s, int index,vector<vector<int>>& dp) { //S.C :  O(log(n^2))
        

       if(index == s.length())
        return i == sum ; 

        if (sum > i)
         return false;

        if(dp[index][sum] != -1)
        return dp[index][sum] ;

        bool ans = false;
      

        for (int j = index; j < s.length(); j++) {
            string st = s.substr(index, j - index + 1);
             int val  = stoi(st);
            ans = ans || isPunishmentNumberMem(i, sum + val , s, j + 1,dp);
            if (ans)
              return true;
               
        }
       dp[index][sum] = ans;
       return dp[index][sum];
    }
    int punishmentNumber(int n) {

        int punishment_num = 0;
      
        for (int i = 1; i <= n; i++) { //T.C : O(n*2^(log(n^2)))
              
            int sq = i * i;
            string str = to_string(sq);
            vector<vector<int>>dp(str.length() , vector<int>(i+1,-1)); //S.C :  O(n*2^(log(n^2)))

            if (isPunishmentNumberMem(i, 0, str, 0,dp)) {
                punishment_num += sq;
            }
        }
        return punishment_num;
    }
};
