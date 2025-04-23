class Solution {
public:
    int countdigit(int n) { //T.C : O(log(n))
        int sum = 0;
        while (n) {

            int rem = n % 10;
            n /= 10;
            sum += rem;
        }
        return sum;
    }
    int countLargestGroup(int n) {

        map<int, int> mp; //S.C : O(n)
        int maxi = 0;
        for (int i = 1; i <= n; i++) { //T.C : O(n*log(n))
            int count = countdigit(i);
            mp[count]++;
            maxi = max(maxi, mp[count]);
        }

        int count = 0;
        for (auto& it : mp) { //T.C : O(n)
            if (it.second == maxi) {
                count++;
            }
        }
        return count;
    }
};
