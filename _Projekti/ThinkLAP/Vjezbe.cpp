#include "Vjezbe.hpp"



// rjeseno
int binaryTree::privateCountLeaves(treePtr rootPtr) {
	if(rootPtr == nullptr) return 0;
	if(rootPtr->right == nullptr && rootPtr->left == nullptr)
		return 1;
	const int leftCount = privateCountLeaves(rootPtr->left);
	const int rightCount = privateCountLeaves(rootPtr->right);
	return leftCount + rightCount;
}
int binaryTree::publicCountLeaves() {
	return privateCountLeaves(_root);
}