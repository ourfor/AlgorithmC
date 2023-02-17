//
//  SingleNumber.cpp
//  Algorithm
//
//  Created by 赫拉 on 2023/2/16.
//

#include "SingleNumber.hpp"
#include <vector>

/// 只出现一次的数字
/// @link https://leetcode.cn/problems/single-number/
class SingleNumberSolution {
public:
    int singleNumber(std::vector<int>& nums) {
        int size = (int)nums.size();
        int result = 0;
        for (int i = 0; i < size; i++) {
            result ^= nums[i];
        }
        return result;
    }
};
