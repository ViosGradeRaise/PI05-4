import heapq
import sys

def dijkstra(graph, start):
    # Бесконечность для вершин, нулевое начало
    dist = {node: sys.maxsize for node in graph}
    dist[start] = 0

    # Элементы - (дистанция, узел)
    pq = [(0, start)]
    
    # Удаляем кратчайшее расстояние
    while pq:
        d, u = heapq.heappop(pq)
        # пропускаем устаревшие значение
        if d > dist[u]:
            continue
        # обновляем расстояния до соседей
        for v, w in graph[u]:
            if d + w < dist[v]:
                dist[v] = d + w
                heapq.heappush(pq, (dist[v], v))
    return dist

graph = {
    "A": [("B", 2), ("C", 6)],
    "B": [("A", 3), ("C", 1), ("D", 4)],
    "C": [("A", 2), ("B", 2), ("D", 4)],
    "D": [("B", 1), ("C", 4)]
}

# Алгоритм Дейкстры от узла А
distances = dijkstra(graph, "A")

print("Расстояния:")
for node, distance in distances.items():
    print(f"{node}: {distance}")
