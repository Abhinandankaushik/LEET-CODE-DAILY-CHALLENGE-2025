class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
       
        int n = arr.size();
        if(n < 3) return false;

        for (int i = 1; i <= n - 2; i++) { //T.C : O(n) , S.C : O(1)
            if (arr[i - 1] & 1 && arr[i] & 1 && arr[i + 1] & 1)
                return true;
        }

        return false;
    }
};
