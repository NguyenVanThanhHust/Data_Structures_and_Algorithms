#include <queue>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <stdexcept>

struct Node
{
    int data;
    int height;
    Node *left=nullptr;
    Node *right=nullptr;
    Node(int item)
    {
        data = item;
        height = 0;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int key);
int get_max_height(Node* root);
void inorder_traversal(Node* root);
void level_order_traversal(Node* root);
bool search(Node* root, int key);