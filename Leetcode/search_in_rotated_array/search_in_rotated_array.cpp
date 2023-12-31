//https://leetcode.com/problems/search-in-rotated-sorted-array/
#pragma once
#include <iostream>
#include <string>
#include <filesystem>
#include <sstream>

using namespace std;

int findStart(vector<int>& inputData, int target, int left, int right)
{
	if (right - left <= 3)
	{
		int startIndex = left;
		for (int i = left; i <= right; i++)
		{
			if (inputData[i] <= inputData[startIndex])
			{
				startIndex = i;
			}
		}
		return startIndex;
	}
	int middle = (left + right) / 2;
	if (inputData[middle] < inputData[left] && inputData[middle] < inputData[right])
	{
		return findStart(inputData, target, left, middle);
	}
	else if (inputData[middle] > inputData[left] && inputData[middle] > inputData[right])
	{
		return findStart(inputData, target, middle + 1, right);
	}
	else
	{
		return findStart(inputData, target, left, middle);
	}
}

int binarySearch(vector<int>& inputData, int target, int left, int right)
{
	if (right - left <=3)
	{
		for (int i = left; i <= right; i++)
		{
			if (inputData[i] == target)
			{
				return i;
			}
		}
		return -1;
	}

	int middle = (left + right) / 2;
	if (inputData[middle] == target)
	{
		return middle;
	}
	if (inputData[middle] < target)
	{
		return binarySearch(inputData, target, middle + 1, right);
	}
	return binarySearch(inputData, target, left, middle);
}

int search(vector<int>& nums, int target)
{
	int right = nums.size() - 1;
	int startIndex = findStart(nums, target, 0, right);
	int offset = right - startIndex;

	vector<int> originalArray;
	originalArray.reserve(nums.size());

	std::move(nums.begin() + startIndex, nums.end(), std::back_inserter(originalArray));
	std::move(nums.begin(), nums.begin() + startIndex, std::back_inserter(originalArray));

	int originalIndex = binarySearch(originalArray, target, 0, right);
	if (originalIndex == -1)
	{
		return originalIndex;
	}
	return (originalIndex + startIndex) % nums.size();
}


int main()
{
	string testFile = "search_in_rotated_array.txt";
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
		int result = search(inputData, key);
		int expectOutput;

		cin >> expectOutput;
		if (expectOutput != result)
		{
			cout << "Case " << t << " is failed" << endl;
			cout << "Expect: " << expectOutput << " get: " << result << endl;
		}
	}
	return 0;
}