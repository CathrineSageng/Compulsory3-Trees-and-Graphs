#pragma once
#include <vector>
#include <iostream>
using namespace std; 

class TreeNode
{
public: 
	int Data;
	vector<TreeNode*> children;

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
		bool isEmpty();
		bool isRoot();
	};
};

