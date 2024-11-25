#include <queue>
#include <iostream>
struct Node
{
    int data;
    Node *left=nullptr;
    Node *right=nullptr;
    Node(int item)
    {
        data = item;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int key);
void inorder_traversal(Node* root);
bool search(Node* root, int key);
void delete_by_key(Node* root, int key);
