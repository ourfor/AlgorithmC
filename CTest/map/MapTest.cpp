//
//  MapTest.cpp
//  CTest
//
//  Created by 梁甜 on 2023/1/12.
//

#include "MapTest.hpp"
#include <iostream>
#include <string>
#include <map>

typedef struct Student {
    std::string id;
    std::string name;
    int sex;
    int age;
    
    friend std::istream& operator>>(std::istream& in, Student& student) {
        std::string sexString;
        in >> student.id >> student.name >> sexString >> student.age;
        if (sexString == "男") {
            student.sex = +1;
        } else if (sexString == "女") {
            student.sex = -1;
        } else {
            student.sex = 0;
        }
        return in;
    }
    
    friend std::ostream& operator<<(std::ostream& out, const Student& student) {
        out << student.id << " " << student.name << " ";
        out << (student.sex == 1 ? "男" : (student.sex == -1 ? "女": "")) << " ";
        out << student.age;
        return out;
    }
} Student;

/// 查找学生信息
/// @link https://www.nowcoder.com/practice/fe8bff0750c8448081759f3ee0d86bb4
void mainFindStudentInfo() {
    using namespace std;
    int total = 0;
    std::map<std::string, Student> students;
    while (std::cin >> total) {
        while (total--) {
            Student student;
            std::cin >> student;
            students[student.id] = student;
        }
        int ops = 0;
        std::cin >> ops;
        std::string id;
        while (ops--) {
            std::cin >> id;
            /// Student student = students[id];
            /// check if student.id equals to id
            if (students.contains(id)) {
                std::cout << students[id] << std::endl;
            } else {
                std::cout << "No Answer!" << std::endl;
            }
        }
    }
    
}
