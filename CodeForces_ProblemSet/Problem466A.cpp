#include <iostream>


class Solution {
public:
    static  void run() {
        int n, m, a, b;
        std::cin >> n >> m >> a >> b;
        int cost = 0;
        if(m * a <= b)
            cost = n * a;
        else {
            int possible_bundles = n / m;
            cost += possible_bundles * b;
            int remaining_tickets = n % m;
            if(remaining_tickets * a < b)
                cost +=remaining_tickets * a;
            else
                cost += b;
        }
        std::cout << cost << std::endl;
    }
};



// int main() {
//     Solution main;
//     main.run();
// }