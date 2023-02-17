//
//  ReadWriteFile.hpp
//  CTest
//
//  Created by 赫拉 on 2023/2/11.
//

#ifndef ReadWriteFile_hpp
#define ReadWriteFile_hpp

#include <cstdio>
#include <string>

class ReadWriteFile {
    
public:
    static void write(std::string path);
    static void read(std::string path);
};

#endif /* ReadWriteFile_hpp */
