class Solution {
public:
    int maximum69Number (int num) {
         
         string s = to_string(num);
        for(int i = 0 ; i < s.length() ; i++){ // s.length() <= 4 --> T.C : O(4) --> O(1)

              if(s[i] != '9'){
                s[i] = '9';
                break;
              }
              
        }

        return stoi(s);
    }
};
