import java.util.*;

public class Dijkstra {

    public static Map<String, Integer> dijkstra(Map<String, List<Edge>> graph, String start) {
        Map<String, Integer> dist = new HashMap<>();
        // Бесконечность для вершин, нулевое начало
        for (String node : graph.keySet()) {
            dist.put(node, Integer.MAX_VALUE);
        }
        // Элементы - (дистанция, узел)
        dist.put(start, 0);

        PriorityQueue<NodeDistance> pq = new PriorityQueue<>(Comparator.comparingInt(nd -> nd.distance));
        pq.offer(new NodeDistance(start, 0));

// Удаляем кратчайшее расстояние
        while (!pq.isEmpty()) {
            NodeDistance current = pq.poll();
            String u = current.node;
            int d = current.distance;
// пропускаем устаревшие значение
            if (d > dist.get(u)) {
                continue;
            }
// обновляем расстояния до соседей
            for (Edge neighbor : graph.get(u)) {
                String v = neighbor.node;
                int w = neighbor.weight;
                if (d + w < dist.get(v)) {
                    dist.put(v, d + w);
                    pq.offer(new NodeDistance(v, dist.get(v)));
                }
            }
        }
        return dist;
    }

    static class Edge {
        String node;
        int weight;

        public Edge(String node, int weight) {
            this.node = node;
            this.weight = weight;
        }
    }

    static class NodeDistance {
        String node;
        int distance;

        public NodeDistance(String node, int distance) {
            this.node = node;
            this.distance = distance;
        }
    }

    public static void main(String[] args) {
        Map<String, List<Edge>> graph = new HashMap<>();
        graph.put("A", Arrays.asList(new Edge("B", 2), new Edge("C", 6)));
        graph.put("B", Arrays.asList(new Edge("A", 3), new Edge("C", 1), new Edge("D", 4)));
        graph.put("C", Arrays.asList(new Edge("A", 2), new Edge("B", 2), new Edge("D", 4)));
        graph.put("D", Arrays.asList(new Edge("B", 1), new Edge("C", 4)));
// Алгоритм Дейкстры от узла А
        Map<String, Integer> distances = dijkstra(graph, "A");

        System.out.println("Расстояния:");
        for (Map.Entry<String, Integer> entry : distances.entrySet()) {
            System.out.println(entry.getKey() + ": " + entry.getValue());
        }
    }
}
