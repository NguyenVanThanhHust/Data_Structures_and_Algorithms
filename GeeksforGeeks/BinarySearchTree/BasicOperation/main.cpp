#include "BinarySearchTree.h"

using std::cout;
using std::endl;

int main()
{
    Node* root = new Node(50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    // Print inorder traversal of the BST
    inorder_traversal(root);
    std::cout<<std::endl;

    // Search 
    bool is_80 = search(root, 80);
    cout<<"is_80: "<<is_80<<endl;
    bool is_90 = search(root, 90);
    cout<<"is_90: "<<is_90<<endl;


    return 0;
}