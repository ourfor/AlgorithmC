//
//  QueueTest.cpp
//  CTest
//
//  Created by 梁甜 on 2022/12/30.
//

#include "QueueTest.hpp"

#include <queue>


typedef struct Animal {
    int number;
    int order;
    Animal() {}
    Animal(int number, int order) {
        this->number = number;
        this->order = order;
    }
} Animal;

/// 猫狗收容所
/// @link https://www.nowcoder.com/questionTerminal/8a7e04cff6a54b7095b94261d78108f5
int mainAdoptAnimal() {
    std::queue<Animal> cat;
    std::queue<Animal> dog;
    
    int n;
    scanf("%d", &n);
    int order = 0;
    int number = 0;
    int type = 0;
    while (n--) {
        scanf("%d %d", &type, &number);
        if (type == 1) {
            Animal animal(number, order);
            if (number > 0) dog.push(animal);
            else cat.push(animal);
        } else {
            Animal animal;
            if (number == 0) {
                if (!dog.empty() && !cat.empty()) {
                    if (dog.front().order < cat.front().order) {
                        animal = dog.front();
                        dog.pop();
                    } else {
                        animal = cat.front();
                        cat.pop();
                    }
                } else if (dog.empty() && !cat.empty()) {
                    animal = cat.front();
                    cat.pop();
                } else if (!dog.empty() && cat.empty()) {
                    animal = dog.front();
                    dog.pop();
                } else {
                    continue;
                }
            } else if (number == 1) {
                if (!dog.empty()) {
                    animal = dog.front();
                    dog.pop();
                } else {
                    continue;
                }
            } else {
                if (!cat.empty()) {
                    animal = cat.front();
                    cat.pop();
                } else {
                    continue;
                }
            }
            printf("%d ", animal.number);
            order++;
        }
    }
    
    return 0;
}
