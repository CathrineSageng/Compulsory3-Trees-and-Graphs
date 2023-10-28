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

/// <summary>
/// This function creatres a new node with the value given from the user and it to the Graph object 'graph'. 
/// Its the 'nodes' map that stores all the nodes using their data values as keys and pointers to Node 
/// objects as values
/// </summary>
/// <param name="Data">The value of the node given by the user</param>
void Graph::addNode(int Data)
{
    //Adds a newly creates 'Node' object and adds it to the unordered_map nodes. 
   nodes[Data] = new Node(Data);
}

/// <summary>
/// This functions adds an undirected edge between two nodes in the graph. It updates the adjacent node list of both 
/// 'startNode' and 'destinationNode', indicating they are connected to each other. 
/// </summary>
/// <param name="source">This represents the data value of the first node between two nodes we are 
/// creating an edge between</param>
/// <param name="destination">This represents the data value of the second node between two nodes we are
/// creating an egde between</param>
void Graph::addEdge(int startNode, int destinationNode)
{
    //First we access the 'startNode' list  and uses the push back to add the pointer to the 'destinationNode' list
    nodes[startNode]->adjacentNodes.push_back(nodes[destinationNode]);
    //First we accsess the 'destinationNode' list and uses the push back to add the pointer to the 'startNode' list 
    nodes[destinationNode]->adjacentNodes.push_back(nodes[startNode]);
}

/// <summary>
/// This function removes an undirected edge between 'startNode' and 'destinationNode'. 
/// </summary>
/// <param name="startNode"></param>
/// <param name="destinationNode"></param>
void Graph::removeEdge(int startNode, int destinationNode)
{
    //Starts by searching the 'startNode' list from the start to the end, by searching for the iterator
    //pointing to the'destinationNode' in the 'adjacentNode' list of the 'startNode'. 
    auto iteration = find(nodes[startNode]->adjacentNodes.begin(), nodes[startNode]->adjacentNodes.end(), 
                     nodes[destinationNode]);
    //if the iteration is not equal to the end of the list the iteration found the 'destinationNode'.
    //Use the erase function to remove the element that is pointing to the 'destinationNode'.
    if (iteration != nodes[startNode]->adjacentNodes.end()) {
        nodes[startNode]->adjacentNodes.erase(iteration);
    }

    //Look at the previous explaination. 
    iteration = std::find(nodes[destinationNode]->adjacentNodes.begin(), nodes[destinationNode]->adjacentNodes.end(),
                          nodes[startNode]);
    if (iteration != nodes[destinationNode]->adjacentNodes.end()) {
        nodes[destinationNode]->adjacentNodes.erase(iteration);
    }
}

/// <summary>
/// This function removes the nodes from the graph and all the edges connected to the node. 
/// </summary>
/// <param name="data">Value of the pointer to be deleted</param>
void Graph::removeNode(int Data)
{
    //Retrives a pointer to the node with the correct value(Data). This will be the node removed. 
    auto nodeToDelete = nodes[Data];
    //Iterates trough the nodes map and deletes the edges that are connected to the node to be delted. 
    //it does this by calling the removeEdge function. 
    for (unordered_map<int, Node*>::iterator iterator = nodes.begin(); iterator != nodes.end(); ++iterator) 
    {
    removeEdge(iterator->first, Data);
    }
    //Removes the node from the graph using the 'Data' value as the key 
    nodes.erase(Data);
    //Deallocates the memory that was occupides by the node. 
    delete nodeToDelete;
}

/// <summary>
/// check if the graph is empty or not. It returns true(1), if the graph is empty. 
/// nodes.empty() checks the nodes in the unodered map. 
/// </summary>
/// <returns>If the map is empty, it will return true(1).</returns>
bool Graph::isEmpty()
{
   return nodes.empty();
}

/// <summary>
/// This function counts the number of nodes in the graph. 
/// </summary>
/// <returns>How many nodes that are counted</returns>
int Graph::size()
{
    //uses the size() function on the unordered_map 'nodes'
   return nodes.size();
}

/// <summary>
/// This function gets data from a specific node in the graph. If the node is not found it prints out an error message. 
/// </summary>
/// <param name="data"></param>
/// <returns></returns>
int Graph::getNodeData(int data)
{
   if (nodes.find(data) == nodes.end()) 
   {
       std::cerr << "Node not found in the graph." << std::endl;
       // Return a default value indicating error
        return -1; 
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


