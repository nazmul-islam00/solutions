#include <vector>


class ProductOfNumbers {
private:
    std::vector<int> prefixProduct = {1};

public:
    ProductOfNumbers() {}

    void add(int num) {
        if (num == 0) {
            prefixProduct.clear();
            prefixProduct.push_back(1);
            return;
        }
        prefixProduct.push_back(prefixProduct[prefixProduct.size() - 1] * num);
    }

    int getProduct(int k) {
        if (prefixProduct.size() < k + 1) return 0;
        return prefixProduct[prefixProduct.size() - 1] / prefixProduct[prefixProduct.size() - 1 - k];
    }
};