#include "BinarySearchTree.h"

using std::cout;
using std::endl;

Node* insert(Node* node, int data) 
{ 
    if (node == nullptr) 
    { 
        return new Node(data); 
    } 
    if (data < node->data) 
    { 
        node->left = insert(node->left, data); 
    } 
    else 
    { 
        node->right = insert(node->right, data); 
    } 
    return node; 
}

int get_max_height(Node* root)
{
    if (root==nullptr)
    {
        return 0;
    }
    
    if (root->left == nullptr && root->right == nullptr)
    {
        return 1;
    }
    if (root->left == nullptr)
    {
        return get_max_height(root->right) + 1;
    }
    if (root->right == nullptr)
    {
        return get_max_height(root->left) + 1;
    }
    return std::max(get_max_height(root->left), get_max_height(root->right)) + 1;
}

void inorder_traversal(Node* root)
{
    if (root->left==nullptr && root->right == nullptr)
    {
        cout<<root->data<<" ";
        return;
    }
    if (root->left != nullptr)
    {
        inorder_traversal(root->left);
    }
    cout<<root->data<<" ";
    if (root->right != nullptr)
    {
        inorder_traversal(root->right);
    }
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

void level_order_traversal(Node* root)
{
    std::queue<Node*> odd_level;
    std::queue<Node*> even_level;
    std::queue<int> output_data;
    odd_level.push(root);
    while (!odd_level.empty() && !even_level.empty())
    {
        while (!odd_level.empty())
        {
            Node* odd_top = odd_level.front();
            output_data.push(odd_top->data);
            if (odd_top->left != nullptr)
            {
                even_level.push(odd_top->left);
            }
            if (odd_top->right != nullptr)
            {
                even_level.push(odd_top->right);
            }
            odd_level.pop();
        }
        while (!even_level.empty())
        {
            Node* even_top = even_level.front();
            output_data.push(even_top->data);
            if (even_top->left != nullptr)
            {
                odd_level.push(even_top->left);
            }
            if (even_top->right != nullptr)
            {
                odd_level.push(even_top->right);
            }
            even_level.pop();
        }
    }
    while (!output_data.empty())
    {
        int val = output_data.front();
        cout<<val<<" ";
        output_data.pop();
    }
}

int find_inorder_successor(Node* root)
{
    if (root->left==nullptr || root->right==nullptr)
    {
        throw std::runtime_error("Leaf node doesn't have successor");
    }
    if (root->left!=nullptr)
    {
        return find_inorder_successor(root->left);
    }
    return find_inorder_successor(root->right);
}

Node* delete_by_key(Node* root, int key)
{
    if (root==nullptr)
    {
        return root;
    }
    if (key > root->data)
    {
        root->right = delete_by_key(root->right, key);
    }
    if (key < root->data)
    {
        root->left = delete_by_key(root->left, key);
    }
    // this is the node we need to delete
    // if it is a leaf node, just delete it
    if (root->left == nullptr && root->right == nullptr)
    {
        delete root;
        return nullptr;
    }
    // if it has only one child, make the child as new node
    if (root->left == nullptr)
    {
        Node *tmp = root->right;
        delete root;
        return tmp;
    }
    if (root->right == nullptr)
    {
        Node *tmp = root->left;
        delete root;
        return tmp;
    }
    // if is has two children, find the inorder node
    int inorder_successor_value = find_inorder_successor(root);
    root->data = inorder_successor_value;
    root = delete_by_key(root, inorder_successor_value);
    return root;
}
