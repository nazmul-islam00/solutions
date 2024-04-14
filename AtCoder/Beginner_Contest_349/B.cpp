#include <iostream>
#include <vector>
using namespace std;

// int main() {
//     string s;
//     cin >> s;
//     vector<int> v(26, 0);
//     for(int i = 0; i < s.length(); i++) {
//         v[s[i] - 'a']++;
//     }
//     vector<int> cnt(101, 0);
//     for(int i = 0; i < 26; i++) {
//         cnt[v[i]]++;
//     }
//     for(int i = 1; i <= 100; i++) {
//         if(cnt[i] != 2 && cnt[i] != 0) {
//             cout << "No" << endl;
//             return 0;
//         }
//     }
//     cout << "Yes" << endl;
// }