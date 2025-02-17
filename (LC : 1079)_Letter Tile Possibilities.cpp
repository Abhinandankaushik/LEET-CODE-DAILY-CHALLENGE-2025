class Solution {
public:
     unordered_map<string,bool>map; //S.C : (n*n!) + system stack O(n)
     void solve(string& tiles, int n , string& temp , vector<bool>& check){

           for(int i = 0 ;i < n ;i++){ //T.C : O(n!)
             
               if(!check[i]){
                temp.push_back(tiles[i]);
                check[i] = true;
                solve(tiles,n,temp,check);
                check[i]= false;
                temp.pop_back();
               }
           }
       map[temp] = true;
     }
    int numTilePossibilities(string tiles) {
        
      int n = tiles.length();
      string temp = "";
      vector<bool>check(n+1,false); //S.C  : O(n)
      solve(tiles,n,temp,check);
      return map.size()-1;
    }
};
