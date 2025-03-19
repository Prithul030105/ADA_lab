What is Dijkstra’s Algorithm?
Dijkstra’s algorithm is used to find the shortest path from a single source vertex to all other vertices in a graph with non-negative edge weights. It is commonly used in routing protocols, map navigation systems, and network optimizations.

Steps of the Algorithm
Initialize Distance Array

Set the source vertex distance as 0.
Set all other vertices’ distances to infinity (∞) because they are unknown.
Use a Greedy Approach

Find the unvisited vertex with the smallest distance and mark it as visited.
Update its neighbors by checking if a shorter path exists through it.
Update the Shortest Paths

If the new path to a vertex is shorter than the known path, update it.
Repeat Until All Nodes Are Processed

