# Search algorithms
![Untitled](https://user-images.githubusercontent.com/89021784/129673085-e14c24a8-0f45-4196-89d5-4830adf3423c.png)

### <a href="https://github.com/sanya25aug/Search-algorithms/blob/main/BFS.cpp">BFS Algorithm: </a>

   * BFS is traversing the adjacent nodes at first, and after that moving on to next nodes.
   * Complexity:
      * Time complexity: O(N+E) -> N is time taken for visiting N nodes, and E is for travelling through adjacent nodes overall.
      * Space complexity: O(N+E) + O(N) + O(N) 

<hr/>

### <a href="https://github.com/sanya25aug/Search-algorithms/blob/main/DFS.cpp">DFS Algorithm: </a>

   * DFS is traversing the graph in depthward motion. It is a recursive function.
   * Complexity:
      * Time complexity: O(N+E) -> N is time taken for visiting N nodes, and E is for travelling through adjacent nodes overall.
      * Space complexity: O(N+E) + O(N) + O(N) -> Space for adjacency list, visited array, and auxiliary space.


<hr/>

### <a href="https://github.com/sanya25aug/Search-algorithms/blob/main/Uniform%20Cost%20Search.cpp">Uniform cost search: </a>
   ![aaaa](https://user-images.githubusercontent.com/89021784/130214504-6d144e9c-8209-4364-8877-97637ee575a8.png)

   1. We will have a priority queue (that will store distance, node).
   2. Priority queue should be a min heap, so that the element with the lower distance should always be on top of priority queue.
   3. We will also be having a distance array of the size of nodes+1, initially marked as infinity.
   4. Take the first node out of queue and mark its distance as zero.
   5. Insert the distance of that node, and the node in the priority queue.
   6. Now start iterating the graph similar to bfs.
   7. Take the adjacent nodes of that element one by one, and add the distance of that adjacent node to the distance of the element, and also compare it to the already assigned distance.
   8. Put the node and distance in the priority queue.
   9. Take the first element from the priority queue. (It will be storing the element with lower distant on top).
   10. Take the adjacent nodes, and repeat the above process. (7,8,9)
   11. Continue this till the priority queue becomes empty.
   * Complexity:
        * Time complexity: O((N+E)logN) -> N is time taken for visiting N nodes, and E is for travelling through adjacent nodes overall. Log N is for priority queue.
        * Space complexity: O(N+E) + O(N) + O(N)

<hr/>

### A* Search:

<hr/>

### Bidirectional Search:
   * In bidirectional search, the search begins simultaneously from source vertex and destination vertex and ends when the two searches meet somewhere in between in the graph.
   * It is based on heuristic search (finding the shortest path to destination optimally).
   * Time and Space complexity: O(b^{d/2}).

<hr/>
