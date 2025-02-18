class Solution {
public: 
        
        //Super BruteForce : cheking all permutation 
    // bool matches(string& pattern, string& s ){ 

    //     for(int i = 0 ; i < pattern.size() ;i++){ //T.C : O(n)
             
    //          if(pattern[i] == 'I' && s[i] > s[i+1]) return false;
    //          if(pattern[i] == 'D' && s[i] < s[i+1]) return false;
    //     }

    //     return true;
    // }
      
    
   string  solveUsingStack(string& pattern ){
           
         int counter = 1;
         stack<char>st;
           string num = "";
          int n = pattern.size(); 
         for(int i = 0 ; i <= n; i++){ //T.C : O(n)
                  
                  st.push(counter +'0');
                  counter++;

                  if( i == n || pattern[i] == 'I'){
                      
                      while(!st.empty()){
                        num+=st.top();
                        st.pop();
                      }
                  }
         } 
      return num;
    }
    string smallestNumber(string pattern) {
        
        int n  = pattern.size();

        // string s = "";

        // for(int i = 1; i <= n+1 ;i++){
        //     s.push_back(i+'0');
        // }

        // while( !matches(pattern,s) ){
        //      next_permutation(s.begin(),s.end()); //T.C : (n+1)!
        // }
        // return s;

        return solveUsingStack(pattern);
      
    }
};
