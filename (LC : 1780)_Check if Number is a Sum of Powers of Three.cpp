class Solution {
public:
    bool checkPowersOfThree(int n) {
        

        //Ternary represent tation approach 
        // if n%3  > 1 return false because if n%3 > 1 it means we need extra number which have same
        // power of three to make n but question is asking only different power of three 
        // to make this particular n 

        while( n > 0 ){
             
            int digit = n/3;
            int remainder = n%3;

            if( remainder > 1) return false;

            n = digit;
        }
        return true;
    }
};
