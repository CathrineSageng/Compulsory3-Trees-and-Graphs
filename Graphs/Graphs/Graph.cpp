#include "Graph.h"

/// <summary>
/// This is the constructor for the Node class. If we are creating a new node, this constructor is automatically 
/// called. Exemple: Creating a node with value 23. The constuctor is automatically called with 'data' being 23
/// and the 'Data' of the new node  is set to 23. This ensures that the node is set with the correct value when 
/// they are created. 
/// </summary>
/// <param name="data">The value of the node with integer as datatype</param>
Graph::Node::Node(int data)
{
	Data = data;
}

/// <summary>
/// An empty constructor to the graph class. When we create an Graph object, the constructor doesen't
/// do anything specific, sonce the body is empty. 
/// </summary>
Graph::Graph()
{
}

/// <summary>
/// This is the destructor of the class Graph. It iterates trough all the elements in the node map. It loops
/// until it reaches the end. count->second gives the pointer to a 'Node' object and is then deleted. 
/// 'it->second' accesses the Node* (pointer to Node object) and deallocates the memory pointed to by 'it->second'
/// </summary>
Graph::~Graph()
{
    for (unordered_map<int, Node*>::iterator count = nodes.begin(); count != nodes.end(); ++count) 
    {
        delete count->second;
    }
}

void Graph::addNode(int Data)
{
   nodes[Data] = new Node(Data);
}

void Graph::addEdge(int source, int destination)
{
	nodes[source]->adjacentNodes.push_back(nodes[destination]);
	nodes[destination]->adjacentNodes.push_back(nodes[source]); // For undirected graph
}

void Graph::removeEdge(int source, int destination)
{
    auto it = std::find(nodes[source]->adjacentNodes.begin(), nodes[source]->adjacentNodes.end(), nodes[destination]);
    if (it != nodes[source]->adjacentNodes.end()) {
        nodes[source]->adjacentNodes.erase(it);
    }

    it = std::find(nodes[destination]->adjacentNodes.begin(), nodes[destination]->adjacentNodes.end(), nodes[source]);
    if (it != nodes[destination]->adjacentNodes.end()) {
        nodes[destination]->adjacentNodes.erase(it);
    }
}

void Graph::removeNode(int data)
{
    {
        auto nodeToDelete = nodes[data];
        for (auto& pair : nodes) {
            removeEdge(pair.first, data);
        }
        nodes.erase(data);
        delete nodeToDelete;
    }
}

bool Graph::isEmpty()
{
   return nodes.empty();
}

int Graph::size()
{
   return nodes.size();
}

int Graph::getNodeData(int data)
{
   if (nodes.find(data) == nodes.end()) {
       std::cerr << "Node not found in the graph." << std::endl;
        return -1; // Return a default value indicating error
        }
        return nodes[data]->Data;
}

std::list<int> Graph::getAdjacentNodes(int data)
{
    
        if (nodes.find(data) == nodes.end()) {
            std::cerr << "Node not found in the graph." << std::endl;
            return std::list<int>(); // Return an empty vector indicating error
        }

        std::list<int> adjacentNodeData;
        for (Node* adjacentNode : nodes[data]->adjacentNodes) {
            adjacentNodeData.push_back(adjacentNode->Data);
        }
        return adjacentNodeData;
    
}

std::list<int> Graph::getVertices()
{
    
        std::list<int> vertices;
        for (const auto& pair : nodes) {
            vertices.push_back(pair.first);
        }
        return vertices;
    
}

int Graph::getNumEdges()
{
    int count = 0;
    for (const auto& pair : nodes) {
        count += pair.second->adjacentNodes.size();
    }
    // For undirected graph, each edge is counted twice, so divide by 2
    return count / 2;
}

void Graph::breadthFirstTraversal(int startNode)
{
        if (nodes.find(startNode) == nodes.end()) {
            std::cerr << "Node not found in the graph." << std::endl;
            return;
        }

        std::unordered_map<Node*, bool> visited;
        std::queue<Node*> queue;

        Node* start = nodes[startNode];
        queue.push(start);
        visited[start] = true;

        while (!queue.empty()) {
            Node* currentNode = queue.front();
            queue.pop();
            std::cout << currentNode->Data << " ";

            for (Node* adjacentNode : currentNode->adjacentNodes) {
                if (!visited[adjacentNode]) {
                    queue.push(adjacentNode);
                    visited[adjacentNode] = true;
                }
            }
        }

        std::cout << std::endl;
}


