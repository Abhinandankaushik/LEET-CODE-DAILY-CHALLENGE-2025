class Solution {
public:
    int maximumCount(vector<int>& nums) {
        
        int n =  nums.size();
        int s = 0 ;
        int l = n-1;
         
        int negative = -1;
        int positive = -1;

        while(s <= l){  //T.C : O[log(n)]  ==> for finding first negative index

            int mid = (s+l)/2;

            if(nums[mid] < 0){
                negative = mid;
                s = mid+1;
            }
            else {
                l = mid-1;
            }
        }

        s = negative+1 , l= n-1;

        while( s <= l){  //T.C : O[ log(log(n))] ==> for finding first positive index

            int mid = (s+l)/2;

            if(nums[mid]>0){
                positive = mid;
                l = mid-1;
            }
            else {
                s = mid+1;
            }
        }
       
     

       if(positive == -1 && negative == -1) return 0;  //if all number are 0 

       positive = positive == -1 ? n : positive ;  
       negative = negative == -1 ? 0 : negative ;

   

       return max(negative+1,n-positive);
    
    }
};
