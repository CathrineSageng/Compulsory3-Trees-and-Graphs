#pragma once
#include <iostream>
#include <list>
using namespace std; 

class TreeNode
{
public: 
	//int member variable
	int Data;
	
	// using the std::list for the children in the tree
	//this is a container for storing the nodes
	list<TreeNode*> children;

	//This is the constuctur of the Treenode class
	//The constuctor is a special member function of the 
		//class that gets called autom when an object of the class is created.
	//The constructor takes an integer parameter called 'data'
	TreeNode(int data);

	//First declare the variable 'Treenode* child'
	//Here we create a pointer to a 'Treenode object' with 'Treenode* child'.
	void addChild(TreeNode* child);

	class GeneralTree
	{
	private:
		//Here a 'Treenode* root' pointer is declared. 
		//The pointer varible is named 'root' and can point to a 'Treenode' object. 
		//Here the pointer is uninitialized, it does not point to any valid memory location yet.
		//It needs a valid memory adress before you can use it to access or manipulate a 'Treenode' object. 
		TreeNode* root;
	public:
		//This is the constuctor of the GeneralTree class
		//The consrtuctor takes an integer parameter called 'rootValue'
		GeneralTree(int rootValue);

		//Returns the root of the tree
		TreeNode* getRoot();
		//Returns the parents of the assigned treeNode
		TreeNode* getParent(TreeNode* node);
		//Returns a list of children of the node being assigned
		list<TreeNode*> getChildren(TreeNode* node);

		//Here we create a pointer to a 'Treenode object' with 'Treenode* node'.
		int getSize(TreeNode* node);
		//Here we create a pointer to a 'Treenode object' with 'Treenode* node'.
		int getDepth(TreeNode* node);
		//Checks if a tree is empty
		bool isEmpty();
		//checks if the assigned node is the root of the tree
		bool isRoot(TreeNode* node);
		//checks if the assigned node is a leaf of the tree
		bool isLeaf(TreeNode* node);

		//The two insertNode work together. First adds a child on the parentNode, second finds the parentNode
		//who will get a new child and inserts the new node as the parents child
		void insertNode(TreeNode* parentNode, int data);
		void insertNode(int parentValue, int data);

		//This two functions deletes the assigned nodes and root of the tree
		void deleteNode(TreeNode* node);
		void deleteRoot();

		//This is a destructor, passinf in the 'root' as an argument. Here a GeneralTree object is deleted. 
		//The nodes in the tree are deallocated from memory, this is to prevent memory leaks. 
		~GeneralTree()
		{
			destroyTree(root);
		}

		//Traverses the tree vertical from the left to rhe right. 
		void depthFirstTraversal(TreeNode* node);

		//Searching the tree for a given node
		TreeNode* findNode(TreeNode* node, int data);
		//Searching the tree for a given parent 
		TreeNode* findParent(TreeNode* currentNode, TreeNode* childNode);

		private:
		//Deletes all the nodes in the tree. 
		void destroyTree(TreeNode* node);
		
	};
};

