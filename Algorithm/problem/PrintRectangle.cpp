//
//  PrintRectangle.cpp
//  CTest
//
//  Created by 赫拉 on 2023/2/11.
//

#include "PrintRectangle.hpp"
#include <vector>

/// 顺时针打印矩阵
/// @link https://www.acwing.com/problem/content/39/
class PrintRectangleSolution {
public:
    std::vector<int> printMatrix(std::vector<std::vector<int> > matrix) {
        std::vector<int> result;
        int row = (int)matrix.size();
        if (row == 0) {
            return result;
        }
        int column = (int)matrix[0].size();
        int loopCount = row / 2 + 1;
        for (int i = 0; i < loopCount; i++) {
            int startRow = i, startColumn = i;
            int endRow = row - i - 1, endColumn = column - i - 1;
            if (startRow >= endRow || startColumn >= endColumn) {
                if (startRow == endRow) {
                    for (int i = startColumn; i <= endColumn; i++) {
                        result.push_back(matrix[startRow][i]);
                    }
                } else if (startColumn == endColumn) {
                    for (int i = startRow; i <= endRow; i++) {
                        result.push_back(matrix[i][startColumn]);
                    }
                }
                break;
            }
            
            for (int j = startColumn; j < endColumn; j++) {
                result.push_back(matrix[startRow][j]);
            }
            
            for (int j = startRow; j < endRow; j++) {
                result.push_back(matrix[j][endColumn]);
            }
            
            for (int j = endColumn; j > startColumn; j--) {
                result.push_back(matrix[endRow][j]);
            }
            
            for (int j = endRow; j > startRow; j--) {
                result.push_back(matrix[j][startColumn]);
            }
            
            if (result.size() == row * column) {
                break;
            }
        }
        return result;
    }
};
