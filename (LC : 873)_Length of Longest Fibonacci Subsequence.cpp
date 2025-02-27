class Solution {
public:
   unordered_map<int,int>mp;
     
     int solve(int i , int j , vector<int>& arr){

          int sum = arr[i] + arr[j];
         if(mp.find(sum) != mp.end()){

            return 1 + solve(j , mp[sum],arr);
         }

         return 2;
     }

    int lenLongestFibSubseq(vector<int>& arr) {
        
        int n = arr.size();
        for(int i = 0 ;i < n ;i++){
            mp[arr[i]] = i;
        }
        
        int ans = 0;
        for(int i = 0 ;i  < n -1;i++){
             for(int j = i+1 ; j < n;j++){

                 int len = solve(i,j,arr);
                 if(len >= 3){
                    ans = max(ans , len);
                 }
             }
        }
        return ans;
    }
};
