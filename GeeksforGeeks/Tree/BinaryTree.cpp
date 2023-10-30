#pragma once
#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include "BinaryTree.h"

TreeNode* createNewEmptyNode()
{
	TreeNode* node = new TreeNode();
	return node;
};

TreeNode* createNewTree(vector<int> values)
{
	int numInput = values.size();
	TreeNode* root = new TreeNode(values[0]);
	queue<TreeNode*> treeNodes;
	treeNodes.push(root);
	int currentIndex = 1;
	while (!treeNodes.empty())
	{
		TreeNode* topNode = treeNodes.front();
		treeNodes.pop();
		if (values[currentIndex] != 0)
		{
			TreeNode* newLeftNode = new TreeNode(values[currentIndex]);
			topNode->left = newLeftNode;
			treeNodes.push(newLeftNode);
		}
		currentIndex++;
		if (currentIndex == numInput)
		{
			break;
		}
		if (values[currentIndex] != 0)
		{
			TreeNode* newRightNode = new TreeNode(values[currentIndex]);
			topNode->right = newRightNode;
			treeNodes.push(newRightNode);
		}
		currentIndex++;
		if (currentIndex == numInput)
		{
			break;
		}
	}
	return root;
};

void levelOrderTraversal(TreeNode* root, vector<int> &output)
{
	queue<TreeNode*> queueNode;
	queueNode.push(root);
	while (!queueNode.empty())
	{
		TreeNode* topNode = queueNode.front();
		output.push_back(topNode->val);
		if (topNode->left != nullptr)
		{
			queueNode.push(topNode->left);
		}
		if (topNode->right != nullptr)
		{
			queueNode.push(topNode->right);
		}
		queueNode.pop();
	}
};

void preOrderTraversal(TreeNode* root, vector<int>& outputs)
{
	if (root == nullptr)
	{
		return;
	}
	outputs.push_back(root->val);
	preOrderTraversal(root->left, outputs);
	preOrderTraversal(root->right, outputs);
};

void inOrderTraversal(TreeNode* root, vector<int>& outputs)
{
	if (root == nullptr)
	{
		return;
	}
	inOrderTraversal(root->left, outputs);
	outputs.push_back(root->val);
	inOrderTraversal(root->right, outputs);
};

void postOrderTraversal(TreeNode* root, vector<int>& outputs)
{
	if (root == nullptr)
	{
		return;
	}
	postOrderTraversal(root->left, outputs);
	postOrderTraversal(root->right, outputs);
	outputs.push_back(root->val);
};

void zigZagTraversal(TreeNode* root, vector<int>& outputs)
{
	stack<TreeNode*> oddLevel;
	stack<TreeNode*> evenLevel;
	oddLevel.push(root);
	while (!oddLevel.empty() || !evenLevel.empty())
	{
		while (!oddLevel.empty())
		{
			TreeNode* topNode = oddLevel.top();
			if (topNode->val == 0)
			{
				continue;
			}
			if (topNode->right==nullptr)
			{
				TreeNode* newEmptyNode = createNewEmptyNode();
				evenLevel.push(newEmptyNode);
			}
			else
			{
				evenLevel.push(topNode->right);
			}
			if (topNode->left==nullptr)
			{
				TreeNode* newEmptyNode = createNewEmptyNode();
				evenLevel.push(newEmptyNode);
			}
			else
			{
				evenLevel.push(topNode->left);
			}
			oddLevel.pop();
		}
		while (!evenLevel.empty())
		{
			TreeNode* topNode = evenLevel.top();
			if (topNode->val==0)
			{
				continue;
			}
			if (topNode->left == nullptr)
			{
				TreeNode* newEmptyNode = createNewEmptyNode();
				evenLevel.push(newEmptyNode);
			}
			else
			{
				evenLevel.push(topNode->left);
			}
			if (topNode->right == nullptr)
			{
				TreeNode* newEmptyNode = createNewEmptyNode();
				evenLevel.push(newEmptyNode);
			}
			else
			{
				evenLevel.push(topNode->right);
			}
			evenLevel.pop();
		}
	}
}

void inOrderTraversalwithoutRecursion(TreeNode* root, vector<int> &outputs)
{
	stack<TreeNode*> nodes;
	nodes.push(root);
	while (!nodes.empty())
	{
		TreeNode* topNode = nodes.top();
		while (topNode->left != nullptr)
		{
			topNode = topNode->left;
			nodes.push(topNode);
		}
	}

	
}


void insertByLevel(TreeNode* root, int val)
{
	queue<TreeNode*> treeNodes;
	treeNodes.push(root);
	while (!treeNodes.empty())
	{
		TreeNode *currentNode = treeNodes.front();
		treeNodes.pop();
		if (currentNode->left == nullptr)
		{
			TreeNode* newNode = new TreeNode();
			newNode->val = val;
			currentNode->left = newNode;
			break;
		}
		else if (currentNode->right == nullptr)
		{
			TreeNode* newNode = new TreeNode();
			newNode->val = val;
			currentNode->right = newNode;
			break;
		}
		else
		{
			treeNodes.push(currentNode->left);
			treeNodes.push(currentNode->right);
		}
	}
};

bool isIdentical(TreeNode* root1, TreeNode* root2)
{
	queue<TreeNode*> firstTree;
	queue<TreeNode*> secondTree;
	if (root1->val != root2->val)
	{
		return false;
	}
	bool leftIdentical = isIdentical(root1->left, root2->left);
	bool rightIdentical = isIdentical(root1->right, root2->right);
	if (!leftIdentical || !rightIdentical)
	{
		return false;
	}
	return true;
};


TreeNode* mirrorTree(TreeNode* root) {
	// Main idea: depth first search traversal
	// push current node
	TreeNode* newRoot = createNewEmptyNode();
	queue<TreeNode*> treeNodes;
	treeNodes.push(root);
	queue<int> orders;

	while (!treeNodes.empty())
	{
		TreeNode* node = treeNodes.front();
		
		treeNodes.pop();
	}
	return newRoot;
};


bool isBalanced(TreeNode* root)
{
	return true;
};

int getDiameter(TreeNode* root)
{
	return 1;
};
bool isSymmetric(TreeNode* root)
{
	return true;
};

TreeNode* getLowestCommonAncestor(TreeNode* root, int val1, int val2)
{
	TreeNode* node = createNewEmptyNode();
	return node;
}

#endif // !BINARY_TREE_H

