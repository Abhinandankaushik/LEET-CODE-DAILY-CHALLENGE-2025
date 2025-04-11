class Solution {
public:
    
     bool solve(string s){
           int len = s.length();

           if(len%2 != 0) return false;
               
            int sum = 0;
           for(int i = 0 ; i < len/2 ; i++){
            sum+=(s[i]-'0');
           }
     
           for(int i = len/2 ; i < len ;i++ ){
            sum -= (s[i]-'0');
           }
           return !sum;
     }
    int countSymmetricIntegers(int low, int high) {
         
            int count = 0;
          for(int i = low ; i <= high ; i++){
               if( solve(to_string(i)) ){
                count++;
               }
          }
          return count;
    }
};
