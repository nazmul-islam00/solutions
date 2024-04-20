#include <vector>
#include <string>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if(numRows == 1)
            return s;
        if(numRows == 2) {
            std::string answer = "";
            for(int i = 0; i < s.length(); i += 2)
                answer += s[i];
            for(int i = 1; i < s.length(); i += 2)
                answer += s[i];
            return answer;
        }
        if(numRows == s.length())
            return s;
        std::vector<std::vector<char>> v(numRows, std::vector<char> (1000, ' '));
        int x = 0, y = 0;
        for(int i = 0; i < s.length();)         
            if(x == 0 || x == 1) {
                while(x < numRows) {
                    v[x++][y] = s[i++];
                    if(i == s.length())
                        break;
                }
                x--;
            }
            else if(x == numRows - 1) {
                while(x > 0) {
                    v[--x][++y] = s[i++];
                    if(i == s.length())
                        break;
                }
                x++;
            }
        std::string answer = "";
        for(int i = 0; i < v.size(); i++) 
            for(int j = 0; j < v[0].size(); j++)
                if(v[i][j] != ' ')
                    answer += v[i][j];
        return answer;
    }
};