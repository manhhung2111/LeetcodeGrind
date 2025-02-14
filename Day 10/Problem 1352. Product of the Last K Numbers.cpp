class ProductOfNumbers {
public:
    vector<int> prefixProduct = {1};
    int n = 1;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if (num == 0) {
            prefixProduct = {1};
            n = 1;
        } else {
            prefixProduct.push_back(prefixProduct.back() * num);
            n++;
        }
    }
    
    int getProduct(int k) {
        if (n <= k) {
            return 0;
        }
        return prefixProduct.back() / prefixProduct[prefixProduct.size() - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */