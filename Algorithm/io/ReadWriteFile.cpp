//
//  ReadWriteFile.cpp
//  CTest
//
//  Created by 赫拉 on 2023/2/11.
//

#include "ReadWriteFile.hpp"

typedef struct StudentInfo {
    char *name;
    int age;
    int sex;
    
    StudentInfo() {
        name = new char[255];
        age = 0;
        sex = 0;
    }
    
    ~StudentInfo() {
        if (name != nullptr) delete name;
        age = 0;
        sex = 0;
    }
} StudentInfo;

void ReadWriteFile::write(std::string path) {
    FILE *file = nullptr;
    if ((file = fopen(path.data(), "wb+")) == nullptr) {
        fprintf(stderr, "error to open file %s\n", path.data());
        return;
    }
    
    int size = 0;
    printf("输入学生人数: ");
    scanf("%d", &size);
    printf("\n 学生信息格式: \n张三 12 1\n");
    printf("输入学生信息:\n");
    StudentInfo *students = new StudentInfo[size];
    for (int i = 0; i < size; i++) {
        StudentInfo *student = students + i;
        scanf("%s %d %d", student->name, &(student->age), &(student->sex));
    }
    for (int i = 0; i < size; i++) {
        fwrite(students+i, sizeof(StudentInfo), 1, file);
    }
    delete[] students;
    fclose(file);
}

void ReadWriteFile::read(std::string path) {
    FILE *file = fopen(path.data(), "rb");
    if (file == nullptr) {
        fprintf(stderr, "%s failed to open", path.data());
        return;
    }
    
    StudentInfo student;
    while (!feof(file)) {
        size_t wroteCount = fread(&student, sizeof(StudentInfo), 1, file);
        if (wroteCount != 1) {
            break;
        }
        printf("name: %s age: %d sex: %d\n", student.name, student.age, student.sex);
    }
    fclose(file);
}
