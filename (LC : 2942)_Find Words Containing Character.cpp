class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {


           int n = words.size();
               vector<int>v;  //S.C : O(n)

           for(int i = 0 ;i < n;i++){ //T.C : O(n*l)
               if(words[i].find(x) != string::npos){
                 v.push_back(i);
               }
           }   
           return v;
    }
};
