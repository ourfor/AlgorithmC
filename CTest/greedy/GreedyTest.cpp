//
//  GreedyTest.cpp
//  CTest
//
//  Created by 梁甜 on 2023/1/2.
//

#include "GreedyTest.hpp"

/// 练习
/// 猫粮换咖啡豆
/// @link http://acm.hdu.edu.cn/showproblem.php?pid=1009

#include <iostream>
#include <algorithm>
#include <cstdio>

typedef struct JavaBean {
    double weight;
    double cost;
    
    bool operator<(JavaBean other) const {
        return weight / cost > other.weight / other.cost;
    }
    
    friend std::istream& operator>>(std::istream& in, JavaBean& bean) {
        in >> bean.weight >> bean.cost;
        return in;
    }
} JavaBean;

void mainBuyJavaBean() {
    int m, n;
    while (std::cin >> m >> n) {
        if (n == -1 && m == -1) break;
        JavaBean *beans = new JavaBean[n];
        for (int i = 0; i < n; i++) {
            std::cin >> beans[i];
        }
        
        std::sort(beans, beans+n);
        
        double sum = 0;
        for (int i = 0; i < n; i++) {
            if (m > beans[i].cost) {
                sum += beans[i].weight;
                m -= beans[i].cost;
            } else {
                sum += (m / beans[i].cost) * beans[i].weight;
                break;
            }
        }
        
        printf("%.3lf\n", sum);
        
        delete[] beans;
    }
}


/// 练习
/// 打怪拿奖金
/// @link http://acm.hdu.edu.cn/showproblem.php?pid=5281
void mainShotWithBonus() {
    int caseN = 0;
    long long n, m;
    scanf("%d", &caseN);
    while (caseN--) {
        scanf("%lld %lld", &n, &m);
        long long *guns = new long long[n];
        for (int i = 0; i < n; i++) {
            scanf("%lld", guns + i);
        }
        long long *monsters = new long long[m];
        for (int i = 0; i < m; i++) {
            scanf("%lld", monsters + i);
        }
        std::sort(guns, guns + n, [](long long a, long long b) -> bool {
            return a > b;
        });
        std::sort(monsters, monsters + m, [](long long a, long long b) -> bool {
            return a < b;
        });
        long long bonus = 0;
        for (int i = 0; i < m && i < n; i++) {
            if (guns[i] > monsters[i]) {
                bonus += guns[i] - monsters[i];
            } else {
                break;
            }
        }
        printf("%lld\n", bonus);
        delete[] guns;
        delete[] monsters;
    }
    
}

/// 练习
/// 箱子打包
/// @link https://acm.ecnu.edu.cn/problem/1045/
///
/// 放牛
/// @link http://poj.org/problem?id=2456
bool isSafeGap(int *loc, int len, int cows, int gap) {
    int curr = loc[0];
    int num = 1;
    for (int i = 1; i < len; i++) {
        if (loc[i] - curr >= gap) {
            curr = loc[i];
            num++;
        }
        
        if (num >= cows) {
            return true;
        }
    }
    return false;
}

void mainPutCow() {
    int n, c;
    while (scanf("%d %d", &n, &c) != EOF) {
        int *loc = new int[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", loc + i);
        }
        std::sort(loc, loc + n);
        int low = 1, high = loc[n - 1] - loc[0];
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isSafeGap(loc, n, c, mid)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        delete[] loc;
        printf("%d\n", high);
    }
}


/// 练习
/// 烘干衣物
/// @link http://poj.org/problem?id=3104


/// 练习
/// 今年暑假不AC
/// @link http://acm.hdu.edu.cn/showproblem.php?pid=2037
typedef struct Program {
    int startTime;
    int endTime;
    
    friend std::istream& operator>>(std::istream& in, Program& program) {
        in >> program.startTime >> program.endTime;
        return in;
    }
    
    bool operator<(Program other) const {
        return endTime < other.endTime;
    }
} Program;

void mainWatchMoreProgram() {
    int n;
    while (std::cin >> n) {
        if (!n) break;
        
        Program *programs = new Program[n];
        for (int i = 0; i < n; i++) {
            std::cin >> programs[i];
        }
        
        std::sort(programs, programs + n);
        
        int ans = 0;
        int currTime = 0;
        for (int i = 0; i < n; i++) {
            if (currTime <= programs[i].startTime) {
                ans++;
                currTime = programs[i].endTime;
            }
        }
        delete[] programs;
        std::cout << ans << std::endl;
    }
}


/// 练习
/// 雷达安装问题
/// @link http://poj.org/problem?id=1328



