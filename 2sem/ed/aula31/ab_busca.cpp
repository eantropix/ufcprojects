#include <iostream>

template <typename T>

struct Node 
    {
        T element; 
        Node<T> *cleft, *cright;  // Child left, child right
    };

template <typename T>
bool createTree (Node<T> &root)
{
    root = new(nothrow) Node<T>;
    if (root == nullptr) return true;
    root.cleft = nullptr; root.cright = nullptr;
    return false;
}

template <typename T>
bool addElement (Node<T> *root, T e)  // Adds element 'e' into tree, from pointer to root.
{

}

template <typename T>
bool contains (Node<T> *root, T e)  // Checks if element 'e' is within the tree, from pointer to root
{  // 'contains' does not go through the entire tree!
    if (root == nullptr)      return false;
    if (e == root->element)   return true;  // Element is the root
    if (e  < root->element)   return contains(root->cleft, e);  // Element is to the left subtree
    else/*(e>root->element)*/ return contains(root->cright, e); // Element is to the right subtree
}
template <typename T>
int height (Node<T> *root)
{
    if (root == nullptr) return 0;  // If tree is empty, height is 0
    int hleft = height(root->cleft);
    int hright = height(root->cright);
    if (hleft > hright)  return (hleft + 1);
    else                 return (hright + 1);
}

template <typename T>
int printHeight (Node<T> *root)
{
    
}

template <typename T>
void printDepth (Node<T> *root, int parent_depth)
{
    if (root == nullptr)  return;
    ++parent_depth;
    cout << 'd(' << root->element << ') = ' << parent_depth;
    printDepth (root->cleft, parent_depth);
    printDepth (root->cright, parent_depth);
}
