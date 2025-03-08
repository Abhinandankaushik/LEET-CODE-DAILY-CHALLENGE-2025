class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        
        //Standard Sliding Window pattern 

        int n = blocks.length();
        int white_block = 0;
        int black = 0;
        queue<char>q;    //S.C : O(K)

        for(int i = 0 ;i < k ;i++){ //T.C : O(n)     
            char ch = blocks[i];
            if(ch == 'W'){
             white_block ++;
              black = 0;
            }
            if(ch =='B'){
                black++;
            }
            if(black == k) return 0;
            q.push(ch);
        }
      
        int minBlock = white_block;
        for(int i = k ;  i <  n ;i++){   
             char ch = blocks[i];
            minBlock = min(minBlock,white_block);
             if(q.front() == 'W'){
                white_block --;     
             } 
             q.pop();
             if(ch =='W'){
                white_block ++;
                black = 0;
             }

             if(ch =='B'){
                black++;
             }
            if(black == k) return 0;
             q.push(ch);
        }  
    minBlock = min(minBlock,white_block);

     return minBlock;
    }
};
