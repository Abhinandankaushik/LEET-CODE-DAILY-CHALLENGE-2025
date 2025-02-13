class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        priority_queue<unsigned long long,vector<unsigned long long>,greater<unsigned long long>>pq; //S.C : O(n)
        for(int i = 0 ; i < nums.size() ;i++){ //T.C : O(n)
            pq.push(nums[i]);
        }
        unsigned long long operation = 0;

        while(pq.top() < k ){ //T.C : O(n)

            if(pq.size() >= 2){
                unsigned long long a = pq.top();pq.pop();
                unsigned long long b = pq.top();pq.pop();
               unsigned long long   newVal = min(a,b)*2+max(a,b);
                pq.push(newVal);
                operation++;
            }
            else break;
        }
        return operation;
    }
};
