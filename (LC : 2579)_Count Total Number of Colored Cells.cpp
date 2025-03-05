class Solution {
public:
    long long coloredCells(int n) {

    //    long long ans = 1;
    //    //iterative solution using Arithmetic Progression 
    //    for(int i = 1 ; i < n ;i++){//T.C : O(n) && S.C : O(1)
    //      ans += (4*i);  
    //    }   
    //     return ans;


    //Solutio using AP ->T.C : O(1)
   return  (1 + (long long)n*(n-1)*2);
    
     
    }
};
