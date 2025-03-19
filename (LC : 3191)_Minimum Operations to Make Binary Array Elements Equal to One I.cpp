class Solution {
public:
    int minOperations(vector<int>& nums) {
       
       int n = nums.size();
       queue<int>q;  //S.C : O(3) --> O(1)
        int flipCount = 0;
        int ans = 0;
       for(int i = 0 ;i < n ;i++){  //T.C : O(n)
           
           if(!q.empty() && i >= 3 && q.front() == 1){
            flipCount--;
             q.pop();
           }

           if( flipCount%2 == nums[i]){
                ans++;
                flipCount++;
               if(i+3 > n) return -1;
                q.push(1);
           }
           else q.push(0);

           if(q.size() > 3) q.pop();
       }

       return ans;
    }
};
