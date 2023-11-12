#pragma once
#include <array>



// rjeseno
class binaryTree
{
public:
	int publicCountLeaves();
private:
	struct binaryTreeNode
	{
		int data;
		binaryTreeNode* left;
		binaryTreeNode* right;
	};
	typedef binaryTreeNode* treePtr;
	treePtr _root;
	int privateCountLeaves(treePtr rootPtr);
};

typedef int INT;