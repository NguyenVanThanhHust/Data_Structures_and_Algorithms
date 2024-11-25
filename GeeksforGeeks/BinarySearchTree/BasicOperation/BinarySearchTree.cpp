#include "BinarySearchTree.h"

using std::cout;
using std::endl;

Node* insert(Node* root, int key)
{
    if (root == nullptr)
    {
        Node *newNode = new Node(key);
        return newNode;
    }
    
    if (root->data == key)
    {
        return root;
    }

    if (root->data < key)
    {
        root->right = insert(root->right, key);
    }
    else
    {
        root->left = insert(root->left, key);
    }
    return root;
}

void inorder_traversal(Node* root)
{
    if (root->left==nullptr && root->right == nullptr)
    {
        cout<<root->data<<" ";
        return;
    }
    inorder_traversal(root->left);
    cout<<root->data<<" ";
    inorder_traversal(root->right);
}

bool search(Node* root, int key)
{
    if (root->data==key)
    {
        return true;
    }
    if (root->data < key)
    {
        if (root->right == nullptr)
        {
            return false;
        }
        return search(root->right, key);
    }
    else
    {
        if (root->left)
        {
            return false;
        }
        return search(root->left, key);
    }
}

void delete_by_key(Node* root, int key)
{
    
}
