class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.length();

        vector<int>index; //O(1)

        for(int i = 0 ;i < n ;i++){ //O(n)
             if(s1[i] != s2[i]){
                index.push_back(i);
             }
             if(index.size() == 2)
             break;
        }
            
        if(index.empty())return true;
  

        if(index.size() > 2) return false;
        if(index.size() < 2) return false;
      
      
  

        swap(s1[index[0]],s1[index[1]]);

        if(s1 != s2)return false;

        return true;
    }
};
