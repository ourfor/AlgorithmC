//
//  main.cpp
//  CTest
//
//  Created by 梁甜 on 2022/12/28.
//

#include "ReadWriteFile.hpp"

/// 牛客网考研专区
/// @link https://www.nowcoder.com/ta/kaoyan
/// POJ
/// @link http://poj.org
/// 杭电OJ
/// @link https://acm.hdu.edu.cn

int main(int argc, const char * argv[]) {
    // insert code here...
    ReadWriteFile::write("/tmp/student.data");
    ReadWriteFile::read("/tmp/student.data");
    return 0;
}
