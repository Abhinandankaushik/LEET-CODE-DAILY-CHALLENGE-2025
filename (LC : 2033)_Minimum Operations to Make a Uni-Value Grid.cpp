class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
          
         int n = grid.size();
         int m = grid[0].size();
          
        
         vector<int>arr;
     
         for(auto &it : grid){
            for(auto&i : it){
                arr.push_back(i);
            }
         }

         sort(arr.begin(),arr.end());

         int mid = arr.size()/2;
          
          int ans = 0;
         for(auto& it : arr){
           
          if( it%x != arr[mid]%x ) return -1;

          ans +=  abs(arr[mid]-it)/x ;
           
         }
         return ans;
    }
};
