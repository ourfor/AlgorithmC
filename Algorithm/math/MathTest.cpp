//
//  MathTest.cpp
//  CTest
//
//  Created by 梁甜 on 2022/12/31.
//

#include "MathTest.hpp"

/// 二进制数
/// @link https://www.nowcoder.com/practice/103dd589fed14457a673c613d8de3841?tpId=40&rp=1&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan&difficulty=&judgeStatus=&tags=&title=二进制&sourceUrl=&gioEnter=menu

int mainConvert10To2() {
    int ans[32];
    int len = 0;
    int num = 0;
    while (scanf("%d", &num) != EOF) {
        len = 0;
        while (num) {
            ans[len++] = num % 2;
            num /= 2;
        }
        for (int i = len - 1; i >= 0; i--) printf("%d", ans[i]);
        printf("\n");
    }
    return 0;
}


/// 练习
/// @link https://www.nowcoder.com/practice/eda051c1effc4dffa630bc8507f0c5f7?tpId=40&rp=1&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan&difficulty=&judgeStatus=&tags=&title=进制&sourceUrl=&gioEnter=menu


/// @link https://www.nowcoder.com/practice/deb19498bc644f53a6a99905ef5ee01d?tpId=40&rp=1&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan&difficulty=&judgeStatus=&tags=&title=进制&sourceUrl=&gioEnter=menu

#include <string>
#include <iostream>

int mainConvert16to10() {
    std::string chs;
    while (std::cin >> chs) {
        if (chs.size()< 3) continue;
        long size = chs.size();
        long long ret = 0;
        for (int i = 2; i < size; i++) {
            ret *= 16;
            ret += chs[i] > '9' ? chs[i] - 'A' + 10 : chs[i] - '0';
        }
        std::cout << ret << std::endl;
    }
    return 0;
}


/// 最大公约数
/// @link https://www.nowcoder.com/practice/20216f2c84bc438eb5ef05e382536fd3?tpId=40&tqId=21492&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan&difficulty=&judgeStatus=&tags=/question-ranking

int mainGCD() {
    int a, b;
    while (scanf("%d %d", &a, &b) != EOF) {
        while (a != 0 && b != 0) {
            if (a > b) a -= b;
            else b -= a;
        }
        printf("%d\n", a ? a : b);
    }
    return 0;
}


/// 练习
/// 求最小公倍数


/// 素数判定
/// @link https://www.nowcoder.com/practice/5fd9c28b1ce746dd99287a04d8fa9002?tpId=40&rp=1&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan&difficulty=&judgeStatus=&tags=&title=素&sourceUrl=&gioEnter=menu
#include <cmath>
int mainPrimeNumber() {
    int n;
    while (scanf("%d", &n) != EOF) {
        bool isPrime = true;
        int times = sqrt(n);
        for (int i = 2; i <= times; i++) {
            if (n % i == 0) {
                isPrime = false;
                break;
            }
        }
        if (n == 1) isPrime = false;
        printf("%s\n", isPrime ? "yes" : "no");
    }
    return 0;
}


/// 第k个质数
/// @link https://www.nowcoder.com/practice/c5f8688cea8a4a9a88edbd67d1358415?tpId=40&rp=1&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan&difficulty=&judgeStatus=&tags=&title=prim&sourceUrl=&gioEnter=menu

int mainKthPrimeNumber() {
#define MAXN 1000000
    bool primes[MAXN];
    std::fill(primes, primes + MAXN, true);
    primes[0] = false;
    primes[1] = false;
    for (int i = 2; i < 10000; i++) {
        if (i > MAXN / i) continue;
        for (int j = i; i * j < MAXN; j++) {
            primes[i * j] = false;
        }
    }
    int k;
    while (scanf("%d", &k) != EOF) {
        int count = 0;
        int i;
        for (i = 0; i < MAXN && count < k; i++) {
            if (primes[i]) count++;
        }
        printf("%d\n", i - 1);
    }
    return 0;
}


/// 练习
