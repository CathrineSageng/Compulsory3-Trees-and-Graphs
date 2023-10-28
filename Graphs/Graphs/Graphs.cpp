#include <iostream>
#include <list>
#include "Graph.h"

using namespace std;
int main()
{
    Graph graph;


    cout << "Is the graph empty?";
    if (graph.isEmpty() == 1)
    { 
        cout << " Yes";
    }
    else 
    {
        cout << " No";
    }
    cout<<endl;

    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);
    graph.addNode(4);
    graph.addNode(5);
    graph.addNode(6);


    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.addEdge(4, 6);
    graph.addEdge(6, 5);

    cout << "Is the graph empty?";
    if (graph.isEmpty() == 1)
    {
        cout << " Yes";
    }
    else
    {
        cout << " No";
    }
    cout << endl;

    cout << "The size of the graph is:" << graph.size()<<endl;

    cout << graph.getNodeData(7) << endl;

    std::cout << "Node 2 data: " << graph.getNodeData(2) << std::endl;

    std::cout << "Adjacent nodes of node 1: ";
    std::list<int> adjacentNodes = graph.getAdjacentNodes(1);
    for (int node : adjacentNodes) {
        std::cout << node << " ";
    }
    std::cout << std::endl;

    std::cout << "Vertices in the graph: ";
    std::list<int> vertices = graph.getVertices();
    for (int vertex : vertices) {
        std::cout << vertex << " ";
    }
    std::cout << std::endl;

    std::cout << "Number of edges in the graph: " << graph.getNumEdges() << std::endl;

    std::cout << "Breadth-first traversal starting from node 1: ";
    graph.breadthFirstTraversal(1);

    return 0;


 
}

