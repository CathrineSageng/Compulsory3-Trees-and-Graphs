#pragma once
#include <iostream>
#include <list>
#include <unordered_map>
#include <queue>
using namespace std;

class Graph
{
private:
   
    class Node 
    {
    public:
        //This is a member variable that can hold an integer value. This variable can be used for the 
        //integer value in each node in the graph. 
        int Data;

        //This is the list for the graph. This adjacency list is a collection of liked lists used to 
        //hold the information between between the nodes in the graph. Each node has a list og pointers 
        //Example: if we have nodes with data values 1, 2, 3 and 4, and there is an edge between node 1 and 2
        //and between 1 and 3, the adjacensy list for node 1 would contain  pointers to nodes 2 and 3.   
        list<Node*> adjacentNodes;

        //This is a constructor for the Node class. This will be called automatically everytime a new node  
        //is being created. 
        Node(int data);
    };
    //Unodered map are used to store the nodes of the graph. The keys are of type integer(nodes ID) and values 
    // are pointers to 'Node' objects representing the nodes in the graph. 
    //This allows fast accsess to the nodes. 
    unordered_map<int, Node*> nodes;

public:
    //This is the constructor to the Graph Class
    Graph();

    //This is the destuctor for the class Graph. 
    ~Graph();

    // Function to add a node to the graph
    void addNode(int Data);

    // Function to add an edge between two nodes
    void addEdge(int source, int destination);

    // Function to remove an edge between two nodes
    void removeEdge(int source, int destination);

    // Function to remove a node from the graph
    void removeNode(int data);

    // Function to check if the graph is empty
    bool isEmpty();

    // Function to get the number of nodes in the graph
    int size();

    // Function to get the data of a specific node
    int getNodeData(int data);

    // Function to get the adjacent nodes of a specific node
    std::list<int> getAdjacentNodes(int data);

    // Function to get the vertices in the graph
    std::list<int> getVertices();

    // Function to get the number of edges in the graph
    int getNumEdges();

    // Function to perform breadth-first traversal of the graph
    void breadthFirstTraversal(int startNode);

};

