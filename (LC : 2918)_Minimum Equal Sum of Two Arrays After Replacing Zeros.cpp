class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {

        int n1Zero = 0;
        long long sum1 = 0;

        int n2Zero = 0;
        long long sum2 = 0;

        for (auto& it : nums1) {//T.C : O(n+m) , S.C : O(1)

          sum1 += it;
            if (it == 0) {
                n1Zero++;
                it = 1;
                sum1++;

            }
           
        }

        for (auto& it : nums2) {

            sum2 += it;
            if (it == 0) {
                n2Zero++;
                it = 1;
                sum2++;
            }
            
        }
      
       if(n1Zero == 0 && sum2 > sum1 || n2Zero  == 0 && sum1 > sum2 )return -1;

       return max(sum1,sum2);

       
    }
};
