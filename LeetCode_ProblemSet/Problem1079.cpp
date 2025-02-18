#include <string>
#include <unordered_set>


class Solution {
public:
    int numTilePossibilities(std::string tiles) {
        std::vector<int> freq(26, 0);

        for (const char ch : tiles) {
            freq[ch - 'A']++;
        }

        return countPossibilities(freq);
    }

private:
    int countPossibilities(std::vector<int>& freq) {
        int count = 0;
        
        for (int i = 0; i < freq.size(); i++) {
            if (freq[i] == 0) continue;

            count++;
            freq[i]--;
            
            count += countPossibilities(freq);
            freq[i]++;
        }

        return count;
    }

    void getSets(std::unordered_set<std::string>& sets, const std::string& tiles, std::string& choice, int used){
        if (choice.size() == tiles.size()) return;

        for (int i = 0; i < tiles.size(); i++) {
            if ((used & (1 << i)) != 0) continue;

            choice += tiles[i];
            used |= (1 << i);

            sets.insert(choice);

            getSets(sets, tiles, choice, used);
    
            choice = choice.substr(0, choice.size() - 1);
            used ^= (1 << i);
        }
    }
};
