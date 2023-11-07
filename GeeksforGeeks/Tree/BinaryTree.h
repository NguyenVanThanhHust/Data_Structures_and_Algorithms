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
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	int height;
	TreeNode() : val(0), height(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), height(1), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), height(1+ max(left->height, right->height)), left(left), right(right) {}
};

TreeNode* createNewEmptyNode();
TreeNode* createNewTree(vector<int> values);

void levelOrderTraversal(TreeNode* root, vector<int> &outputs);
void preOrderTraversal(TreeNode* root, vector<int>& outputs);
void inOrderTraversal(TreeNode* root, vector<int>& outputs);
void postOrderTraversal(TreeNode* root, vector<int>& outputs);
void zigZagTraversal(TreeNode* root, vector<int>& outputs);
void inOrderTraversalwithoutRecursion(TreeNode* root, vector<int>& outputs);

void insertByLevel(TreeNode* root, int val);
bool isBalanced(TreeNode* root);
int getHeight(TreeNode* root);
int getDiameter(TreeNode* root);
int isSymmetric(TreeNode* root);

TreeNode* mirrorTree(TreeNode* root);
TreeNode* getLowestCommonAncestor(TreeNode* root, int val1, int val2);