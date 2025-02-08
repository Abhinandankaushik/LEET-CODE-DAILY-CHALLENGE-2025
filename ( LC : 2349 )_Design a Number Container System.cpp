class NumberContainers {
    //S.C : O(n)
    unordered_map<int, set<int>> num_to_index;
    unordered_map<int, int> index_to_num;

public:
    NumberContainers() {}

    void change(int index, int number) {

        if (index_to_num.find(index) != index_to_num.end()) {

            // previous mapping deletion
            int prevNum = index_to_num[index];
            num_to_index[prevNum].erase(index); //T.c : O(logn)

            // number have no index the  delete the prev number from map
            if (num_to_index[prevNum].size() == 0)
                num_to_index.erase(prevNum); //T.C : O(1)
        }
        // mapping number with index
        index_to_num[index] = number;
        num_to_index[number].insert(index); //T.c : O(logn)
    }

    int find(int number) {

        if (num_to_index.find(number) != num_to_index.end()) {
            int index = *num_to_index[number].begin(); // T.C : O(1)
            return index;
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
