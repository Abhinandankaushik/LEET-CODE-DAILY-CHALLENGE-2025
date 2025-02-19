class Solution {
public:  
  string ans ="";  //S.C : O(n)
   void solve(int n , string& s , string& temp , int& k ){ 
       
       
         if( k == 1 ){
            ans = temp;  
        }

        if(temp.size() == n){
           k--;
           return ;
        }
        

        for(int i = 0 ;i  < 3 ;i++){  //T.C : O(3^n) * System stack : O(n)

            char ch = s[i];

            if(temp.empty() || temp[temp.size()-1] != ch){
                temp.push_back(ch);
                solve(n,s,temp,k);
                temp.pop_back();
            }
            
        }
   }
    string getHappyString(int n, int k) {
      
      string s = "abc";
      string temp ="";
      solve(n,s,temp ,k) ;   
      return ans ;

    }
};
