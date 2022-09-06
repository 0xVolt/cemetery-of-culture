# To implement a queue
import collections

# Function to implement the BFS algo
def bfs(graph, root):
    visited, queue = set(), collections.deque([root])
    visited.add(root)

    while queue:
        # Dequeue a vertex from queue
        vertex = queue.popleft()
        print(str(vertex) + " ", end="")

        # If not visited, mark it as visited, and
        # enqueue it
        for neighbour in graph[vertex]:
            if neighbour not in visited:
                visited.add(neighbour)
                queue.append(neighbour)


if __name__ == '__main__':
    graph = {
        0: [1, 2], 
        1: [2, 3, 4], 
        2: [2], 
        3: [1, 2]
    }
    
    print("Traversing according to the BFS algorithm:")
    
    bfs(graph, 0)