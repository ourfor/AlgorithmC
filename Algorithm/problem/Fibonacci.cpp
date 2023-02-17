//
//  Fibonacci.cpp
//  CTest
//
//  Created by 赫拉 on 2023/2/11.
//

#include "Fibonacci.hpp"

/// 斐波那契数列
/// @link https://www.acwing.com/problem/content/19/
class FibonacciSolution {
public:
    int Fibonacci(int n) {
        int *array = new int[n + 1];
        array[0] = 0;
        array[1] = 1;
        for (int i = 2; i <= n; i++) {
            array[i] = array[i - 1] + array[i - 2];
        }
        int result = array[n];
        delete[] array;
        return result;
    }
};
