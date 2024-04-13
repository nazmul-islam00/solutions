//
// Created by HP on 4/12/2024.
//

#ifndef PROBLEM901_H
#define PROBLEM901_H
#include <stack>


class StockSpanner {
public:
    std::stack<std::pair<int, int>> stocks;
    StockSpanner() {

    }

    int next(int price) {
        int span = 1;
        while(!stocks.empty() && stocks.top().first <= price) {
            span += stocks.top().second;
            stocks.pop();
        }
        stocks.push({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */


#endif //PROBLEM901_H
