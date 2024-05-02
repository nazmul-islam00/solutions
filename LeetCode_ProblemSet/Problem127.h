//
// Created by HP on 5/2/2024.
//

#ifndef PROBLEM127_H
#define PROBLEM127_H
#include <algorithm>
#include <queue>
#include <string>
#include <vector>


class Solution {
    bool isAdj(std::string s1, std::string s2) {
        int mismatch = 0;
        for(int i = 0; i < s1.length(); i++) {
            mismatch += (s1[i] != s2[i]);
        }
        return (mismatch == 1);
    }
    void getAdj(std::vector<std::string>& wordList, std::vector<std::vector<int>>& adj) {
        for(int i = 0; i < wordList.size() - 1; i++) {
            for(int j = 0; j < wordList.size(); j++) {
                if(isAdj(wordList[i], wordList[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
    }
    void bfs(std::vector<std::vector<int>>& adj, std::vector<int>& dist, int source) {
        dist[source] = 1;
        std::queue<int> bfsQueue;
        bfsQueue.push(source);
        while(!bfsQueue.empty()) {
            int index = bfsQueue.front();
            bfsQueue.pop();
            for(int i : adj[index]) {
                if(dist[i] == -1) {
                    dist[i] = dist[index] + 1;
                    bfsQueue.push(i);
                }
            }
        }
    }
public:
    int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
        int  target = -1, source = -1;
        for(int i = 0; i < wordList.size(); i++) {
            if(wordList[i] == endWord) {
                target = i;
            } else if(wordList[i] == beginWord) {
                source = i;
            }
        }
        // target word not found in the wordlist
        // no valid conversions
        if(target == -1) {
            return 0;
        }
        // source word not found in the wordlist
        // add source word
        if(source == -1) {
            source = wordList.size();
            wordList.push_back(beginWord);
        }
        // get adjacency list
        std::vector<std::vector<int>> adj(wordList.size(), std::vector<int> ());
        getAdj(wordList, adj);
        // bfs
        std::vector<int> dist(wordList.size(), -1);
        bfs(adj, dist, source);
        return (dist[target] == -1)? 0 : dist[target];
    }
};



#endif //PROBLEM127_H
