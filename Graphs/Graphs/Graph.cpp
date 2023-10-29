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
/// This function generates numbers in a range
/// </summary>
/// <param name="minValue">The minimum value of the node</param>
/// <param name="maxValue">The maximun value of the node</param>
/// <returns> -1 for invalid inputs, indicating error. Returns the random numbers generated</returns>
int Graph::getRandomValue(int minValue, int maxValue)
{
    {
        //if the minimum value is greater than the maximun value, then the values are invalid. 
        if (minValue > maxValue) {
            cerr << "This numbers are invalid" <<endl;
            return -1; 
        }
        // Generates a random value between minValue and maxValue if the values are valid.
        //Then the function calculates the size of the range and adds +1, so the maxvalue is included  in the range. 
        return rand() % (maxValue - minValue + 1) + minValue; 
    }
}

/// <summary>
/// This function adds the random numbers to the graph. 
/// </summary>
/// <param name="minValue">The minimum value of the node</param>
/// <param name="maxValue"> The maximum value of the node</param>
void Graph::addRandomNode(int minValue, int maxValue)
{
    int randomValue = getRandomValue(minValue, maxValue);
    //Adds a new node to the graph with a generated number. 
    addNode(randomValue);
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
/// <returns> The data associated with the specified node. -1 and message if the node is not found</returns>
int Graph::getNodeData(int data)
{
   //Searching trough the unorderod_map 'nodes' for the asked 'data', with the function find(). 
   //if the 'data' is not found it prints out the message. 
   if (nodes.find(data) == nodes.end()) 
   {
       //cerr is used for error message. cout is used for normal output message. 
       cerr << "The node was not found in the graph." << endl; 
       return -1; 
   }
  // If the node is found in the graph, the function retrieves the Data from the Node object, pointed to
  // by the data key in the nodes map.
       return nodes[data]->Data;
}

/// <summary>
/// This function retrives values from the nodes that are adjacent to the node asked for, 
/// Iterates trough the adjacentNode list and  for a specified data (nodes[data]->adjacentNodes).
/// For each adjacent node pointer, it retrieves the Data associated with that node and adds it to the 
/// adjacentNodeData list.
/// </summary>
/// <param name="data">The node value from the node that are adjacent from the node(s) </param>
/// <returns>If the node is not found, an error message will be printed out.
/// If the node is found, it will return a list containing data values of the adjacent nodes </returns>
list<int> Graph::getAdjacentNodes(int data)
{
    
    if (nodes.find(data) == nodes.end()) 
    {
        cerr << "The node was not found in the graph." <<endl;
        //Returns an empty list
        return list<int>(); 
    }
    //Here we iterate trough the adjacentNode list for the node that is asked for. 
    list<int> adjacentNodeData;
    list<Node*> adjacentNodes = nodes[data]->adjacentNodes;
    for (list<Node*>::iterator iterator = adjacentNodes.begin(); iterator != adjacentNodes.end(); ++iterator) 
    {
        Node* adjacentNode = *iterator;
        adjacentNodeData.push_back(adjacentNode->Data);
    }
    return adjacentNodeData;
}

/// <summary>
/// This function retrives data of all the nodes in the graph and return them as a list. 
/// </summary>
/// <returns>A list with data values of all the nodes in the graph</returns>
list<int> Graph::getVertices()
{
    //This is an empty list 
    list<int> vertices;
    //Iterates trough all the nodes in the unordered_map from the beginning to the end and collects 
    //all the node data in a list that will be reutrned. first is the node data, second is the pointer to Node. 
    for (unordered_map<int, Node*>::iterator iterator = nodes.begin(); iterator != nodes.end(); ++iterator) 
    {
        vertices.push_back(iterator->first);
    }
    return vertices;
}

/// <summary>
/// This function calculates the number of edges in the graph. It iterates trough all the nodes and counts 
/// the munber of adjacent nodes and then divide the total number on 2 since the edge is counted twice. 
/// </summary>
/// <returns><The total amount of edges in the graph</returns>
int Graph::getNumEdges()
{
    int count = 0;
    for (unordered_map<int, Node*>::iterator iterator = nodes.begin(); iterator != nodes.end(); ++iterator) 
    {
        count += iterator->second->adjacentNodes.size();
    }
    // For undirected graph, each edge is counted twice, so we need to divide by 2
    return count / 2;
}


/// <summary>
/// This function does a breadth first traversal from a specified startNode and prints out the data for each 
/// visited node in the order they are visited. Each node is only visited once. 
/// </summary>
/// <param name="startNode">this is the node the traversal starts from</param>
void Graph::breadthFirstTraversal(int startNode)
{
        //Checks if the stratNode exists, if not the message wil be printed out. 
        if (nodes.find(startNode) == nodes.end()) {
            cerr << "Node not found in the graph." << endl;
            return;
        }
        //Here an unordered map is created with a bool datatype. Each node pointer (element) has a bool value
        //to indicate if the node is visited or not. 
        unordered_map<Node*, bool> visited;
        //Creates an empty queue. 
        queue<Node*> queue;
        //The start gets a pointer to the starting node based on the provided value to startNode. 
        Node* start = nodes[startNode];
        //Adds the element start at the end og the queue. 
        queue.push(start);
        //Start value is visited. 
        visited[start] = true;

        //The while loop continues to the loop is empty. 
        while (!queue.empty()) 
        {
            //Retrives the first element and is now the currentNode. 
            Node* currentNode = queue.front();
            //Removes the current node from the queue. 
            queue.pop();
            //Prints out data from the currentNode. 
            cout << currentNode->Data << " ";

            //iterated trough the adjacent nodes of the current nodes.
            for (list<Node*>::iterator iterator = currentNode->adjacentNodes.begin(); 
                    iterator != currentNode->adjacentNodes.end(); ++iterator) 
            {
                //if the adjacent node has not been visited it change the status from false to true. 
                Node* adjacentNode = *iterator;
                if (!visited[adjacentNode]) 
                {
                    //Adds the element at the end og the queue. 
                    queue.push(adjacentNode);
                    visited[adjacentNode] = true;
                }
            }
        }
        cout << endl;
}


