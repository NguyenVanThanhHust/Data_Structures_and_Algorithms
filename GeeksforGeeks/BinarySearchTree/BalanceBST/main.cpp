#include "BinarySearchTree.h"

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>

using std::cin;
using std::cout;
using std::endl;

class my_exception : public std::runtime_error {
    std::string msg;
public:
    my_exception(const std::string &arg, const char *file, int line) :
    std::runtime_error(arg) {
        std::ostringstream o;
        o << file << ":" << line << ": " << arg;
        msg = o.str();
    }
    ~my_exception() throw() {}
    const char *what() const throw() {
        return msg.c_str();
    }
};
#define throw_line(arg) throw my_exception(arg, __FILE__, __LINE__);

int main()
{
    freopen("../sample_data.txt", "r", stdin);

    int num_test_case;
    cin>>num_test_case;
    std::string line;
    cout<<num_test_case<<endl;
    while (num_test_case != 0)
    {
        try
        {
            int num_element_in_tree;
            cin>>num_element_in_tree;
            cout<<num_element_in_tree<<"---";
            int number;
            std::queue<int> numbers;
            for (int i = 0; i < num_element_in_tree; i++)
            {
                cin>>number;
                numbers.push(number);
            }
            
            Node* root = nullptr;
            cout<<"Start to insert to tree"<<endl;
            while (!numbers.empty())
            {
                int top_number = numbers.front();
                root = insert(root, top_number);
                numbers.pop();
                cout<<top_number<<"--";
            }
            
            cout<<endl<<"inorder traversal"<<endl;
            // // Print inorder traversal of the BST
            inorder_traversal(root);
            std::cout<<std::endl;
            num_test_case--;
            cout<<num_test_case<<endl;

        }
        catch (const std::runtime_error &ex) 
        {
            std::cout << ex.what() << std::endl;
        }
    }
    return 0;
}