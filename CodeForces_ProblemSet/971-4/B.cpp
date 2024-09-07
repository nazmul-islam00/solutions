#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> pos(n);
        for (int i = 0; i < n; i++) {
            std::string note;
            std::cin >> note;
            pos[n - 1 - i] = note.find('#') + 1;
        }
        for (int i : pos) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
}