class Solution {
public:
    int minMaxDifference(int num) {

     
        string s = to_string(num);
        string temp = s;
        char maxi_v = s[0];
        char mini_v = s[0];

        for(auto& it : s){
            if(it < '9'){
                maxi_v = it;
                break;
            }
        }
        
     
        for(int i = 0 ;i <s.length() ;i++){
             
             if(s[i] == maxi_v){
                s[i] = '9';
             } 

             if(temp[i] == mini_v){
                temp[i] = '0';
             }
        }
        cout<<s<<" "<<temp<<endl;

        int maxi = stoi(s);
        int mini = stoi(temp);


        return maxi - mini;
    }
};
