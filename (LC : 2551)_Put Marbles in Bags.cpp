class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {

        if(k==1) return 0;
        int n = weights.size();
       
        priority_queue<int, vector<int>, greater<int>> maxi; //S.C : O(k-1)
        priority_queue<int> mini;

        for (int i = 0; i < n - 1; i++) {  //T.C : O(n*log(n))

            int nbr_sum = weights[i] + weights[i + 1];

            if (mini.size() == k - 1) {

                if (mini.top() > nbr_sum) {
                    mini.pop();
                    mini.push(nbr_sum);
                }

            } else {
                mini.push(nbr_sum);
            }

            if (maxi.size() == k - 1) {

                if (maxi.top() < nbr_sum) {
                    maxi.pop();
                    maxi.push(nbr_sum);
                }
            } else {
                maxi.push(nbr_sum);
            }
        }

        long minSum = 0;
        long maxSum = 0;

        while (!mini.empty()) { //T.C : O(k-1)
            minSum+=mini.top();
            mini.pop(); 
            maxSum+=maxi.top();
            maxi.pop();
        }

        return maxSum - minSum;
    }
};
