class Solution {
public:
    string largestGoodInteger(string num) {
        
         for(int i = 9 ; i >= 0 ; i-- ){ //constant
              string s(3,(i+'0')); 
              if(num.find(s) != string::npos ){ //(N*3) --> O(N)
                return s;
              }
         }
        return "";
    }
};
