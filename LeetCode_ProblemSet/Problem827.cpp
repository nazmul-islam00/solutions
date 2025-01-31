#include <vector>
#include <unordered_map>


class Solution {
private:
    class UnionFind {
    private:

    public:
        std::vector<int> parent;
        UnionFind(int size) {
            parent.resize(size);
            for (int i = 0; i < size; i++) parent[i] = i;
        }

        int findParent(int node) {
            if (parent[node] == node) return node;
            return parent[node] = findParent(parent[node]);
        }

        void merge(int node1, int node2) {
            int parent1 = findParent(node1), parent2 = findParent(node2);
            parent[parent1] = parent2; 
        }
    };

private:
    std::vector<int> changeX = {-1, 1, 0, 0};
    std::vector<int> changeY = {0, 0, -1, 1};

public:
    int largestIsland(std::vector<std::vector<int>>& grid) {
        int size = grid.size();
        UnionFind unionFind = mergeCells(grid);
        std::unordered_map<int, int> islandSize = countIslandSizes(unionFind, size);
        int maxIslandSize = getMaxIslandSize(islandSize);
        if (maxIslandSize == size * size) return maxIslandSize;

        for (int row = 0; row < size; row++) {
            for (int col = 0; col < size; col++) {
                if (grid[row][col] == 1) continue;
                maxIslandSize = std::max(maxIslandSize, getNewIslandSize(unionFind, grid, islandSize, row, col, size));
            }
        }

        return maxIslandSize;
    }

private:
    int getNewIslandSize(UnionFind& unionFind, std::vector<std::vector<int>>& grid, std::unordered_map<int, int>& islandSize, int row, int col, int size) {
        std::vector<int> parents;
        int newIslandSize = 1;
        
        for (int idx = 0; idx < changeX.size(); idx++) {
            int newRow = row + changeX[idx], newCol = col + changeY[idx];
            if (!isInGrid(newRow, newCol, size)) continue;
            if (grid[newRow][newCol] == 0) continue;

            int cellNumber = unionFind.findParent(getCellNumber(newRow, newCol, size));
            if (std::find(parents.begin(), parents.end(), cellNumber) != parents.end()) continue;
            newIslandSize += islandSize[cellNumber];
            parents.push_back(cellNumber);
        }

        return newIslandSize;
    }

    int getMaxIslandSize(std::unordered_map<int, int>& islandSize) {
        int maxIslandSize = 0;
        for (auto &[cellNumber, islandSize] : islandSize) maxIslandSize = std::max(maxIslandSize, islandSize);
        return maxIslandSize;
    }

    std::unordered_map<int, int> countIslandSizes(UnionFind& unionFind, int size) {
        std::unordered_map<int, int> islandSize;

        for (int row = 0; row < size; row++) {
            for (int col = 0; col < size; col++) {
                int cellNumber = unionFind.findParent(getCellNumber(row, col, size));
                if (islandSize.find(cellNumber) != islandSize.end()) islandSize[cellNumber]++;
                else islandSize[cellNumber] = 1;
            }
        }

        return islandSize;
    }

    UnionFind mergeCells(std::vector<std::vector<int>>& grid) {
        int size = grid.size();
        UnionFind unionFind(size * size);

        for (int row = 0; row < size; row++) {
            for (int col = 0; col < size; col++) {
                if (grid[row][col] == 0) continue;

                for (int idx = 0; idx < changeX.size(); idx++) {
                    int newRow = row + changeX[idx], newCol = col + changeY[idx];
                    if (!isInGrid(newRow, newCol, size)) continue;
                    if (grid[newRow][newCol] == 0) continue;
                    unionFind.merge(getCellNumber(row, col, size), getCellNumber(newRow, newCol, size));
                }
            }
        }

        return unionFind;
    }

    int getCellNumber(int row, int col, int size) {
        return row * size + col;
    }

    bool isInGrid(int row, int col, int size) {
        return 0 <= row && row < size && 0 <= col && col < size;
    }
};