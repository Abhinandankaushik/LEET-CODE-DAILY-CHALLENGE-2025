class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
         
         int n = grid.size();
         
         int gridSum = 0;
         long long gridSquareSum = 0;

         for(int i = 0 ;i < n ;i++){ //T.C : (n*n)
             
             for(int j = 0 ; j < n ;j ++){
               int val = grid[i][j];
                gridSum += val ;
                gridSquareSum += (val*val);
             }
         }
          
          long long N = n*n;
         long long  sum = (N*(N+1))/2;
         long long  squareSum = (N*(N+1)*(2*N+1))/6;

        int sumDiff = gridSum - sum;
        int SquareDiff = gridSquareSum - squareSum ;

        int a =  (SquareDiff/sumDiff + sumDiff)/2;  //formula derrived from maths baiscs 
        int b =  (SquareDiff/sumDiff - sumDiff)/2;   // S.C : O(1)

        return {a,b};
    }
};
