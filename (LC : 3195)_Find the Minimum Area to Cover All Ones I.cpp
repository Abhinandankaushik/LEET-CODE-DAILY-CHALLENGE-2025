class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        
        int fr = INT_MAX , fc = INT_MAX , lr = INT_MIN ,lc = INT_MIN;

        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0 ;i < m ;i++){  //T.C : O(m*n)
            for(int j = 0 ;j < n ;j++){
                  
                  if(grid[i][j] == 1){
                    fr = min(fr,i);
                    lr = max(lr,i);
                    fc = min(fc,j);
                    lc = max(lc,j);
                  }
            }
        }

        int row = (lr-fr+1);
        int col = (lc-fc+1);
        return (row*col);
    }
};
