//
//  StackTest.cpp
//  CTest
//
//  Created by 梁甜 on 2022/12/31.
//

#include "StackTest.hpp"
#include <stack>

///@link https://www.nowcoder.com/practice/c54775799f634c72b447ef31eb36e975?tpId=40&tqId=21440&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan&difficulty=&judgeStatus=&tags=/question-ranking
int mainStackTest() {
    std::stack<long long> stack;
    int n;
    while (scanf("%d", &n) != EOF) {
        long long num;
        for (int i = 0; i < n; i++) {
            scanf("%lld", &num);
            stack.push(num);
        }
        
        for (int i = 0; i < n; i++) {
            num = stack.top();
            stack.pop();
            printf("%lld ", num);
        }
        printf("\n");
    }
    return 0;
}

int mainMatchTest() {
    char chs[100];
    int len = 0;
    std::stack<int> stack;
    char ch;
    while (scanf("%c", &ch) != EOF) {
        chs[len] = ch;
        if (ch == '(') stack.push(len);
        else if (ch == ')') {
            if (stack.top() == '(') stack.pop();
            else {
                chs[len] = '?';
                stack.pop();
            }
        }
    }
    chs[len] = '\0';
    
    while (!stack.empty()) {
        int i = stack.top();
        stack.pop();
        chs[i] = '$';
    }
    
    printf("%s\n", chs);
    
    return 0;
}

/// 简单计算器
/// @link https://www.nowcoder.com/practice/5759c29a28cb4361bc3605979d5a6130?tpId=40&rp=1&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan&difficulty=&judgeStatus=&tags=&title=简单&sourceUrl=&gioEnter=menu
