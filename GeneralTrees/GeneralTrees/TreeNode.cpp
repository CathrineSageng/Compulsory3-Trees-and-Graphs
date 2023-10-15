#include "TreeNode.h"

TreeNode::TreeNode(int data)
{
	Data = data;
}

void TreeNode::addChild(TreeNode* child)
{
	children.push_back(child);
}

TreeNode::GeneralTree::GeneralTree(int rootValue)
{
	root = new TreeNode(rootValue);
}

TreeNode* TreeNode::GeneralTree::getRoot()
{
	return root;
}

TreeNode* TreeNode::GeneralTree::getParent(TreeNode* node)
{
	return findParent(root, node);
}

bool TreeNode::GeneralTree::isEmpty()
{
	return root== nullptr;
}

bool TreeNode::GeneralTree::isRoot()
{
	return false;
}


