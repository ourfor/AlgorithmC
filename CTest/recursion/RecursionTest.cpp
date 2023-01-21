//
//  RecursionTest.cpp
//  CTest
//
//  Created by 梁甜 on 2023/1/3.
//

#include "RecursionTest.hpp"
#include <iostream>

/// N的阶乘
/// @link https://www.nowcoder.com/practice/97be22ee50b14cccad2787998ca628c8?tpId=40&rp=1&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan&difficulty=&judgeStatus=&tags=&title=n的&sourceUrl=&gioEnter=menu
long long Factorial(long long n) {
    if (n == 1) {
        return 1;
    } else {
        return n * Factorial(n - 1);
    }
}

void mainFactorial() {
    long long n;
    while (std::cin >> n) {
        std::cout << Factorial(n) << std::endl;
    }
}

/// 练习
/// 汉诺塔
/// @link http://acm.hdu.edu.cn/showproblem.php?pid=2064


/// 练习
/// 斐波那契数
/// @link https://www.nowcoder.com/practice/17ad6908e36a49f4b06ea96936e8bb25?tpId=40&tqId=21427&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan&difficulty=&judgeStatus=&tags=/question-ranking


