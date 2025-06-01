class Solution {
public:
    long long distributeCandies(int n, int limit) {

        long long ans = 0;

        for (int i = 0; i <= min(n,limit); i++) {

            if (n - i > limit * 2)
                continue;

            ans += (min(limit, n - i) - max(0, n - i - limit) + 1);
        }

        return ans;
    }
}; 
