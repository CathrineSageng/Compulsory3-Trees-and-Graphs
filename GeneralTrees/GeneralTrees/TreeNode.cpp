#include "TreeNode.h"

/// <summary>
/// This is the constructor  to the Treenode. 
/// </summary>
/// <param name="data">The constuctor takes the datatype integer.</param>
TreeNode::TreeNode(int data)
{
	Data = data;
}


/// <summary>
///push_back push elements into a list from the back. The new value is inserted at the end of a list. 
///This increases the size by 1 in the container 'treeNode'.
/// </summary>
/// <param name="child">The function takes a treeNode object</param>
void TreeNode::addChild(TreeNode* child)
{
	children.push_back(child);
}

/// <summary>
/// The GeneralTree class is nested in the Treenode class. 
/// A new 'Treenode' object is allocated on the heap memory using the 'new' keyword. 
/// The constuctor of the 'Treenode' is called with the assigned 'rootValue' parameter and the memory adress
/// of the newly created created 'Treenode' object.
/// Now the 'root' pointer points to a root node of the tree
/// </summary>
/// <param name="rootValue">The value of the root</param>
TreeNode::GeneralTree::GeneralTree(int rootValue)
{
	root = new TreeNode(rootValue);
}

/// <summary>
/// 'getRoot' takes no parameter and is the function name. 
/// </summary>
/// <returns> Here it reuturns a pointer to the 'Treenode' object, the adress of the root. </returns>
TreeNode* TreeNode::GeneralTree::getRoot()
{
	if (root == nullptr)
		return 0;
	else
		return root;
}

/// <summary>
/// A function that find the parent node of a specified node in the tree object. 
/// Passing in the root of the tree as the starting point for the search and the node parameter for the child
/// you want to find the parents to. findParents recursively finds the parents of the given node. 
/// </summary>
/// <param name="node"> the node of the parents you want to find</param>
/// <returns>The parents of the given node </returns>
TreeNode* TreeNode::GeneralTree::getParent(TreeNode* node)
{
	return findParent(root, node);
}

/// <summary>
/// Takes a pointer to the 'Treenode' object as a parameter and returns a list 
/// of child nodes of the node taken to account
/// </summary>
/// <param name="node">node' is a pointer to the member variable list<TreeNode*> children</param>
/// <returns>Returns the children of a parent assigned </returns>
list<TreeNode*> TreeNode::GeneralTree::getChildren(TreeNode* node)
{
	return node->children;
}

/// <summary>
/// This function calculates and returns the total number of nodes in the tree. 
/// </summary>
/// <param name="node"> node' is a pointer to the member variable list<TreeNode*> children</param>
/// <returns>The size of the tree</returns>
int TreeNode::GeneralTree::getSize(TreeNode* node)
{
	//If the node is a nullptr, means that its a empty tree or a leaf node with no children. 
	//The function will return 0. This is the base case. 
	if (node == nullptr)
	{
		return 0;
	}
	//If the node is not a nullptr the size will be initialized 1 
	//This means that a root exists. 
	int size = 1;
	//Now we know that a root exists and we wand to count the children. 
	//uses 'auto' to declare a variable. The compiler examines what type of initializing expression is on the right- 
	//hand side of the assignment and gives it the appropriate datatype for the variable. 
	//the iteration begins at the start of the children list and interates until it reaches the end
	//it updates the size for every interation. 
	for (auto count = node->children.begin(); count != node->children.end(); count++)
	{
		TreeNode* child = *count;
		size += getSize(child);
	}
	return size;
}

/// <summary>
/// This function calculates and returns the depth of the tree
/// </summary>
/// <param name="node">node' is a pointer to the member variable list<TreeNode*> children</param>
/// <returns> Returns the maximum depth of the tree</returns>
int TreeNode::GeneralTree::getDepth(TreeNode* node)
{
	//If the node is empty (nullptr), then the depth is 0 because there are no nodes in an empty tree.  
	if (node == nullptr)
	{
		return 0;
	}
	//The depth do not count the root, 
	int depth = 0;
	//For each child it calls itsef (getDepth(Child)) to find the depth of the subtree rooted at that child.
	//max compares the current depth and the depth of the current child and choose the larger one. 
	//1+getDepth. When you go one level deeper in the tree, to a child node you add 1 to the depth of the 
	//parent node. 
	//Explaination for the for loop, look at 'getChildren()'
	for (auto count = node->children.begin(); count != node->children.end(); count++)
	{
		TreeNode* child = *count;
		depth = max(depth, 1 + getDepth(child));
	}
	return depth;
}

/// <summary>
/// checks if the tree is empty or not. If it is empty, the tree has noe root, it is a nullptr. 
/// </summary>
/// <returns>It returns true if the tree is empty(1), and false(0) if the tree is not empty</returns>
bool TreeNode::GeneralTree::isEmpty()
{
	return root== nullptr;
}

/// <summary>
/// Checks if the assigned node is a root of the tree or not. 
/// Checks if the input node pointer is equal to the root pointer of the tree(GeneralTree object).
/// If they are equal, it means that the node is the root of the tree. 
/// </summary>
/// <param name="node">node' is a pointer to the member variable list<TreeNode*> children</param>
/// <returns>It returns true(1), if the pointers are equal and false(0) if they are different</returns>
bool TreeNode::GeneralTree::isRoot(TreeNode* node)
{
	return node==root;
}

/// <summary>
/// checks if the assigned node is a leaf of the tree. This is a node with no children. 
/// First we check if the node is not a nullptr, chekcs if the 'children list' is empty of the given 'node'.
/// If its empty, it indicates that the node has no children. 
/// </summary>
/// <param name="node">node' is a pointer to the member variable list<TreeNode*> children</param>
/// <returns>Returns true(1) if the node is not a nullptr and the node has no children, returns false(0) if
/// the node has children</returns>
bool TreeNode::GeneralTree::isLeaf(TreeNode* node)
{
	return (node != nullptr && node->children.empty());
}

/// <summary>
/// Here we insert a new node, with a assigned 'data' as a child of the assigned node(parentNode)
/// 'TreeNode*parentNode' points to the parentNode where the new child will be added. 
/// 'int data' is the value that the new child contains.
/// The two insertNode functions work together. The first one inserts a node to the parentNode, the second 
/// finds the parentNode based on the value and then inserts the new node as its child
/// </summary>
/// <param name="parentNode"></param>
/// <param name="data"></param>
void TreeNode::GeneralTree::insertNode(TreeNode* parentNode, int data)
{
	//Creates a new treeNode with the assigned value. 
	TreeNode* newNode = new TreeNode(data);
	//Adds the new child to the parentNode.
	parentNode->addChild(newNode);
}

/// <summary>
/// Uses the 'findNode' function to find the node with the 'parentValue' in the tree. 
/// Calls the fist 'insertNode' function to insert a new node with an assigned data value as a child of the found 
/// parent node. If the parentNode is not found, the 'not found' will be printed out. 
/// </summary>
/// <param name="parentValue">value of the parent node</param>
/// <param name="data">The value of the new node added</param>
void TreeNode::GeneralTree::insertNode(int parentValue, int data)
{
	TreeNode* parent = findNode(root, parentValue);
	if (parent != nullptr)
	{
		insertNode(parent, data);
	}
	else
	{
		cout << "Parent value " << parentValue << " not found " << endl;
	}
}

/// <summary>
/// This function finds and deletes the node. If it is a parent, the children also will be deleted.
/// </summary>
/// <param name="node">Declares a node as an pointer to the object TreeNode. It is looking for the 
/// node to delete</param>
void TreeNode::GeneralTree::deleteNode(TreeNode* node)
{
	//Finds the parent of the given/assigned node
	TreeNode* parent = getParent(node);
	//Check to see if the parent exits 
	if (parent != nullptr) 
	{
		//Finds the node in the childens list 
		auto iteration = find(parent->children.begin(), parent->children.end(), node);

		//If the node is found in the list, erase the node.
		if (iteration != parent->children.end()) 
		{
			parent->children.erase(iteration);
			delete node;
		}
	}

}

/// <summary>
/// This function will delete the root of the tree. First we check if the root exits. Then er call the 
/// destroyTree function to delete all the nodes of the tree. Then we set the root to a nullptr, this indicates that
/// the root is empty. 
/// </summary>
void TreeNode::GeneralTree::deleteRoot()
{
	if (root != nullptr) 
	{
		destroyTree(root);
		root = nullptr;
	}
}

/// <summary>
/// Explores the tree depth frist and prints out the value of each node visited. It explores as far as possible 
/// in each branch before backtracking. 
/// </summary>
/// <param name="node">Represents the current node the that the function is visiting trough the traversal</param>
void TreeNode::GeneralTree::depthFirstTraversal(TreeNode* node)
{
	//This is the base case, it stops the traversal when a leaf node of a empty tree is encountered
	if (node == nullptr)
	{
		return;
	}
	//Prints out the data of the current node visited 
	cout << node->Data << " ";
	//explores all the child nodes before the siblings. Explores from the left to the right, vertical. 
	for(auto count = node->children.begin(); count != node->children.end(); count++)
	/*for (TreeNode* child : node->children)*/
	{
		TreeNode* child = *count;
		depthFirstTraversal(child);
	}
}

/// <summary>
/// This is a recursive function. If the node is equal to the target data, then the value has been found in the 
/// current node. The function recursively searches for the target 'data' in all child nodes of the current node. 
/// If the target value is not found in any subtree, the function will return a nullptr. 
/// </summary>
/// <param name="node">'node' is a pointer to the member variable list<TreeNode*> children </param>
/// <param name="data"> The target value of the node</param>
/// <returns> returns the node with the taget 'data' or a nullptr if not found.</returns>
TreeNode* TreeNode::GeneralTree::findNode(TreeNode* node, int data)
{
	if (node == nullptr)
	{
		return nullptr;
	}
	if (node->Data == data)
	{
		return node;
	}
	for (auto count = node->children.begin(); count != node->children.end(); count++)
	{
		TreeNode* child = *count;
		TreeNode* found = findNode(child, data);
		if (found != nullptr)
		{
			return found;
		}
	}
	return nullptr;
}

/// <summary>
/// Recursive function that searches every branch and level to find the parent of a 
/// child node.
/// </summary>
/// <param name="currentNode"> The current node being inspected during the recirsive search. Its a pointer 
/// to the current node being considered as a parent to node of the 'childnode'</param>
/// <param name="childNode">its a pointer to the node that we want to find the parent to</param>
/// <returns>If the childNode is found, it will return the parents, if the child is not 
/// found, it will return a nullptr</returns>
TreeNode* TreeNode::GeneralTree::findParent(TreeNode* currentNode, TreeNode* childNode)
{
	//Returns a nullptr if the childNode is not found in the subtree rooted at this node. 
	if (currentNode == nullptr)
	{
		return nullptr;
	}
	//Iterates trough the list looking and are looking for the childNode. 
	for(auto count= currentNode->children.begin();count != currentNode->children.end();count ++)
	{
		//iterates trough each child of the 'currentNode', if the 'child' matches the 'childNode', the 'currentNode'
		//is the parent, and returns the currentNode as the parent. 
		TreeNode* child = *count;
		if (child == childNode)
		{
			return currentNode;
		}
		TreeNode* parent = findParent(child, childNode);
		if (parent != nullptr)
		{
			return parent;
		}
	}
	return nullptr;
}

/// <summary>
/// This function deletes all the node recursively from the given node. First we check if there is a nullptr. 
/// This is the base case, when we reaches a leaf the recursion stops and begin to returning back up the call stack. 
/// </summary>
/// <param name="node">The current node to be deleted</param>
void TreeNode::GeneralTree::destroyTree(TreeNode* node)
{
	if (node == nullptr)
	{
		return;
	}
	for(auto count = node->children.begin(); count != node->children.end(); count++)
	{
		TreeNode* child = *count;
		destroyTree(child);
	}
	delete node;
}


