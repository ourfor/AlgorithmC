//
//  SearchTest.cpp
//  CTest
//
//  Created by 梁甜 on 2023/1/3.
//

#include "SearchTest.hpp"
#include <queue>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

/// 抓住那头牛
/// @link http://poj.org/problem?id=3278
const int MAXN = 1e5 + 10;
bool visited[MAXN];
typedef struct State {
    long long position;
    int minutes;
    
    State(long long position, int minutes) {
        this->position = position;
        this->minutes = minutes;
    }
} State;

void mainCatchThatCow1() {
    long long n, k;
    scanf("%lld %lld", &n, &k);
    {
        std::queue<State> queue;
        State curr(n, 0);
        queue.push(curr);
        visited[n] = true;
        memset(visited, false, sizeof(visited));
        long long result = 0;
        while (!queue.empty()) {
            curr = queue.front();
            queue.pop();
            if (curr.position == k) {
                result = curr.minutes;
                break;
            }
            
            for (int i = 0; i < 3; i++) {
                State next = curr;
                if (i == 0) {
                    next.position += 1;
                } else if (i == 1) {
                    next.position -= 1;
                } else {
                    next.position *= 2;
                }
                
                next.minutes++;
                
                if (next.position < 0 ||
                    next.position > MAXN ||
                    visited[next.position]) {
                    continue;
                }
                
                queue.push(next);
                visited[next.position] = true;
            }
        }
        std::cout << result << std::endl;
    }
}

void mainCatchThatCow() {
    int n, k;
    const int MAXN = 1e5 + 10;
    bool *visited = new bool[MAXN];
    memset((void *)visited, false, sizeof(visited));
    std::cin >> n >> k;
    {
        std::queue<int> queue;
        queue.push(n);
        visited[n] = true;
        int minutes = 0;
        int curr;
        while (!queue.empty()) {
            if (visited[k]) break;
            long long size = queue.size();
            while (size--) {
                curr = queue.front();
                queue.pop();
                if (curr - 1 > 0 && !visited[curr - 1]) {
                    queue.push(curr - 1);
                    visited[curr - 1] = true;
                }
                if (curr + 1 < k + 1 && !visited[curr + 1]) {
                    queue.push(curr + 1);
                    visited[curr + 1] = true;
                }
                if (curr * 2 < 2 * k + 1 && curr * 2 > 0 && !visited[curr * 2]) {
                    queue.push(curr * 2);
                    visited[curr * 2] = true;
                }
            }
            minutes++;
        }
        std::cout << minutes << std::endl;
    }
    delete[] visited;
}

/// 练习
/// @link http://poj.org/problem?id=1426



/// 练习
/// @link http://poj.org/problem?id=2488
typedef struct Square {
    int x;
    int y;
    
    Square(int ax, int ay): x(ax), y(ay) {}
    Square operator+(Square delta) {
        return Square(x + delta.x, y + delta.y);
    }
    
    std::string location() {
        char loc[2] = {'A', '1'};
        loc[0] += y;
        loc[1] += x;
        return std::string(loc, 0, 2);
    }
    
    bool isInBoard(int x, int y) {
        bool inValid = (
            this->x < 0 ||
            this->y < 0 ||
            this->x >= x ||
            this->y >= y
        );
        return !inValid;
    }
} Square;

Square direction[8] = {
    Square(-1, -2), Square(1, -2),
    Square(-2, -1), Square(2, -1),
    Square(-2,  1), Square(2,  1),
    Square(-1,  2), Square(1, 2)
};

#define KNIGHT_MAXN 36
bool knightVisited[KNIGHT_MAXN][KNIGHT_MAXN];

bool KnightDFS(Square root, std::string path, int step, int borderX, int borderY) {
    if (step == borderX * borderY) {
        std::cout << path << std::endl;
        return true;
    }
    
    for (int i = 0; i < 8; i++) {
        Square next = root + direction[i];
        if (!next.isInBoard(borderX, borderY) ||
            knightVisited[next.x][next.y]) continue;
        
        knightVisited[next.x][next.y] = true;
        bool isReached = KnightDFS(
            next,
            path + next.location(),
            step + 1,
            borderX,
            borderY
        );
        knightVisited[next.x][next.y] = false;
        
        if (isReached) return true;
    }
    return false;
}
void mainKnightJourney() {
    int caseNum, borderX, borderY;
    std::cin >> caseNum;
    int i = 1;
    while (caseNum--) {
        std::cin >> borderX >> borderY;
        memset(knightVisited, false, KNIGHT_MAXN * KNIGHT_MAXN);
        Square root(0, 0);
        knightVisited[0][0] = true;
        std::cout << "Scenario #" << i++ << ":" << std::endl;
        if (KnightDFS(root, root.location(), 1, borderX, borderY)) {
            std::cout << std::endl;
        } else {
            std::cout << "impossible" << std::endl << std::endl;
        }
    }
}

/// 练习
/// @link http://poj.org/problem?id=2362
bool canBuildSquare(
    int *edges,
    bool *visited,
    int length,
    int completeEdgeNum,
    int root,
    int currentLength,
    int targetLength) {
    if (completeEdgeNum == 3) return true;
    for (int i = root; i < length; i++) {
        if (visited[i] || edges[i] > targetLength) {
            continue;
        }
        
        visited[i] = true;
        if (edges[i] + currentLength == targetLength) {
            if (canBuildSquare(edges, visited, length, completeEdgeNum + 1, 0, 0, targetLength)) return true;
        } else {
            if (canBuildSquare(edges, visited, length, completeEdgeNum, i, currentLength + edges[i], targetLength)) return true;
        }
        visited[i] = false;
    }
    return false;
}

void mainBuildSquare() {
    int caseNum = 0;
    std::cin >> caseNum;
    while (caseNum--) {
        int edgeNum = 0;
        std::cin >> edgeNum;
        int *edges = new int[edgeNum];
        bool *visited = new bool[edgeNum];
        memset(edges, 0, edgeNum * sizeof(int));
        memset(visited, false, edgeNum * sizeof(bool));
        for (int i = 0; i < edgeNum; i++) {
            std::cin >> edges[i];
        }
        std::sort(edges, edges + edgeNum);
        int sum = 0;
        for (int i = 0; i < edgeNum; i++) {
            sum += edges[i];
        }
        int targetLength = sum / 4;
        if (canBuildSquare(edges, visited, edgeNum, 0, 0, 0, targetLength)) {
            std::cout << "yes" << std::endl;
        } else {
            std::cout << "no" << std::endl;
        }
        delete[] edges;
        delete[] visited;
    }
}
