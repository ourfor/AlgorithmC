//
//  MiniStack.cpp
//  CTest
//
//  Created by 赫拉 on 2023/2/12.
//

#include "MiniStack.hpp"
#include <stack>

/// 包含min函数的栈
/// @link https://www.acwing.com/problem/content/90/
class MinStackSolution {
private:
    std::stack<int> *normalStack = nullptr;
    std::stack<int> *minimalStack = nullptr;
public:
    /** initialize your data structure here. */
    MinStackSolution() {
        normalStack = new std::stack<int>;
        minimalStack = new std::stack<int>;
    }
    
    void push(int x) {
        normalStack->push(x);
        int min = x;
        if (!minimalStack->empty()) {
            min = minimalStack->top() > x ? x : minimalStack->top();
        }
        minimalStack->push(min);
    }
    
    void pop() {
        normalStack->pop();
        minimalStack->pop();
    }
    
    int top() {
        return normalStack->top();
    }
    
    int getMin() {
        return minimalStack->top();
    }
    
    ~MinStackSolution() {
        if (normalStack != nullptr) delete normalStack;
        if (minimalStack != nullptr) delete minimalStack;
    }
};
