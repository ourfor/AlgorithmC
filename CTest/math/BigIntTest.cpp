//
//  BigIntTest.cpp
//  CTest
//
//  Created by 梁甜 on 2023/1/1.
//

#include "BigIntTest.hpp"
#include <iostream>
#include <string>

/// 练习
/// 大整数

#define MAXN 1010

typedef struct BigInt {
    int length;
    int digit[MAXN];
    
    BigInt operator+(BigInt other) {
        BigInt ans;
        int carry = 0;
        ans.length = 0;
        int bound = length > other.length ? length : other.length;
        for (int i = 0; i < bound; i++) {
            int curr = 0;
            if (i < length && i < other.length) {
                curr = digit[i] + other.digit[i] + carry;
            } else if (i < length) {
                curr = digit[i] + carry;
            } else {
                curr = other.digit[i] + carry;
            }
            carry = curr / 10;
            ans.digit[i] = curr % 10;
            ans.length++;
        }
        if (carry) {
            ans.digit[ans.length++] = carry;
        }
        return ans;
    }
    
    friend std::ostream& operator<<(std::ostream& out, BigInt& x) {
        for (int i = 0; i < x.length; ++i) {
            out << x.digit[x.length - i - 1];
        }
        return out;
    }
    
    friend std::istream& operator>>(std::istream& in, BigInt& x) {
        std::string chs;
        in >> chs;
        x.length = (int)chs.size();
        for (int i = 0; i < x.length; i++) {
            x.digit[i] = chs[x.length - i - 1] - '0';
        }
        return in;
    }
} BigInt;


/// 练习
/// @link https://www.nowcoder.com/practice/4c39c984ea3848b48e111b8e71ec1dd4?tpId=40&rp=1&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan&difficulty=&judgeStatus=&tags=&title=a&sourceUrl=&gioEnter=menu

void BigIntAddTest() {
    BigInt a, b, c;
    while (std::cin >> a >> b) {
        c = a + b;
        std::cout << c << std::endl;
    }
}
