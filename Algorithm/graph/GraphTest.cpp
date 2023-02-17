//
//  GraphTest.cpp
//  CTest
//
//  Created by 梁甜 on 2023/1/13.
//

#include "GraphTest.hpp"
#include <iostream>
#include <algorithm>
#include <vector>

typedef struct Set {
    int root[1000];
    int height[1000];
    
    Set(int size = 1000) {
        for (int i = 0; i < size; i++) {
            root[i] = i;
            height[i] = 0;
        }
    }
    
    int find(int x) {
        if (root[x] != x) {
            root[x] = find(root[x]);
            return root[x];
        }
        return x;
    }
    
    void join(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY) {
            return;
        }
        
        if (height[rootX] > height[rootY]) {
            root[rootY] = rootX;
        } else if (height[rootY] > height[rootX]) {
            root[rootX] = rootY;
        } else {
            root[rootX] = rootY;
            height[rootX]++;
        }
        
    }
} Set;

/// 连通图
/// @link https://www.nowcoder.com/practice/569e89823a5141fe8a11ab7d4da21edf
void mainGraphComponent() {
    int nodes = 0, edges = 0;
    while (std::cin >> nodes >> edges) {
        if (nodes == 0 && edges == 0) {
            break;
        }
        Set set(nodes + 1);
        int node1 = 0, node2 = 0;
        for (int i = 0; i < edges; i++) {
            std::cin >> node1 >> node2;
            set.join(node1, node2);
        }
        
        int components = 0;
        for (int i = 1; i <= nodes; i++) {
            if (i == set.find(i)) {
                components++;
            }
        }
        std::cout << (components == 1 ? "YES" : "NO") << std::endl;
    }
}

typedef struct Edge {
    int from;
    int to;
    int weight;
    
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
    
    friend std::istream& operator>>(std::istream& in, Edge& edge) {
        in >> edge.from >> edge.to >> edge.weight;
        return in;
    }
} Edge;

/// 最小生成树
/// @link https://www.nowcoder.com/practice/d6bd75dbb36e410995f8673a6a2e2229
void mainMinimalTree() {
    int vertex = 0;
    while (std::cin >> vertex) {
        if (vertex == 0) {
            break;
        }
        int size = vertex * (vertex - 1) / 2;
        Edge *edges = new Edge[size];
        for (int i = 0; i < size; i++) {
            std::cin >> edges[i];
        }
        
        std::sort(edges, edges + size);
        
        Set set(vertex + 1);
        int cost = 0;
        for (int i = 0; i < size; i++) {
            Edge edge = edges[i];
            if (set.find(edge.from) == set.find(edge.to)) {
                continue;
            }
            
            cost += edge.weight;
            set.join(edge.from, edge.to);
        }
        
        std::cout << cost << std::endl;
        delete[] edges;
    }
}


/// 最短路径
/// @link

typedef struct GraphEdge {
    int from;
    int to;
    int weight;
    
    friend std::istream& operator>>(std::istream& in, GraphEdge& edge) {
        in >> edge.from >> edge.to >> edge.weight;
        return in;
    }
    
    GraphEdge reverse() {
        GraphEdge edge = {
            .from = to,
            .to = from,
            .weight = weight
        };
        return edge;
    }
} GraphEdge;

void shortestPath(int start, int n) {
    /**
     * do not use in product environment
     * just use in test
     */
#define GRAPH_MAX_NODES 200
    const int INF = INT_MAX;
    std::vector<GraphEdge> Graph[GRAPH_MAX_NODES];
    bool visited[GRAPH_MAX_NODES];
    int distance[GRAPH_MAX_NODES];
    
    
    memset(visited, false, GRAPH_MAX_NODES * sizeof(bool));
    std::fill(distance, distance + GRAPH_MAX_NODES, INF);
    distance[start] = 0;
    for (int i = 0; i < n; i++) {
        int from = -1;
        for (int j = 0; j < n; j++) {
            if (visited[i]) {
                continue;
            }
            
            if (from == -1 || distance[from] > distance[j]) {
                from = j;
            }
        }
        
        visited[from] = true;
        
        std::vector<GraphEdge> edges = Graph[from];
        int size = (int)edges.size();
        for (int i = 0; i < size; i++) {
            GraphEdge edge = edges[i];
            if (distance[edge.from] + edge.weight < distance[edge.to]) {
                distance[edge.to] = distance[edge.from] + edge.weight;
            }
        }
        
    }
}

/// 拓扑排序 (确定比赛名次)
/// @link hdu 1285
void TopoLogicalSort() {
#define MAXN 10
    std::vector<int> table[MAXN];
    int n = 0, i = 0, j = 0;
    std::cin >> n;
    while (std::cin >> i >> j) {
        table[i].push_back(j);
    }
    
    int indegree[MAXN];
    bool visited[MAXN];
    std::fill(indegree, indegree + MAXN, 0);
    std::fill(visited, visited + MAXN, false);
    for (int i = 0; i < n; i++) {
        std::vector<int> edges = table[i];
        int size = (int)edges.size();
        for (int j = 0; j < size; j++) {
            indegree[edges[i]]++;
        }
    }
    
    int visitedCount = 0;
    std::vector<int> order;
    for (int i = 0; i < n; i++) {
        int start = -1;
        for (int j = 0; j < n; j++) {
            if (indegree[j] == 0 && !visited[j]) {
                start = j;
                order.push_back(start);
                visitedCount++;
            }
        }
        
        if (start == -1 && visitedCount != n) {
            
        }
        
        std::vector<int> edges = table[start];
        int size = (int)edges.size();
        for (int j = 0; j < size; j++) {
            indegree[edges[j]]--;
        }
    }
    
    int size = (int)order.size();
    for (int i = 0; i < size; i++) {
        std::cout << order[i] << " ";
    }
}


/// 关键路径
/// @link

