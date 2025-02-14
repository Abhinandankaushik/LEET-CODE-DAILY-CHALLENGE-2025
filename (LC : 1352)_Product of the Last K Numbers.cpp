class ProductOfNumbers {
    vector<int> vec; //S.C : O(n)

public:
    ProductOfNumbers() {}

    void add(int num) {
        if(num == 0 ){
            vec.clear();
            return;
        }
        if (!vec.empty()) {
            int b_l = vec.back();
            int c_p = b_l * num;
            vec.push_back(c_p);
            return;
        }
        vec.push_back(num);
    }

    int getProduct(int k) {  //T.C : O(1)
         
         int size = vec.size();
         if(size - k <  0){
            return 0;
         }

         if(size - k == 0) return vec.back();

         int index = vec.size() - k - 1;

         return vec.back()/vec[index];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
