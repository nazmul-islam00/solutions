#include <iostream>
#include <vector>

class Solution {
public:
    void run() {
        int t;
        std::cin >> t;
        while(t--) {
            int n;
            std::cin >> n;
            std::vector<std::vector<char>> grid(2 * n, std::vector<char>(2 * n));
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    if((i + j) % 2) 
                        grid[2 * i][2 * j] = grid[2 * i + 1][2 * j] = 
                        grid[2 * i][2 * j + 1] = grid[2 * i + 1][2 * j + 1] = '.';
                    else 
                        grid[2 * i][2 * j] = grid[2 * i + 1][2 * j] = 
                        grid[2 * i][2 * j + 1] = grid[2 * i + 1][2 * j + 1] = '#';
            for(int i = 0; i < 2 * n; i++) {
                for(int j = 0; j < 2 * n; j++)
                    std::cout << grid[i][j];
                std::cout << std::endl;
            }
        }
    }
};
