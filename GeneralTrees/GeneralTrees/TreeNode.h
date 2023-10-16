#pragma once
#include <queue>
#include <iostream>
#include <list>
using namespace std; 

class TreeNode
{
public: 
	int Data;
	list<TreeNode*> children;

	TreeNode(int data);

	void addChild(TreeNode* child);

	class GeneralTree
	{
	private:
		TreeNode* root;
	public:
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

