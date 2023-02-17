//
//  StackOperateSequence.cpp
//  CTest
//
//  Created by 赫拉 on 2023/2/12.
//

#include "StackOperateSequence.hpp"
#include <vector>
#include <stack>

/// 栈的压入、弹出序列
/// @link https://www.acwing.com/problem/content/40/
class StackOperateSequenceSolution {
public:
    bool isPopOrder(std::vector<int> pushV,std::vector<int> popV) {
        int sizeOfPush = (int)pushV.size();
        int sizeOfPop = (int)popV.size();
        if (sizeOfPop != sizeOfPush) {
            return false;
        }
        
        if (sizeOfPush == 0) return true;
        std::stack<int> stack;
        int i = 0, j = 0;
        for (; i < sizeOfPush; i++) {
            if (pushV[i] == popV[j]) {
                j++;
            } else if (!stack.empty() && stack.top() == popV[j]) {
                j++;
                stack.pop();
                i--;
            } else {
                stack.push(pushV[i]);
            }
        }
        
        for (; j < sizeOfPop; j++) {
            if (stack.empty()) {
                break;
            } else {
                if (stack.top() == popV[j]) {
                    stack.pop();
                } else {
                    break;
                }
            }
        }
        
        return stack.empty();
    }
};
