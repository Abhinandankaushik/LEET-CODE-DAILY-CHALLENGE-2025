class Solution {
public:
    string clearDigits(string s) {
        
        //Approach - 1 : Using 2 loops
        // for(int i = 0 ;i < s.length() ; i++){
             
        //      if(s[i] >='0' && s[i] <= '9'){
        //           int j = i-1;
        //         while(j >= 0){
                    
        //             if(s[j] >= 'a' && s[j] <= 'z'){
        //                 s[j] = '#';
        //                 break;
        //             }
        //             j--;
        //         }
        //      }

        // }
        // string ans = "";
        // for(auto& it : s){
        //     if(it != '#' && (it >= 'a' && it <= 'z')){
        //         ans+=it;
        //     }
        // }
        // return ans;
      
      //Approahc - 2 : Using Stack 
      stack<int>st;
        for(int i = 0 ; i < s.length() ;i++){

             if(s[i] >= '0' && s[i] <= '9'){

                while(!st.empty() &&  !(s[st.top()] >= 'a') && !(s[st.top()] <= 'z') ){
                   st.pop();
                }
                if(!st.empty()){
                    s[st.top()] = '#';
                    st.pop();
                }
             }
            else st.push(i);
            
        }

          string ans = "";
        for(auto& it : s){
            if(it != '#' && (it >= 'a' && it <= 'z')){
                ans+=it;
            }
        }
        return ans;

    }
};
