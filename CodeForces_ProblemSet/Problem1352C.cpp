#include <cmath>
#include <iostream>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, k;
        std::cin >> n >> k;

        int chunks = std::floor(k / (n - 1));
        int offset = k - chunks * (n - 1);
        std::cout << (long long)chunks * n + ((offset == 0) ? -1 : offset) << std::endl;
    }

    return 0;
}