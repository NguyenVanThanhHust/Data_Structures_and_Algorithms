#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <iostream>
#include <filesystem>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
        bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p || !q)
        {
            return p == q;
        }
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

};
int main()
{
    string testFile = "symmetric_tree.txt";
	if (!std::filesystem::exists(testFile))
	{
		cout << "Can't find test case: " << testFile;
		return 1;
	}
	freopen(testFile.c_str(), "r", stdin);
    int numTestCase;
	cin >> numTestCase;
    for (int testCase = 0; testCase < numTestCase; testCase++)
    {
        std::string line;
        std::getline(std::cin, line);

        std::istringstream iss(line);
        std::vector<std::string> words;
        std::string word;

        while (iss >> word) {
            words.push_back(word);
        }

        // Print the list of strings
        for (const auto& str : words) {
            std::cout << str << std::endl;
        }

    }
    
    return 0;
}