class Solution {
public:
    bool isPowerOfFour(int n) {
      
      long long temp = 1;
     while(temp < n ){
          
          temp<<=2;
          if(temp == n)return true;
     }   

     return n==temp;
    }
};
