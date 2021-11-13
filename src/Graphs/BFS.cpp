#include <iostream>
#include <list>

using namespace std;

// This class represents a directed graph  using
// adjancency list representation
class Graph
{
    int numberOfVertices;
    list<int> *adjancencyMatrix;

public:
    Graph(int numberOfVertices);                // Constructor
    void AddEdge(int vertexNumber, int wieght); // function to add an edge to graph
    void BFS(int source);                       // prints BFS traversal from a given source s
};

Graph ::Graph(int numberOfVertices)
{
    this->numberOfVertices = numberOfVertices;
    adjancencyMatrix = new list<int>[numberOfVertices];
}

void Graph ::AddEdge(int vertexNumber, int wieght)
{
    adjancencyMatrix[vertexNumber].push_back(wieght);
}

void Graph ::BFS(int source)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[numberOfVertices];

    // Create a queue for BFS
    for (int i = 0; i < numberOfVertices; i++)
        visited[i] = false;

    // Create a queue for BFS
    list<int> queue;

    // Mark the current node as visited and enqueue
    visited[source] = true;
    queue.push_back(source);

    // create the iterator to iterate the adjanecy list
    list<int>::iterator iterator;

    while (!queue.empty())
    {
        // Dequeue a vertex from the queue and print it
        source = queue.front();
        cout << source << " ";

        queue.pop_front();

        // Get all adjacent vertiece of the dequeued vertex souece
        for (iterator = adjancencyMatrix[source].begin(); iterator != adjancencyMatrix[source].end(); ++iterator)
        {
            if (!visited[*iterator])
            {
                visited[*iterator] = true;
                queue.push_back(*iterator);
            }
        }
    }
}

// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    int numberVertices, numberOfEdges;
    cin>>numberVertices,numberOfEdges;
    
    Graph graph(numberVertices);

    for(int index=0;index <numberOfEdges;index++)
    {
        int source,destination;
        cin>>source,destination;
        graph.AddEdge(source, destination);
    }
    
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    graph.BFS(2);

    return 0;
}
