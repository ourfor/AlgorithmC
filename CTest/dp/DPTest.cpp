//
//  DPTest.cpp
//  CTest
//
//  Created by 赫拉 on 2023/2/2.
//

#include "DPTest.hpp"
#include <iostream>

/// 最大连续子序列和
/// @link https://www.nowcoder.com/practice/afe7c043f0644f60af98a0fba61af8e7
void mainMaxSumOfSubSequence() {
    int n = 0;
    while (std::cin >> n) {
        if (!n) break;
        int *array = new int[n];
        int *sum = new int[n];
        int *start = new int[n];
        int *end = new int[n];
        for (int i = 0; i < n; i++) {
            std::cin >> array[i];
        }
        
        sum[0] = array[0];
        start[0] = 0;
        end[0] = 0;
        int j = 0;
        for (int i = 1; i < n; i++) {
            if (sum[i - 1] > 0) {
                sum[i] = sum[i - 1] + array[i];
                start[i] = start[i - 1];
                end[i] = i;
            } else {
                sum[i] = array[i];
                start[i] = i;
                end[i] = i;
            }
            
            if (sum[i] > sum[j]) {
                j = i;
            }
        }
        
        if (sum[j] < 0) {
            std::cout << 0 << " " << array[0] << " " << array[n - 1] << std::endl;
        } else {
            std::cout << sum[j] << " " << array[start[j]] << " " << array[end[j]] << std::endl;
        }
        
        delete[] array;
        delete[] sum;
        delete[] start;
        delete[] end;
    }
}


/// 最大序列和
/// @link https://www.nowcoder.com/practice/df219d60a7af4171a981ef56bd597f7b
void mainMaxSubSequenceSum() {
    int n = 0;
    while (std::cin >> n) {
        int *array = new int[n];
        for (int i = 0; i < n; i++) {
            std::cin >> array[i];
        }
        
        int prevSum = array[0];
        int currSum = 0;
        int maxSum = prevSum;
        for (int i = 1; i < n; i++) {
            if (prevSum > 0) {
                currSum = prevSum + array[i];
            } else {
                currSum = array[i];
            }
            prevSum = currSum;
            if (currSum > maxSum) {
                maxSum = currSum;
            }
        }
        
        std::cout << maxSum << std::endl;
        
        delete[] array;
    }
}


/// 最长递增子序列
/// @link http://poj.org/problem?id=2533
void mainLongestSubSequence() {
    int n = 0;
    while (std::cin >> n) {
        int *array = new int[n];
        for (int i = 0; i < n; i++) {
            std::cin >> array[i];
        }
        
        int prev = array[0], curr = 0;
        int *len = new int[n];
        len[0] = 1;
        int result = 1;
        for (int i = 1; i < n; i++) {
            curr = array[i];
            len[i] = 1;
            for (int j = i - 1; j >= 0; j--) {
                if (curr > array[j]) {
                    if (len[j] + 1 > len[i]) {
                        len[i] = len[j] + 1;
                    }
                }
            }
            
            prev = curr;
            
            if (len[i] > result) {
                result = len[i];
            }
        }
        
        std::cout << result << std::endl;
        delete [] array;
        delete [] len;
    }
}


typedef struct Matrix2 {
    int row = -1;
    int column = -1;
    int **data = nullptr;
    
    Matrix2(int row, int column) {
        this->row = row;
        this->column = column;
        if (row > 0) {
            data = new int*[row];
        }
        
        for (int i = 0; i < row; i++) {
            data[i] = new int[column];
        }
    }
    
    int* operator[](int m) {
        return data[m];
    }
    
    ~Matrix2() {
        row = -1;
        column = -1;
        if (data == nullptr) return;
        
        for (int i = 0; i < row; i++) {
            delete[] data[i];
        }
        delete[] data;
    }
    
} Matrix2;

//int memo[1000][1000];

int commonSubsequence(const std::string& a, int i, const std::string& b, int j, Matrix2& memo) {
    if (i == -1 || j == -1) {
        return 0;
    }
    
    if (memo[i][j] != -1) {
        return memo[i][j];
    }
    
    if (a[i] == b[j]) {
        int max = commonSubsequence(a, i - 1, b, j - 1, memo);
        if (i > 0 && j > 0) memo[i-1][j-1] = max;
        return max + 1;
    } else {
        int max1 = commonSubsequence(a, i - 1, b, j, memo);
        int max2 = commonSubsequence(a, i, b, j - 1, memo);
        if (i > 0 && j >= 0) memo[i-1][j] = max1;
        if (i >= 0 && j > 0) memo[i][j-1] = max2;
        return max1 > max2 ? max1 : max2;
    }
}

int commonSubsequence2(const std::string& a, int m, const std::string& b, int n, Matrix2& memo) {
    if (m == -1 || n == -1) {
        return 0;
    }
    
    memo[0][0] = a[0] == b[0] ? 1 : 0;
    
    for (int i = 0; i <= m; i++) memo[i][0] = a[i] == b[0] ? 1 : 0;
    for (int j = 0; j <= n; j++) memo[0][j] = a[0] == b[j] ? 1 : 0;
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i] == b[j]) {
                memo[i][j] = memo[i-1][j-1] + 1;
            } else {
                int max1 = memo[i-1][j];
                int max2 = memo[i][j-1];
                memo[i][j] = max1 > max2 ? max1 : max2;
            }
        }
    }
    return memo[m][n];
}

/// 最长公共子序列
/// @link http://poj.org/problem?id=1458
void mainLongestCommonSubSequence() {
    std::string a = "";
    std::string b = "";
    while (std::cin >> a >> b) {
        int row = (int)a.size();
        int column = (int)b.size();
        Matrix2 memo(row, column);
        // flush memo cache
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                memo[i][j] = -1;
            }
        }
        int max = commonSubsequence2(a, row - 1, b, column - 1, memo);
        std::cout << max << std::endl;
    }
}

typedef struct FoodInfo {
    int price;
    int rate;
    
    friend std::istream& operator>>(std::istream &in, FoodInfo &food) {
        in >> food.price >> food.rate;
        return in;
    }
} FoodInfo;

/// 0/1背包
/// @link https://www.nowcoder.com/practice/b44f5be34a9143aa84c478d79401e22a
void mainBuyFood() {
    int money = 0, total = 0;
    while (std::cin >> money >> total) {
        FoodInfo *foods = new FoodInfo[total];
        for (int i = 0; i < total; i++) {
            std::cin >> foods[i];
        }
        int *bags = new int[total];
        for (int i = 0; i <= money; i++) bags[i] = 0;
        for (int i = 1; i <= total; i++) {
            FoodInfo food = foods[i-1];
            for (int j = money; j >= food.price; j--) {
                int max1 = bags[j - food.price] + food.rate;
                if (max1 > bags[j]) {
                    bags[j] = max1;
                }
            }
        }
        std::cout << bags[money] << std::endl;
        delete[] foods;
    }
}

/// 完全背包
/// @link hdu 4508
/// @link https://www.acwing.com/problem/content/3/



/// 多重背包
/// @link 
