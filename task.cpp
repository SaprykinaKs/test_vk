// файл с графом - graph.txt
// граф ненаправленный, вес ребер одинаковый - оптимально использовать bfs

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

void bfs(const std::vector<std::vector<int>>& graph, int start) {
    int n = graph.size();
    std::vector<int> distance(n, -1);
    std::queue<int> q;
    
    distance[start] = 0;
    q.push(start);
    
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int neighbor : graph[v]) {
            if (distance[neighbor] == -1) {
                distance[neighbor] = distance[v] + 1;
                q.push(neighbor);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        std::cout << distance[i] << "\n";
    }
}

int main() {
    std::ifstream file("graph.txt");
    if (!file) {
        std::cerr << "ошибка открытия файла" << std::endl;
        return 1;
    }
    
    int vertices, edges, start;
    file >> vertices >> edges;
    
    std::vector<std::vector<int>> graph(vertices);
    
    for (int i = 0; i < edges; i++) {
        int u, v;
        file >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    file >> start;
    file.close();
    
    bfs(graph, start);
    
    return 0;
}