#include <limits.h>
#include <iostream>
#include <vector>
 
void Algorithm(std::vector<std::vector<int>> graph, int start, int SIZE) {
  int distance[SIZE];
  bool visited[SIZE];

  for (int i = 0; i < SIZE; i++) {
    distance[i] = INT_MAX;
    visited[i] = false;
  }

  distance[start] = 0;

  for (int j = 0; j < SIZE - 1; j++) {
    int cur = -1;
    int mindistance = INT_MAX;

    for (int i = 0; i < SIZE; i++) {
      if (!visited[i] && distance[i] < mindistance) {
        cur = i;
        mindistance = distance[i];
      }
    }

    visited[cur] = true;

	for (int i = 0; i < SIZE; i++) {
	  if (!visited[i] && graph[cur][i] != INT_MAX &&
		  distance[cur] != INT_MAX &&
		  distance[cur] + graph[cur][i] < distance[i]) {
		distance[i] = distance[cur] + graph[cur][i];
	  }
	}
  }


  std::cout << "Vertex\tDistance from Source\n";
  for (int i = 0; i < SIZE; i++) {
    std::cout <<  i << " " <<  distance[i] << "\n";
  }
}

int main() {
	int SIZE = 4;
  std::vector<std::vector<int>> graph =  {
	  {0, 3, 5, INT_MAX},
	  {3, 0, 2, 7},
	  {5, 2, 0, INT_MAX},
	  {INT_MAX, 7, INT_MAX, 0}
  };

 Algorithm(graph, 0, SIZE);
  return 0;
}
