#include "BST.h"
#include "TreeUtils.h"
#include <iostream>
using namespace std;

BST::BST()
{
    root = nullptr;
}

BST::~BST()
{
    destroy(root);                  // postorder delete of every node
}

// ============================ Q4 ============================
bool BST::insert(int value)
{
    bool inserted = false;
    root = insertInto(root, value, inserted);
    return inserted;
}

TreeNode* BST::insertInto(TreeNode* node, int value, bool& inserted)
{
    if (node == nullptr)                       // boþ yer bulundu
    {
        inserted = true;
        return makeNode(value);
    }

    if (value < node->data)
        node->left = insertInto(node->left, value, inserted);
    else if (value > node->data)
        node->right = insertInto(node->right, value, inserted);
    // eþitse: tekrar eden deðer, eklenmez (inserted false kalýr)

    return node;
}

// ============================ Q5 ============================
bool BST::find(int value) const
{
    TreeNode* cur = root;
    while (cur != nullptr)
    {
        if (value == cur->data)
            return true;
        else if (value < cur->data)
            cur = cur->left;
        else
            cur = cur->right;
    }
    return false;
}

bool BST::findMin(int& value) const
{
    if (root == nullptr)
        return false;

    TreeNode* cur = root;
    while (cur->left != nullptr)
        cur = cur->left;

    value = cur->data;
    return true;
}

bool BST::findMax(int& value) const
{
    if (root == nullptr)
        return false;

    TreeNode* cur = root;
    while (cur->right != nullptr)
        cur = cur->right;

    value = cur->data;
    return true;
}

// ============================ Q7 ============================
bool BST::remove(int value)
{
    bool removed = false;
    root = removeFrom(root, value, removed);
    return removed;
}

TreeNode* BST::removeFrom(TreeNode* node, int value, bool& removed)
{
    if (node == nullptr)                       // deðer aðaçta yok
        return nullptr;

    if (value < node->data)
    {
        node->left = removeFrom(node->left, value, removed);
    }
    else if (value > node->data)
    {
        node->right = removeFrom(node->right, value, removed);
    }
    else                                       // silinecek düðüm bulundu
    {
        removed = true;

        // Yaprak veya tek çocuklu durumlar
        if (node->left == nullptr)
        {
            TreeNode* rightChild = node->right;
            delete node;
            return rightChild;
        }
        if (node->right == nullptr)
        {
            TreeNode* leftChild = node->left;
            delete node;
            return leftChild;
        }

        // Ýki çocuk: sað alt aðacýn en küçüðü (inorder successor)
        TreeNode* succ = node->right;
        while (succ->left != nullptr)
            succ = succ->left;

        node->data = succ->data;               // successor deðerini kopyala
        bool dummy = false;
        node->right = removeFrom(node->right, succ->data, dummy);  // successor'ý sil
    }

    return node;
}

// ============================ wrappers ============================
void BST::preorder() const { ::preorder(root); }
void BST::inorder() const { ::inorder(root); }
void BST::postorder() const { ::postorder(root); }
int  BST::height() const { return ::height(root); }
bool BST::isBalanced() const { return ::isBalanced(root); }
bool BST::isEmpty() const { return root == nullptr; }
