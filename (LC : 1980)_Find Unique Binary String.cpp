class Solution {
public: 
     unordered_map<string,bool>map;
     string ans = "";

     void solve(string& temp , int n ){ 

        if(ans.length() > 1 ) return ;

        if(temp.length() == n){
            if(map.find(temp) == map.end())
            ans = temp;
                  return ;
        } 

        temp.push_back('0');
        solve(temp,n);      //T.C : O(2^n)  + System stack O(n)
        temp.pop_back();   

        temp.push_back('1');
        solve(temp,n);
        temp.pop_back();
           
           return ;
     }  
    
    string findDifferentBinaryString(vector<string>& nums) {
         
        for(auto& it : nums){
            map[it] = true;
        }

        string temp = ""; 
        solve(temp , nums[0].length());
        return ans;
                
    }
};
