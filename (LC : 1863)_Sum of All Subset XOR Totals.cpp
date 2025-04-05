//Optimal Backtracking Code :-

class Solution {
public:
     
     void solve(vector<int>& nums , int index , int & totalSum , int XORSUM){

         if(index == nums.size()){
            totalSum += XORSUM;
            return;
         }
         solve(nums,index+1,totalSum,XORSUM^nums[index]);  //T.C : O(2^n)
         solve(nums,index+1,totalSum,XORSUM);              //S.C : O(n)-->becuse of recursive callstack
     }

    int subsetXORSum(vector<int>& nums) {
        
        int totalSum = 0;
        solve(nums,0,totalSum,0);
        return totalSum;
    }

};


//Optimal Bitmasking Solution

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        
        int OR = 0;
          int n = nums.size();
        for(int i = 0 ;i < n;i++){ //T.C : O(n)
            OR|=nums[i];
        }
        
        for(int i= 0 ;i < n-1 ;i++){ //T.C : O(n-1)
             OR = OR<<1;
        }
         
         //S.C : O(1)
        return OR;
    }
};

