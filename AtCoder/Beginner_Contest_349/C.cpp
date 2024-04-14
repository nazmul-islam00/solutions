#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// int main() {
// 	string s, t;
// 	cin >> s >> t;
// 	bool f = false, sc = false, th = false;
// 	for(int i = 0; i < s.length(); i++) {
// 		if(!f) {
// 			while(i < s.length() && s[i] - 'a' != t[0] - 'A')
// 				i++;
// 			if(s[i] - 'a' == t[0] - 'A') f = true;
// 		} else if(!sc) {
// 			while(i < s.length() && s[i] - 'a' != t[1] - 'A')
// 				i++;
// 			if(s[i] - 'a' == t[1] - 'A') sc = true;
// 		} else if(!th) {
// 			if(t[2] == 'X') {
// 				th = true;
// 				break;
// 			} else {
// 				while(i < s.length() && s[i] - 'a' != t[2] - 'A')
// 					i++;
// 				if(s[i] - 'a' == t[2] - 'A') th= true;
// 			}
// 		}
// 	}
// 	if(f && sc && th) cout << "Yes" << endl;
// 	else cout << "No" << endl;
// }
