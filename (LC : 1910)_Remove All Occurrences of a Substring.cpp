class Solution {
public:
   
      //Recursive Approach
//    string remove(string& s , string& part){

//        if(s.find(part) == string::npos){
//         return s;
//        }
//        s.erase( s.find(part),part.length());
//        remove(s,part);
//       return s;
//    }
   

    string removeOccurrences(string s, string part) {
             
             //Recursive Approach
       //   return remove(s,part);

            
            //iterative Approach
            while( s.find(part) != string::npos){

            s.erase(s.find(part),part.length());
            
        }
        return s;
    }
};
