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

		TreeNode* getRoot();
		TreeNode* getParent(TreeNode* node);

		list<TreeNode*> getChildren(TreeNode* node);

		int getSize(TreeNode* node);
		int getDepth(TreeNode* node);

		bool isEmpty();
		bool isRoot(TreeNode* node);
		bool isLeaf(TreeNode* node);

		void insertNode(TreeNode* parentNode, int data);
		void insertNode(int parentValue, int data);
		void deleteNode(TreeNode* node);
		void depthFirstTraversal(TreeNode* node);

		~GeneralTree()
		{
			destroyTree(root);
		}

	private:
		TreeNode* findNode(TreeNode* node, int data);
		TreeNode* findParent(TreeNode* currentNode, TreeNode* childNode);

		void destroyTree(TreeNode* node);
		
	};
};

