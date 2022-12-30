//
//  SortTest.cpp
//  CTest
//
//  Created by 梁甜 on 2022/12/29.
//

#include "SortTest.hpp"
#include <algorithm>

int mainSort() {
    int array[] = {1, 3, 5, 8, 2, 9, 6};
    std::sort(array, array + 7);
    for (int i = 0; i < 7; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}


typedef struct Student {
    int number;
    int score;
    
    bool operator<(Student other) const {
        if (score < other.score) return true;
        if (score == other.score) {
            return number < other.number;
        }
        return false;
    }
} Student;

Student students[101];

bool comp(Student a, Student b) {
    return a.score < b.score ? true : (a.score == b.score ? a.number < b.number : false);
}

int mainSortStudent() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d\n", &((students+i)->number), &((students+i)->score));
    }
    std::sort(students, students+n);
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", students[i].number, students[i].score);
    }
    return 0;
}


/// @link https://www.nowcoder.com/practice/bbbbf26601b6402c9abfa88de5833163?tpId=40&tqId=21398&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan&difficulty=&judgeStatus=&tags=/question-ranking

int mainSortOddAndEven() {
    int array[10];
    for (int i = 0; i < 10; i++) {
        scanf("%d", array + i);
    }
    std::sort(array, array + 10, [](int a, int b) -> bool {
        if (a % 2 == 1 && b % 2 == 1) {
            return a > b;
        } else if (a % 2 == 0 && b % 2 == 0) {
            return a < b;
        } else {
            return (a % 2) > (b % 2);
        }
    });
    
    for (int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}
