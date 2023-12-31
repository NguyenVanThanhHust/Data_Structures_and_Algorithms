//https://leetcode.com/problems/valid-perfect-square/
#pragma once
#include <iostream>
#include <string>
#include <filesystem>
#include <sstream>

using namespace std;

// Copy from : https://walkccc.me/LeetCode/problems/0367/
bool isPerfectSquare(int num)
{
	long l = 1;
	long r = num;

	while (l < r) {
		const long m = (l + r) / 2;
		if (m >= num / m)
			r = m;
		else
			l = m + 1;
	}

	return l * l == num;
};

int main()
{
	string testFile = "valid_perfect_square.txt";
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
		int input;
		cin >> input;
		int result = isPerfectSquare(input);
		cout << result << endl;
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