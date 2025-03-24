class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {

        sort(meetings.begin(), meetings.end()); //T.C : O(nlog(n))

        int total = 0;
        int end = 0;

        for (int i = 0; i < meetings.size(); i++) { //T.C : O(n)

            if (meetings[i][0] > end) {
                total += (meetings[i][0] - end - 1);
            }

            end = max(end, meetings[i][1]);
        }

        if (days > end)
            total += (days - end);

        return total;
    }
};
