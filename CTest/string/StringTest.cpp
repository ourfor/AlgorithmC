//
//  StringTest.cpp
//  CTest
//
//  Created by 梁甜 on 2022/12/30.
//

#include "StringTest.hpp"
#include <string>
#include <iostream>

///@link https://www.nowcoder.com/practice/a5edebf0622045468436c74c3a34240f?tpId=40&tqId=21349&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan&difficulty=&judgeStatus=&tags=/question-ranking
int mainInputString() {
    std::string a, b;
    std::cin >> a >> b;
    int result = 0;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            result += (a[i] - '0') * (b[j] - '0');
        }
    }
    std::cout << result << std::endl;
    return 0;
}


/// @link https://www.nowcoder.com/practice/ff99c43dd07f4e95a8f2f5448da3772a?tpId=40&rp=1&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan&difficulty=&judgeStatus=&tags=&title=简单密码&sourceUrl=&gioEnter=menu
int mainInputLine() {
    std::string line;
    while (getline(std::cin, line)) {
        if (line == "ENDOFINPUT") break;
        getline(std::cin, line);
        for (int i = 0; i < line.size(); i++) {
            if (line[i] >= 'A' && line[i] <= 'Z') {
                int offset = ((line[i] - 'A') - 5 + 26) % 26;
                line[i] = 'A' + offset;
            }
        }
        std::cout << line << std::endl;
        getline(std::cin, line);
    }
    return 0;
}

///@link https://www.nowcoder.com/practice/4ec4325634634193a7cd6798037697a8?tpId=40&rp=1&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan&difficulty=&judgeStatus=&tags=&title=统计字符&sourceUrl=&gioEnter=menu
int mainInputCharCount() {
    std::string tmp, line;
    int counter[256] = {0};
    while (getline(std::cin, tmp)) {
        if (tmp == "#") break;
        
        getline(std::cin, line);
        for (int i = 0; i < tmp.size(); i++) {
            counter[tmp[i]] = 0;
        }
        
        for (int i = 0; i < line.size(); i++) {
            counter[line[i]]++;
        }
        
        for (int i = 0; i < tmp.size(); i++) {
            std::cout << tmp[i] << " " << counter[tmp[i]] << std::endl;
        }
    }
    return 0;
}

///@link http://poj.org/problem?id=3461

void initNextTable(std::string pattern, int *next) {
    int m = (int)pattern.size();
    int i = 0;
    next[i] = -1;
    int j = next[i];
    while (i < m) {
        if (j == -1 || pattern[i] == pattern[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
}

int KMP(std::string text, std::string pattern) {
    int n = (int)text.size();
    int m = (int)pattern.size();
    int i = 0;
    int j = 0;
    int *next = new int[m + 1];
    initNextTable(pattern, next);
    while (i < n && j < m) {
        if (j == -1 || text[i] == pattern[j]) {
            i++;
            j++;
//            next[j + 1] = next[j] + 1;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
    delete[] next;
    return -1;
}

int mainStringMatch() {
    
    return 0;
}
