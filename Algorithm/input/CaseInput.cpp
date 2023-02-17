//
//  CaseInput.cpp
//  CTest
//
//  Created by 梁甜 on 2022/12/28.
//

#include "CaseInput.hpp"
#include <cstdio>

using namespace std;

/// 单组输入
int mainSingleInput() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", a + b);
    return 0;
}


/// 多组输入，未知组数
int mainMultiInput() {
    int a, b;
    // EOF表示文件结尾
    while (scanf("%d %d", &a, &b) != EOF) {
        printf("%d\n", a + b);
    }
    return 0;
}


/// 多组输入，给定组数
int mainMultiInputWithGivenGroup() {
    int a, b, cases;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d %d", &a, &b);
        printf("%d", a + b);
    }
    
    return 0;
}


/// 多组输入, 特定跳出
int mainMultiInputWithCondition() {
    int a, b;
    while (scanf("%d %d", &a, &b) != EOF) {
        // 题目制定条件
        if (a == 0 && b == 0) break;
        printf("%d\n", a + b);
    }
    return 0;
}
