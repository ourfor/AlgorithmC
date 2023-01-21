//
//  QueueTest.cpp
//  CTest
//
//  Created by 梁甜 on 2023/1/11.
//

#include "QueueTest.hpp"

#include <queue>
#include <string>
#include <iostream>

/// 复数集合
/// @link https://www.nowcoder.com/practice/abdd24fa839c414a9b83aa9c4ecd05cc

typedef struct MyComplexNumber {
    int real;
    int image;
    
    bool operator<(const MyComplexNumber& other) const {
        if (real * real + image * image < other.real * other.real + other.image * other.image) {
            return true;
        }
        return false;
    }
    
    friend std::istream& operator>>(std::istream& in, MyComplexNumber& number) {
        scanf("%d+i%d", &number.real, &number.image);
        return in;
    }
    
    friend std::ostream& operator<<(std::ostream& out, const MyComplexNumber& number) {
        printf("%d+i%d", number.real, number.image);
        return out;
    }
} ComplexNumber;

void mainComplexNumber() {
    int num = 0;
    std::string cmd;
    std::priority_queue<ComplexNumber> queue;
    while (scanf("%d", &num) != EOF) {
        std::cin >> cmd;
        if (cmd == "Pop") {
            if (queue.empty()) {
                std::cout << "empty" << std::endl;
            } else {
                ComplexNumber number = queue.top();
                std::cout << number << std::endl;
                queue.pop();
                std::cout << "SIZE = " << queue.size() << std::endl;
            }
        } else if (cmd == "Insert") {
            ComplexNumber number;
            std::cin >> number;
            queue.push(number);
            std::cout << "SIZE = " << queue.size() << std::endl;
        } else {
            
        }
    }
}

