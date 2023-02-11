//
//  MultiBag.cpp
//  CTest
//
//  Created by 赫拉 on 2023/2/11.
//

#include "MultiBag.hpp"

#include <iostream>
#include <vector>

typedef struct Stuff {
    int volume;
    int value;
    int size;
    
    Stuff() {
        volume = 0;
        value = 0;
        size = 0;
    }
    
    Stuff(int volume, int value, int size = 1) {
        this->volume = volume;
        this->value = value;
        this->size = size;
    }
    
    friend std::istream& operator>>(std::istream& in, Stuff &stuff) {
        in >> stuff.volume >> stuff.value >> stuff.size;
        return in;
    }
} Stuff;

/// 多重背包
/// @link https://www.acwing.com/problem/content/4/
class MultiBagSolution {
public:
    static void main() {
        int stuffSize = 0, bagCapacity = 0;
        while (std::cin >> stuffSize >> bagCapacity) {
            Stuff *stuffs = new Stuff[stuffSize];
            for (int i = 0; i < stuffSize; i++) std::cin >> stuffs[i];
            std::vector<Stuff> newStuffs;
            for (int i = 0; i < stuffSize; i++) {
                Stuff stuff = stuffs[i];
                int mask = 0x1;
                // std::cout << stuff.size << " = ";
                for (int j = 1; j < 32 && stuff.size > 0; j++) {
                    int size = stuff.size > mask ? mask : stuff.size;
                    if (size) {
                        // std::cout << size << " ";
                        newStuffs.push_back(Stuff(size * stuff.volume, size * stuff.value));
                        stuff.size -= size;
                    }
                    mask <<= 1;
                }
                // std::cout << std::endl;
            }
            
            int newStuffSize = newStuffs.size();
            int *bag = new int[bagCapacity + 1];
            for (int i = 0; i <= bagCapacity; i++) bag[i] = 0;
            for (int i = 0; i < newStuffSize; i++) {
                Stuff stuff = newStuffs[i];
                for (int j = bagCapacity; j >= stuff.volume; j--) {
                    int newValue = bag[j - stuff.volume] + stuff.value;
                    if (newValue > bag[j]) {
                        bag[j] = newValue;
                    }
                }
            }
            
            int maxValue = bag[bagCapacity];
            delete[] bag;
            delete[] stuffs;
            std::cout << maxValue << std::endl;
        }
    }
};
