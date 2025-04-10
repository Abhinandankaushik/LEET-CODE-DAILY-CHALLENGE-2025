
class Solution {
public:
     
      long long solve(string& str , string& s , int limit){

          if(str.length() < s.length()) return 0 ;

          long long count = 0;

          string trailStr = str.substr(str.length()-s.length());

             int remainlen = str.length() - s.length();

             for(int i = 0 ;i < remainlen ; i++){

                 int digit = str[i] - '0';

                 if(digit <= limit){
                    count+=digit*pow(limit+1,remainlen-i-1);

                 }
                 else{
                    count += pow(limit+1,remainlen-i);
                    return count;
                 }
             }  

          if(trailStr >= s){
            count+=1;
          }
          return count;
      }

    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        
        string str = to_string(start-1);
        string end = to_string(finish);


        return solve(end,s,limit)-solve(str,s,limit);
    }
};
