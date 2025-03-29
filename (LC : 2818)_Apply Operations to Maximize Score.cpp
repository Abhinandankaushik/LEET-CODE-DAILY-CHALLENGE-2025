class Solution {
public:
     
   //finding All prime upto give limits
   vector<int> sieveOfEratosthenes(int limit) {
    

    vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int num = 2; num * num <= limit; ++num) {
        if (isPrime[num]) {
            for (int multiple = num * num; multiple <= limit; multiple += num) {
                isPrime[multiple] = false;
            }
        }
    }

    vector<int> primes;
    for (int i = 2; i <= limit; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }

    return primes;
   }
 const int mod = 1e9 +7;
   //binaryExponentiation
long long binaryExponentiation(long long a ,long long b){

         if(b == 0){
            return 1;
         }
      long long half = binaryExponentiation(a,b/2);
      half = (half*half)%mod;
      if(b%2 == 1){
        half = (half*a)%mod;
      }
      return half;
}  

  //next greater element
  vector<int> findNextGreater(vector<int>& primeScores) {
        int n = primeScores.size();
        vector<int> nextGreator(n, n);
        stack<int> st;

        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && primeScores[st.top()] <= primeScores[i]) {
                st.pop();
            }

            nextGreator[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return nextGreator;
    }
 
 //Previous greater element
  vector<int> findPrevGreater(vector<int>& primeScores) {
        int n = primeScores.size();
        vector<int> prevGreator(n, -1);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && primeScores[st.top()] < primeScores[i]) {
                st.pop();
            }

            prevGreator[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return prevGreator;
    }

typedef unsigned long long ll;

vector<int> findPrimeScores(vector<int>& nums){

     int maxElement = *max_element(begin(nums),end(nums));
    vector<int> primes = sieveOfEratosthenes(maxElement);

    int n = nums.size();
    vector<int>primeScores(n,0);
    
    for(int i = 0 ;i< n;i++){

        int val = nums[i];

        for(int prime : primes){

            if( prime*prime > val){
                break;
            }

            if(val % prime != 0){
                continue;
            }
           
            primeScores[i]++;
           
            while(val%prime == 0){
                val/= prime;
            }
            
        }

         if(val > 1){
            primeScores[i]++;
            }
    }
    return primeScores;

}

int maximumScore(vector<int>& nums, int k) {
      

     vector<int>primeScores = findPrimeScores(nums);
     vector<int>nextGreater = findNextGreater(primeScores);
     vector<int>priviousGreater = findPrevGreater(primeScores);
     
     int n = nums.size();
     vector<ll> subArrays(n,0);

      for(int i = 0; i < n;i++){
        subArrays[i] = (ll)( nextGreater[i] - i)*(i-priviousGreater[i]);

      }
      
      vector<pair<ll,ll>>sortedNums(n);

      for(int i = 0 ;i< n;i++){
        sortedNums[i]  = {nums[i],i};
      }

      sort(sortedNums.begin(),sortedNums.end(),greater<>());

     ll score = 1;
   

     int i = 0 ;

     while(k > 0){

       auto [val,index] = sortedNums[i];

      ll operations = min( (ll)k , subArrays[index] );
      
  
       ll points = binaryExponentiation(val,operations);
        score =  ( score* (points)%mod )%mod;
        k=(k-operations);
        i++;
     }

       return score;
    }
};
