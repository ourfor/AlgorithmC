//
//  ReplaceWhiteSpaceChar.cpp
//  CTest
//
//  Created by 赫拉 on 2023/2/11.
//

#include "ReplaceWhiteSpaceChar.hpp"
#include <string>

/// 替换空格
/// @link https://www.acwing.com/problem/content/17/
class ReplaceWhiteSpaceCharSolution {
public:
    std::string replaceSpaces(std::string &str) {
        int size = (int)str.size();
        std::string newString = "";
        for (int i = 0; i < size; i++) {
            char ch = str[i];
            if (ch == ' ') {
                newString.append("%20");
            } else {
                newString.append(1, ch);
            }
        }
        return newString;
    }
};
