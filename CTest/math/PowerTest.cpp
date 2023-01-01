//
//  PowerTest.cpp
//  CTest
//
//  Created by 梁甜 on 2023/1/1.
//

#include "PowerTest.hpp"

/// 快速幂
int QuickPower(int x, int n) {
    int ans = 1;
    while (n) {
        if (n % 2 == 1) {
            ans *= x;
        }
        n /= 2;
        x *= x;
    }
    return ans;
}
