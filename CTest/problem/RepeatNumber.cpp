//
//  RepeatNumber.cpp
//  CTest
//
//  Created by 赫拉 on 2023/2/11.
//

#include "RepeatNumber.hpp"
#include <vector>
#include <string>

/// 找出数组中重复的数字
/// @link https://www.acwing.com/problem/content/14/
class RepeatNumberSolution {
public:
    int duplicateInArray(std::vector<int>& nums) {
        const int size = (int)nums.size();
        int *counts = new int[size];
        for (int i = 0; i < size; i++) counts[i] = 0;
        int repeatNumber = -1;
        for (int i = 0; i < size; i++) {
            int num = nums[i];
            if (num < 0 || num >= size) return -1;
            counts[num]++;
            if (counts[num] > 1) {
                repeatNumber = num;
            }
        }
        return repeatNumber;
    }
};


/// 不修改数组找出重复的数字
/// @link https://www.acwing.com/problem/content/15/
class RepeatNumberWithModifySolution {
public:
    int duplicateInArray(std::vector<int>& nums) {
        int size = (int)nums.size();
        int startPosition = 0;
        int repeatNumber = -1;
        for (int i = 1; i <= size; i++) {
            int count = 0;
            for (int j = 0; j <= size; j++) {
                if (nums[j] == i) {
                    count++;
                }
                
                if (count > 1) {
                    repeatNumber = i;
                }
            }
        }
        return repeatNumber;
    }
};
