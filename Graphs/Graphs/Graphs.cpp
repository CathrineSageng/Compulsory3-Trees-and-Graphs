#include <iostream>
#include <list>
#include "Graph.h"
#include <cstdlib> 

using namespace std;
int main()
{
    //Creating an object to the class graph 
    Graph graph;

    //Checks if the graph is empty
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

    //Adding nodes to the graph
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);
    graph.addNode(4);
    graph.addNode(5);
    graph.addNode(6);
    //Adding edges to the graph
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.addEdge(4, 6);
    graph.addEdge(6, 5);

    //Checks if the graph is empty 
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

    //Prints out the size of the graph(how many nodes the graph contains)
    cout << "The size of the graph is:" << graph.size()<<endl;

    //Prints out information on the nodes. 
    cout << "Does the graph has a node with the value of 8? " << "No: "<< graph.getNodeData(8) << endl;
    cout << "Does the graph has a node with the value of 4? " << "Yes: " <<graph.getNodeData(4) << endl;

    //Prints out the adjacent nodes of the node asked for in the function 
    cout << "What are the adjacent node(s) to node 2? ";
    list<int> adjacentNodes = graph.getAdjacentNodes(2);
    for (list<int>::iterator iterator = adjacentNodes.begin(); iterator != adjacentNodes.end(); ++iterator) {
        cout << *iterator << " ";
    }
    cout << endl;

    cout << "What are the adjacent node(s) to node 8? ";
    list<int> adjacentNodes1 = graph.getAdjacentNodes(8);
    for (list<int>::iterator iterator = adjacentNodes1.begin(); iterator != adjacentNodes1.end(); ++iterator) {
        cout << *iterator << " ";
    }
    cout << endl;

    //Prints out all the nodes(vertices) in the graph
    cout << "All the nodes in the graph: ";
    list<int> vertices = graph.getVertices();
    for (list<int>::iterator iterator = vertices.begin(); iterator != vertices.end(); ++iterator) 
    {
        cout << *iterator << " ";
    }
    cout << std::endl;

    //Prints out the total amount od edges in the graph 
    cout << "The total amount of edges in the graph is: " << graph.getNumEdges() << endl;

    //Prints out the breadth first traversal. 
    cout << "Breadth-first traversal starting from node 1: ";
    graph.breadthFirstTraversal(1);

    //Deletes a node from the graph. 
    graph.removeNode(5);
    cout << "The graph with Breadth-first traversal after node 5 is removed: ";
    graph.breadthFirstTraversal(1);

    //Deletes a edge from the graph. 
    graph.removeEdge(1, 2);
    cout << "The graph with Breadth-first traversal after node 5 and edge between 1 and 2 is removed: ";
    graph.breadthFirstTraversal(1);
    
    //Creating a new object of the graph class
    Graph graph2;
    /*for (int i = 0; i < 5; ++i) {
        graph2.addRandomNode(100);
    }
   
    std::cout << "Graph size after inserting random nodes: " << graph2.size() << std::endl;
    
    cout << std::endl;*/

    srand(time(0)); // Seed the random number generator with current time

    // Insert 5 random nodes with values between 1 and 100
    for (int i = 0; i < 5; ++i) {
        graph2.addRandomNode(1, 100);
    }

    std::cout << "Graph size after inserting random nodes: " << graph2.size() << std::endl;

    std::cout << "Random values between 1 and 100: ";
    for (int i = 0; i < 5; ++i) {
        int randomValue = graph2.getRandomValue(1, 100);
        std::cout << randomValue << " ";
    }
    std::cout << std::endl;

    return 0;

}

