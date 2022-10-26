// UVA 536 Tree Recovery
#include <iostream>
#include <string>
#include <vector>
#include <cstring> 
#include <algorithm>

using namespace std;


// https://java2blog.com/split-string-space-cpp/#Using_stdstrtok2
void split_string(string& line, vector<string>& strings, const char* delimeter)
{
    char* token = strtok(const_cast<char*>(line.c_str()), delimeter);
    while (token != nullptr)
    {
        strings.push_back(string(token));
        token = strtok(nullptr, delimeter);
    }
}

void printPostOrder(string& preOrder, string& inOrder, int length)
{
    if (length==1 || length==0)
    {
        cout<<preOrder;
        return;
    }
    string head = preOrder.substr(0, 1);
    int headPos = inOrder.find(head);

    int leftLength = headPos;
    int rightLength = max(length - (headPos+1), 0);

    if (leftLength>0)
    {
        string preLeft = preOrder.substr(1, leftLength);
        string inLeft = inOrder.substr(0, leftLength);
        printPostOrder(preLeft, inLeft, leftLength);
    }
    if (rightLength>0)
    {
        string preRight = preOrder.substr(leftLength+1, rightLength);
        string inRight = inOrder.substr(headPos+1, rightLength);
        printPostOrder(preRight, inRight, rightLength);
    }
    cout<<head;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    std::string preOrder, inOrder;
    std::string line;
    // freopen("local_test_case.txt", "r", stdin);
    const char* delimeter = " ";
    while (std::getline(cin, line))
    {
        vector<string> tree;
        split_string(line, tree, delimeter);
        preOrder = tree[0];
        inOrder = tree[1];
        int len = preOrder.size();
        printPostOrder(preOrder, inOrder, len);
        cout << endl;
    }
    return 0;
}