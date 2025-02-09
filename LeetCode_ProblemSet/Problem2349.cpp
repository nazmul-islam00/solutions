#include <unordered_map>
#include <set>


class NumberContainers {
private:
    std::unordered_map<int, std::set<int>> numberToIndices;
    std::unordered_map<int, int> indexToNumber;

public:
    NumberContainers() {}
   
    void change(int index, int number) {
        if (indexToNumber.find(index) != indexToNumber.end()) numberToIndices[indexToNumber[index]].erase(index);
        if (numberToIndices.find(number) == numberToIndices.end()) numberToIndices[number] = std::set<int>();
        numberToIndices[number].insert(index);
        indexToNumber[index] = number;
    }

    int find(int number) {
        if (numberToIndices.find(number) == numberToIndices.end() || numberToIndices[number].size() == 0) return -1;
        return *numberToIndices[number].begin();
    }
};