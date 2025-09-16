#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

class Solution {
    std::string lower(const std::string& s) {
        std::string res = s;
        for (int i = 0; i < res.size(); i++) {
            if (res[i] >= 'A' && res[i] <= 'Z') res[i] += 'a' - 'A';
        }
        return res;
    }
    std::string encode(std::string& s) {
        std::string res = s;
        for (int i = 0; i < res.size(); i++) {
            if (isVowel(res[i])) res[i] = '*';
        }
        return res;
    }
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    std::vector<std::string> spellchecker(std::vector<std::string>& wordlist, std::vector<std::string>& queries) {
        std::unordered_set<std::string> ogSet;
        std::unordered_map<std::string, std::string> capMap, vowelMap;
        std::vector<std::string> res(queries.size());
        for (const std::string& s : wordlist) {
            ogSet.insert(s);
            std::string lowered = lower(s);
            if (capMap.find(lowered) == capMap.end()) capMap[lowered] = s;
            std::string encoded = encode(lowered);
            if (vowelMap.find(encoded) == vowelMap.end()) vowelMap[encoded] = s;
        } 
        for (int i = 0; i < queries.size(); i++) {
            if (ogSet.find(queries[i]) != ogSet.end()) {
                res[i] = queries[i];
                continue;
            }
            std::string lowered = lower(queries[i]);
            if (capMap.find(lowered) != capMap.end()) {
                res[i] = capMap[lowered];
                continue;
            }
            std::string encoded = encode(lowered);
            if (vowelMap.find(encoded) != vowelMap.end()) res[i] = vowelMap[encoded];
        }
        return res;
    }
};