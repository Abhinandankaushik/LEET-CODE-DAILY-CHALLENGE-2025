class FenwickTree {
private:
    vector<int> bit; 

public:
    FenwickTree(int size) : bit(size + 1, 0) {}

    void update(int index, int delta) {
        index++;
        while (index < bit.size()) {
            bit[index] += delta;
            index += index & -index;
        }
    }

    int query(int index) {
        index++;
        int sum = 0;
        while (index > 0) {
            sum += bit[index];
            index -= index & -index;
        }
        return sum;
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> indexInNums2(n), mappedIndex(n);

      
        for (int i = 0; i < n; i++) {
            indexInNums2[nums2[i]] = i;
        }

     
        for (int i = 0; i < n; i++) {
            mappedIndex[indexInNums2[nums1[i]]] = i;
        }

        FenwickTree fenwick(n);
        long long totalTriplets = 0;

        for (int i = 0; i < n; i++) {
            int mappedPos = mappedIndex[i];
            int countLeft = fenwick.query(mappedPos);
            fenwick.update(mappedPos, 1);
            int countRight = (n - 1 - mappedPos) - (i - countLeft);
            totalTriplets += (long long)countLeft * countRight;
        }

        return totalTriplets;
    }
};
