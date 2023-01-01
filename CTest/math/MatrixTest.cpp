//
//  MatrixTest.cpp
//  CTest
//
//  Created by 梁甜 on 2023/1/1.
//

#include "MatrixTest.hpp"

#define MAXN 100
typedef struct Matrix {
    int col;
    int row;
    int data[MAXN][MAXN];
    
    Matrix(int row, int col) {
        this->col = col;
        this->row = row;
    }
    
    Matrix operator+(Matrix other) {
        Matrix ans(row, col);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                ans.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return ans;
    }
    
    Matrix operator*(Matrix other) {
        Matrix ans(row, other.col);
        for (int i = 0; i < ans.row; i++) {
            for (int j = 0; j < ans.col; j++) {
                int sum = 0;
                for (int k = 0; k < ans.col; k++) {
                    sum += data[i][k] * other.data[k][j];
                }
                ans.data[i][j] = sum;
            }
        }
        return ans;
    }
    
    Matrix operator^(int n) {
        Matrix ans(row, col);
        Matrix x(row, col);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                ans.data[i][j] = i == j ? 1 : 0;
                x.data[i][j] = data[i][j];
            }
        }
        
        while (n) {
            if (n % 2) {
                ans = ans + x;
            }
            
            n /= 2;
            x = x * x;
        }
        
        return ans;
    }
} Matrix;


/// 练习
/// 矩阵幂
/// @link https://www.nowcoder.com/practice/31e539ab08f949a8bece2a7503e9319a?tpId=40&tqId=21523&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan&difficulty=&judgeStatus=&tags=/question-ranking
void QuickMatrixPower() {
    int n, k;
    while (scanf("%d %d", &n, &k) != EOF) {
        Matrix ans(n, n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &(ans.data[i][j]));
            }
        }
        
        ans = ans ^ k;
        
        for (int i = 0; i < ans.row; i++) {
            for (int j = 0; j < ans.col; j++) {
                printf("%d ", ans.data[i][j]);
            }
            printf("\n");
        }
    }
}
