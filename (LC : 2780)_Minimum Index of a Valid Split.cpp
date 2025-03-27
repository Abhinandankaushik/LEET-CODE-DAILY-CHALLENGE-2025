class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        
        unordered_map<int,int>mp; //S.C : O(n)
        for(auto&it : nums){ //T.C : O(n)
            mp[it]++;
        }

      int maxiFreq = 0;
      int num = 0;
      for(auto &it : mp){//T.C : O(n)
         if(maxiFreq < it.second){
            maxiFreq  = it.second;
            num = it.first;
         }
      }
       
       cout<<maxiFreq<<" "<<num<<endl;
       int index = -1;
      int f = 0;
      for(int i = 0;i< nums.size() -1;i++){//T.C : O(n)
          
          if(nums[i] == num){
            f++;
          }
          
          if( f*2 > i+1 && (maxiFreq-f)*2 > ( nums.size()-(i+1)) ){
            index = i;
            break;
          }
      }
      return index;
    }
};
