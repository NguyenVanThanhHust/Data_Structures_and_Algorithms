//https://leetcode.com/problems/search-insert-position/

#include <iostream>
#include <string>
#include <filesystem>
#include <sstream>

using namespace std;

int find_insert_position(vector<int> &inputData, int key, int left, int right)
{
	if (right == left)
	{
		if (inputData[right] < key)
		{
			return right + 1;
		}
		return right;
	}
	int middle = (left + right) / 2;
	if (inputData[middle] == key)
	{
		return middle;
	}
	if (inputData[middle] > key)
	{
		return find_insert_position(inputData, key, left, middle);
	}
	return find_insert_position(inputData, key, middle + 1, right);
}

int searchInsert(vector<int>& nums, int target)
{
	int left = 0;
	int right = nums.size() - 1;
	return find_insert_position(nums, target, left, right);
}

int main()
{
	string testFile = "search_insert_position.txt";
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
		int resOutput = searchInsert(inputData, key);
		int expectOutput;

		cin >> expectOutput;
		if (expectOutput != resOutput)
		{
			cout << "Case " << t << " is failed" << endl;
			cout << "Expect: " << expectOutput << " get: " << resOutput << endl;
			break;
		}
	}
	return 0;
}