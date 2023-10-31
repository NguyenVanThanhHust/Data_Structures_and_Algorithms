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
				break;
			}
		}
		cout << "This case is passed" << endl;
	}
	return 0;
}