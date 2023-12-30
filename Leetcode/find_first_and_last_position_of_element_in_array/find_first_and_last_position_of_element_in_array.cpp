//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
#pragma once
#include <iostream>
#include <string>
#include <filesystem>
#include <sstream>

using namespace std;

int findFirst(vector<int>& inputData, int key, int left, int right)
{
	if (inputData.size() == 0)
	{
		return -1;
	}
	if (right == left)
	{
		if (inputData[left] == key)
		{
			return left;
		}
		return -1;
	}

	int middle = (left + right) / 2;
	if (inputData[middle] < key)
	{
		int newLeft = middle + 1;
		return findFirst(inputData, key, newLeft, right);
	}
	return findFirst(inputData, key, left, middle);
}

int findLast(vector<int>& inputData, int key, int left, int right)
{
	if (inputData.size() == 0)
	{
		return -1;
	}
	if (right == left)
	{
		if (inputData[left] == key)
		{
			return left;
		}
		return -1;
	}

	
	int middle = (left + right) / 2;
	if (inputData[middle] == key)
	{
		int tempLast = findLast(inputData, key, middle+1, right);
		if (tempLast != -1)
		{
			return tempLast;
		}
		return middle;
	}
	else if (inputData[middle] < key)
	{
		return findLast(inputData, key, middle+1, right);
	}
	else
	{
		return findLast(inputData, key, left, middle);
	}
}

vector<int> searchRange(vector<int>& nums, int target)
{
	vector<int> output;
	int inputSize = nums.size();
	int first = findFirst(nums, target, 0, inputSize - 1);
	int last = findLast(nums, target, 0, inputSize - 1);
	output.push_back(first);
	output.push_back(last);
	return output;
}


int main()
{
	string testFile = "find_first_and_last_position_of_element_in_array.txt";
	if (!std::filesystem::exists(testFile))
	{
		cout << "Can't find test case: " << testFile;
		return 1;
	}
	freopen(testFile.c_str(), "r", stdin);
	int numTestCase;
	cin >> numTestCase;
	cout << "number of test case: " << numTestCase << endl;
	for (int t = 0; t < numTestCase; t++)
	{
		cout << "Start case: " << t << endl;
		int inputSize, num;
		cin >> inputSize;
		vector<int> inputData;
		for (int i = 0; i < inputSize; i++)
		{
			cin >> num;
			inputData.push_back(num);
		}
		int key;
		cin >> key;
		vector<int> resOutput = searchRange(inputData, key);
		vector<int> expectOutput;

		cin >> num;
		expectOutput.push_back(num);
		cin >> num;
		expectOutput.push_back(num);
		for (int i = 0; i < 2; i++)
		{
			if (expectOutput[i] != resOutput[i])
			{
				cout << "Case " << t << " is failed" << endl;
				cout << "Expect: " << expectOutput[i] << " get: " << resOutput[i] << endl;
				break;
			}
		}
	}
	return 0;
}