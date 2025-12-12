#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <limits>
#include <string>

struct Edge {
    std::string node;
    int weight;

    Edge(const std::string& n, int w) : node(n), weight(w) {}
};

struct NodeDistance {
    std::string node;
    int distance;

    NodeDistance(const std::string& n, int d) : node(n), distance(d) {}

    bool operator<(const NodeDistance& other) const {
        return distance > other.distance;
    }
};

std::unordered_map<std::string, int> dijkstra(
    const std::unordered_map<std::string, std::vector<Edge>>& graph,
    const std::string& start) {

    std::unordered_map<std::string, int> dist;

    // Бесконечность для вершин, нулевое начало
    for (const auto& pair : graph) {
        dist[pair.first] = std::numeric_limits<int>::max();
    }
    dist[start] = 0;
    // Элементы - (дистанция, узел)
    std::priority_queue<NodeDistance> pq;
    pq.emplace(start, 0);

    // Удаляем кратчайшее расстояние
    while (!pq.empty()) {
        NodeDistance current = pq.top();
        pq.pop();

        // пропускаем устаревшие значения
        if (current.distance > dist[current.node]) {
            continue;
        }
        // обновляем расстояния до соседей
        for (const auto& neighbor : graph.at(current.node)) {
            int new_dist = current.distance + neighbor.weight;
            if (new_dist < dist[neighbor.node]) {
                dist[neighbor.node] = new_dist;
                pq.emplace(neighbor.node, new_dist);
            }
        }
    }

    return dist;
}

int main() {
    std::unordered_map<std::string, std::vector<Edge>> graph = {
        {"A", {Edge("B", 2), Edge("C", 6)}},
        {"B", {Edge("A", 3), Edge("C", 1), Edge("D", 4)}},
        {"C", {Edge("A", 2), Edge("B", 2), Edge("D", 4)}},
        {"D", {Edge("B", 1), Edge("C", 4)}}
    };
    // Алгоритм Дейкстры от узла А
    auto distances = dijkstra(graph, "A");

    std::cout << "Расстояния:" << std::endl;
    for (const auto& pair : distances) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
