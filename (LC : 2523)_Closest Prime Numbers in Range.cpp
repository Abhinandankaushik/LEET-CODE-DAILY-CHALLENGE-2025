class Solution {
public:
     
     vector<int> solve(int left , int right){

     vector<bool> is_prime(right+1, true); //S.c O(n)

     is_prime[0] = is_prime[1] = false; 

    for (int i = 2; i * i <= right ; i++) {  //T.C : O(n)
        if (is_prime[i]) {
            for (int j = i * i; j <= right; j += i) {
                is_prime[j] = false;
            }
        }
    }

    vector<int>ans;
    for (int i = left; i <= right; i++) {
        if (is_prime[i]) {
           ans.push_back(i);
        }
    }
  
    if(ans.size() < 2) 
    return {-1,-1};

      
      int minDif = INT_MAX;

      vector<int>finalAns(2,-1);

      for(int i = 1 ;i < ans.size() ;i++){

        int dif = ans[i] - ans[i-1];

         if(dif < minDif){
            minDif = dif;
            finalAns[0] = ans[i-1];
            finalAns[1] = ans[i];
         }

      }
      return finalAns;

     }

    vector<int> closestPrimes(int left, int right) {
       return solve(left,right);
    }
};
