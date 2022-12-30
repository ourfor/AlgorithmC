//
//  main.cpp
//  CTest
//
//  Created by 梁甜 on 2022/12/28.
//

#include <iostream>
#include <string>

/// @link https://www.nowcoder.com/ta/kaoyan

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    std::string hello = "Hello World";
    std::string other = "Smith";
    hello.append(" ").append(other);
    for (int i = 0; i < hello.size(); i++) {
        printf("%c ", hello[i]);
    }
    printf("\n");
    return 0;
}
