#include <queue>
#include <vector>

using namespace std;

struct Node {
  int distance;
  int vertex;
};

bool operator<(const Node& a, const Node& b) {
  return a.distance > b.distance;
}

vector<int> Dijkstra(vector<vector<int>>& graph, int source) {
  // Initialize the distances of all vertices to infinity.
  vector<int> distances(graph.size(), INT_MAX);
  distances[source] = 0;

  // Create a priority queue to store the vertices in order of increasing distance from the source.
  priority_queue<Node> pq;
  pq.push({0, source});

  while (!pq.empty()) {
    // Get the vertex with the shortest distance from the source.
    Node node = pq.top();
    pq.pop();

    // If the vertex is already visited, skip it.
    if (distances[node.vertex] < node.distance) {
      continue;
    }

    // Update the distances of all the neighbors of the vertex.
    for (int i = 0; i < graph[node.vertex].size(); i++) {
      int neighbor = graph[node.vertex][i];
      int newDistance = distances[node.vertex] + graph[node.vertex][i];
      if (newDistance < distances[neighbor]) {
        distances[neighbor] = newDistance;
        pq.push({newDistance, neighbor});
      }
    }
  }

  return distances;
}

int main() {
  // Create a graph with 6 vertices.
  vector<vector<int>> graph(6);

  // Add edges to the graph.
  graph[0][1] = 10;
  graph[0][2] = 3;
  graph[1][3] = 1;
  graph[2][3] = 4;
  graph[3][4] = 2;
  graph[4][5] = 6;

  // Find the shortest paths from the source vertex (0) to all other vertices.
  vector<int> distances = Dijkstra(graph, 0);

  // Print the shortest paths.
  for (int i = 0; i < distances.size(); i++) {
    cout << "Shortest path from source to vertex " << i << ": " << distances[i] << endl;
  }

  return 0;
}
