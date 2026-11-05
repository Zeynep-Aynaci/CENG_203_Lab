#include "TreeUtils.h"
#include <iostream>
#include <queue>                    // std::queue: the library version of
#include <algorithm>                // std::max
#include <cstdlib>                  // std::abs
using namespace std;                // Week 4's Queue, for any type

TreeNode* makeNode(int value)
{
    TreeNode* node = new TreeNode;
    node->data = value;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

// ============================ Q2 ============================
void preorder(const TreeNode* node)
{
    if (node == nullptr)            // base case: boþ aðaç
        return;
    cout << node->data << " ";      // node
    preorder(node->left);           // left
    preorder(node->right);          // right
}

void inorder(const TreeNode* node)
{
    if (node == nullptr)
        return;
    inorder(node->left);            // left
    cout << node->data << " ";      // node
    inorder(node->right);           // right
}

void postorder(const TreeNode* node)
{
    if (node == nullptr)
        return;
    postorder(node->left);          // left
    postorder(node->right);         // right
    cout << node->data << " ";      // node
}

int countNodes(const TreeNode* node)
{
    if (node == nullptr)
        return 0;
    return 1 + countNodes(node->left) + countNodes(node->right);
}

int countLeaves(const TreeNode* node)
{
    if (node == nullptr)            // önce nullptr testi
        return 0;
    if (node->left == nullptr && node->right == nullptr)
        return 1;                   // yaprak: çocuðu yok
    return countLeaves(node->left) + countLeaves(node->right);
}

// ============================ Q3 ============================
int height(const TreeNode* node)
{
    if (node == nullptr)
        return -1;                  // boþ aðaç = -1, yaprak = 0
    return 1 + max(height(node->left), height(node->right));
}

void levelOrder(const TreeNode* node)
{
    if (node == nullptr)
        return;

    queue<const TreeNode*> q;
    q.push(node);                   // kökü kuyruða koy

    while (!q.empty())
    {
        const TreeNode* cur = q.front();   // pop deðer döndürmez: önce front()
        q.pop();
        cout << cur->data << " ";

        if (cur->left != nullptr)
            q.push(cur->left);
        if (cur->right != nullptr)
            q.push(cur->right);
    }
}

// ============================ Q6 ============================
bool isBalanced(const TreeNode* node)
{
    if (node == nullptr)            // boþ aðaç dengelidir
        return true;

    int diff = height(node->left) - height(node->right);
    if (abs(diff) > 1)              // bu düðümde kural bozuldu
        return false;

    // Her düðümde geçerli olmalý: iki alt aðaç da dengeli olmalý
    return isBalanced(node->left) && isBalanced(node->right);
}

// ============================ memory ============================
void destroy(TreeNode* node)
{
    if (node == nullptr)
        return;
    destroy(node->left);            // children first ...
    destroy(node->right);
    delete node;                    // ... the node last (postorder)
}
