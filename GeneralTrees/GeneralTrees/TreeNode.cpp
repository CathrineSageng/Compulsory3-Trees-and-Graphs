#include "TreeNode.h"

TreeNode::TreeNode(int data)
{
	Data = data;
}

//push_back push elements into a list from the back. The new value is inserted at the end of a list. 
//This increases the size by 1 in the container treenode.
void TreeNode::addChild(TreeNode* child)
{
	children.push_back(child);
}

//The GeneralTree class is nested in the Treenode class. 
TreeNode::GeneralTree::GeneralTree(int rootValue)
{
	//A new 'Treenode' object is allocated on the heap memory using the 'new' keyword. 
	//The constuctor of the 'Treenode' is called with the provided 'rootValue' parameter and the memory adress
		// of the newly created created 'Treenode' object.
	//Now the 'root' pointer points to a root node of the tree
	root = new TreeNode(rootValue);
}

//'getRoot' takes no parameter and is the function name. 
//Here it reuturns a pointer to the 'Treenode' object, the adress of the root. 
TreeNode* TreeNode::GeneralTree::getRoot()
{
	return root;
}

TreeNode* TreeNode::GeneralTree::getParent(TreeNode* node)
{
	return findParent(root, node);
}

list<TreeNode*> TreeNode::GeneralTree::getChildren(TreeNode* node)
{
	return node->children;
}

int TreeNode::GeneralTree::getSize(TreeNode* node)
{
	if (node == nullptr)
	{
		return 0;
	}
	int size = 1;
	for (TreeNode* child : node->children)
	{
		size += getSize(child);
	}
	return size;
}

int TreeNode::GeneralTree::getDepth(TreeNode* node)
{
	if (node == nullptr)
	{
		return 0;
	}
	int depth = 0;
	for (TreeNode* child : node->children)
	{
		depth = max(depth, 1 + getDepth(child));
	}
	return depth;
}

bool TreeNode::GeneralTree::isEmpty()
{
	return root== nullptr;
}

bool TreeNode::GeneralTree::isRoot(TreeNode* node)
{
	return node==root;
}

bool TreeNode::GeneralTree::isLeaf(TreeNode* node)
{
	return (node != nullptr && node->children.empty());
}

void TreeNode::GeneralTree::insertNode(TreeNode* parentNode, int data)
{
	TreeNode* newNode = new TreeNode(data);
	parentNode->addChild(newNode);
}

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

void TreeNode::GeneralTree::deleteNode(TreeNode* node)
{
	TreeNode* parent = getParent(node);
	if (parent != nullptr)
	{
		auto it = find(parent->children.begin(), parent->children.end(), node);
		if (it != parent->children.end())
		{
			parent->children.erase(it);
			destroyTree(node);
		}
	}
	else if (node == root)
	{
		destroyTree(root);
		root = nullptr;
	}
}

void TreeNode::GeneralTree::depthFirstTraversal(TreeNode* node)
{
	if (node == nullptr)
	{
		return;
	}
	cout << node->Data << " ";
	for (TreeNode* child : node->children)
	{
		depthFirstTraversal(child);
	}
}

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
	for (TreeNode* child : node->children)
	{
		TreeNode* found = findNode(child, data);
		if (found != nullptr)
		{
			return found;
		}
	}
	return nullptr;
}

TreeNode* TreeNode::GeneralTree::findParent(TreeNode* currentNode, TreeNode* childNode)
{
	if (currentNode == nullptr)
	{
		return nullptr;
	}
	for (TreeNode* child : currentNode->children)
	{
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

void TreeNode::GeneralTree::destroyTree(TreeNode* node)
{
	if (node == nullptr)
	{
		return;
	}
	for (TreeNode* child : node->children)
	{
		destroyTree(child);
	}
	delete node;
}


