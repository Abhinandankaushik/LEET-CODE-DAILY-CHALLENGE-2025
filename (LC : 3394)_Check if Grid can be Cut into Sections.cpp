class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
      
      int size = rectangles.size();
      sort(rectangles.begin(),rectangles.end(),[](vector<int>&a,vector<int>&b){
        return a[0] < b[0];
      }) ;

    

     int x_partition = 0;
     int end = rectangles[0][2];
     for(int i = 1 ;i < size ; i++){

         if( end <= rectangles[i][0]){
          x_partition++;  
         }    
        
        end = max(end,rectangles[i][2]);
     }
        
     if(x_partition >=2) return true;  

     
   

 sort(rectangles.begin(),rectangles.end(),[](vector<int>&a,vector<int>&b){
        return a[1] < b[1];
      }) ;

     int y_partition = 0;
     end = rectangles[0][3];
     for(int i = 1 ;i < size ; i++){
       
          if( end <= rectangles[i][1]){
           y_partition++;  
         }    
        
        end = max(end,rectangles[i][3]);
     }
     
      
     if(y_partition >=2) return true;

      return false;
    }
};
