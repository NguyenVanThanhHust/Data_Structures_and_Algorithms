/**
* From Leetcode
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <iostream>
#include <queue>
#include <climits>
#include <array>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode* parent;
	TreeNode() : val(0), left(nullptr), right(nullptr), parent(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr), parent(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right), parent(nullptr) {}
};

void printLevelOrder(TreeNode* root);
void printPreOrderTraversal(TreeNode* root);
void printInOrderTraversal(TreeNode* root);
void printPostOrderTraversal(TreeNode* root);

void insertByLevel(TreeNode* root, int val);

TreeNode* createNewEmptyNode()
{
	TreeNode* node = new TreeNode();
	return node;
};

TreeNode* createNewTree(vector<int> values)
{
	TreeNode* root = new TreeNode();
	queue<TreeNode*> treeNodes;
	treeNodes.push(root);
	for (auto value : values)
	{
		TreeNode* currentNode = treeNodes.front();
		if (value != 0)
		{
			currentNode->val = value;
			TreeNode* left = new TreeNode();
			TreeNode* right = new TreeNode();
			currentNode->left = left;
			currentNode->right = right;
			treeNodes.push(left);
			treeNodes.push(right);
		}
		treeNodes.pop();
	}
	return root;
};

int main()
{
	TreeNode* root = createNewEmptyNode();
	root->val = 1;
	root->left = createNewEmptyNode();
	root->left->val = 2;
	root->right = createNewEmptyNode();
	root->right->val = 3;

	cout << "Level order: ";
	printLevelOrder(root);
	cout << " \n Pre Order: ";
	printPreOrderTraversal(root);
	cout << " \n In Order: ";
	printInOrderTraversal(root);
	cout << " \n Post Order: ";
	printPostOrderTraversal(root);


	int valToInsert = 4;
	cout << "\n  Insert new val by level: " << valToInsert;
	insertByLevel(root, valToInsert);
	cout << "\n Level order: ";
	printLevelOrder(root);

	// Test if two trees are identical

	return 0;
}

void printLevelOrder(TreeNode* root)
{
	queue<TreeNode*> queueNode;
	queueNode.push(root);
	while (!queueNode.empty())
	{
		TreeNode* topNode = queueNode.front();
		queueNode.pop();
		cout << topNode->val << "  ";
		if (topNode->left != nullptr)
		{
			queueNode.push(topNode->left);
		}
		if (topNode->right != nullptr)
		{
			queueNode.push(topNode->right);
		}
	}
};

void printPreOrderTraversal(TreeNode* root)
{
	if (root == nullptr)
	{
		return;
	}
	cout << root->val << " ";
	printPreOrderTraversal(root->left);
	printPreOrderTraversal(root->right);
};

void printInOrderTraversal(TreeNode* root)
{
	if (root == nullptr)
	{
		return;
	}
	printInOrderTraversal(root->left);
	cout << root->val << " ";
	printInOrderTraversal(root->right);
};

void printPostOrderTraversal(TreeNode* root)
{
	if (root == nullptr)
	{
		return;
	}
	printPostOrderTraversal(root->left);
	printPostOrderTraversal(root->right);
	cout << root->val << " ";
};

void insertByLevel(TreeNode* root, int val)
{
	queue<TreeNode*> treeNodes;
	treeNodes.push(root);
	while (!treeNodes.empty())
	{
		TreeNode* currentNode = treeNodes.front();
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
