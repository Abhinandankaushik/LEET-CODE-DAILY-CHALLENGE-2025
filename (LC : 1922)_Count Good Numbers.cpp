

 int mod = 1e9+7;
long long binaryExponentiation(long long a ,long long b){

         if(b == 0){
            return 1;
         }
      long long half = 1LL*binaryExponentiation(a,b/2);
 
      half =(half%mod)*(half%mod);

      if(b%2 != 0){
        half = (half%mod)*(a%mod);
      }
      return half;
}


class Solution {
public:
    int countGoodNumbers(long long n) {
         
        
         long long even = (n+1)/2;
         long long odd =  n/2;

         int total = ((binaryExponentiation(5,even)%mod)*(binaryExponentiation(4,odd)%mod))%mod; //T.C : O(log(even) + log(odd))--> O(log(n))

         return total;
    }
};
