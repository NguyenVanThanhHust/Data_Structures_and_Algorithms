#pragma once
#include <string>
#include <filesystem>
#include <sstream>
#include "BinaryTree.h"

using namespace std;

int main()
{
	cout << "Input type of test: ";
	string testCase, testFile;
	cin >> testCase;
	testFile = testCase + ".txt";
	if (!std::filesystem::exists(testFile))
	{
		cout << "Can't find test case: " << testCase;
		return 1;
	}
	cout << "Start to test case: " << testCase << endl;
	freopen(testFile.c_str(), "r", stdin);
	int numTestCase;
	cin >> numTestCase;
	cout << "number of test case: " << numTestCase << endl;
	for (int t = 0; t < numTestCase; t++)
	{
		int inputSize, num;
		cin >> inputSize;
		vector<int> inputData;
		for (int i = 0; i < inputSize; i++)
		{
			cin >> num;
			inputData.push_back(num);
		}

		vector<int> output;
		// Main algorithm that need to be tested here
		TreeNode* root = createNewTree(inputData);
		if (testCase == "levelOrderTraversal")
		{
			levelOrderTraversal(root, output);
		}
		else if (testCase == "inOrderTraversal")
		{
			inOrderTraversal(root, output);
		}
		else if (testCase == "preOrderTraversal")
		{
			preOrderTraversal(root, output);
		}
		else if (testCase == "postOrderTraversal")
		{
			postOrderTraversal(root, output);
		}
		else if (testCase == "insertLevelOrder")
		{
			int inputVal;
			cin >> inputVal;
			insertByLevel(root, inputVal);
			levelOrderTraversal(root, output);
		}
		else if (testCase == "mirrorTree")
		{
			TreeNode* newRoot = mirrorTree(root);
			levelOrderTraversal(newRoot, output);
		}
		else if (testCase == "isSymmetric")
		{
			int isThisTreeSymmetric = isSymmetric(root);
			output.push_back(isThisTreeSymmetric);
		}
		else if (testCase == "getHeight")
		{
			int height = getHeight(root);
			output.push_back(height);
		}
		else if (testCase == "getDiameter")
		{
			int diameter = getDiameter(root);
			output.push_back(diameter);
		}
		else if (testCase == "inOrderTraversalwithoutRecursion")
		{
			inOrderTraversalwithoutRecursion(root, output);
		}
		else if (testCase == "getPostOrderFromInOrderAndPreOrder")
		{
			// In this case, vector<int> inputData is inOrder Traversal
			// So we need to input preOrder Traversal too
			vector<int> preOrder;
			for (int i = 0; i < inputSize; i++)
			{
				cin >> num;
				preOrder.push_back(num);
			}
			output = getPostOrderFromInOrderAndPreOrder(inputData, preOrder);
		}
		else
		{
			cout << "Unrecogize test case" << endl;
			return 1;
		}

		int expectOutputSize;
		cin >> expectOutputSize;
		cout << "Start to compare result for case: " << t + 1 << endl;
		vector<int> expectOutput;
		for (int i = 0; i < expectOutputSize; i++)
		{
			cin >> num;
			expectOutput.push_back(num);
		}
		int outputSize = output.size();
		for (int i = 0; i < outputSize; i++)
		{
			if (expectOutput[i] != output[i]) 
			{
				cout << "Expect: " << expectOutput[i] << " get: " << output[i] << endl;
				cout << "This case is failed" << endl;
				return 1;
			}
		}
		cout << "This case is passed" << endl;
	}
	return 0;
}