#include "ExpressionTree.h"
#include <iostream>
#include <sstream>                  // stringstream: splits the tokens
#include <stack>                    // std::stack: Week 4's Stack, any type
#include <stdexcept>                // runtime_error
using namespace std;

bool isOperator(const string& token)
{
    return token == "+" || token == "-" || token == "*" || token == "/";
}

// ============================ Q8 ============================
ExprNode* buildFromPostfix(const string& postfix)
{
    stack<ExprNode*> st;            // holds finished subtrees
    stringstream ss(postfix);
    string token;
    while (ss >> token) {           // one token at a time: "3", "4", "+"
        ExprNode* node = new ExprNode{ token, nullptr, nullptr };

        if (isOperator(token)) {
            // Operatör için en az iki operand gerekir ("3 +" hatalý)
            if (st.size() < 2) {
                delete node;
                while (!st.empty()) { destroyExpr(st.top()); st.pop(); }
                throw runtime_error("Invalid postfix expression");
            }
            node->right = st.top();  st.pop();   // ilk çekilen = SAÐ çocuk
            node->left = st.top();  st.pop();   // sonra gelen = SOL çocuk
        }
        st.push(node);                           // bitmiþ alt aðacý geri koy
    }

    // Sonunda stack'te tam 1 düðüm (kök) kalmalý ("3 4" hatalý)
    if (st.size() > 1) {
        while (!st.empty()) { destroyExpr(st.top()); st.pop(); }
        throw runtime_error("Invalid postfix expression");
    }

    return st.empty() ? nullptr : st.top();
}

void printPrefix(const ExprNode* node)
{
    if (node == nullptr)
        return;
    cout << node->data << " ";      // operator first: Polish notation
    printPrefix(node->left);
    printPrefix(node->right);
}

void printPostfix(const ExprNode* node)
{
    if (node == nullptr)
        return;
    printPostfix(node->left);
    printPostfix(node->right);
    cout << node->data << " ";      // operator last: reverse Polish
}

// ============================ Q9 ============================
void printInfix(const ExprNode* node)
{
    if (node == nullptr)
        return;

    if (isOperator(node->data)) {
        cout << "(";
        printInfix(node->left);
        cout << " " << node->data << " ";
        printInfix(node->right);
        cout << ")";
    }
    else {
        cout << node->data;         // sayý: parantezsiz
    }
}

double evaluate(const ExprNode* node)
{
    if (node == nullptr)
        throw runtime_error("Empty expression");

    if (!isOperator(node->data))
        return stod(node->data);    // yaprak: sayý

    double l = evaluate(node->left);    // önce iki çocuk (postorder)
    double r = evaluate(node->right);

    if (node->data == "+") return l + r;
    if (node->data == "-") return l - r;
    if (node->data == "*") return l * r;

    // son ihtimal: "/"
    if (r == 0.0)
        throw runtime_error("Division by zero");
    return l / r;
}

void destroyExpr(ExprNode* node)
{
    if (node == nullptr)
        return;
    destroyExpr(node->left);
    destroyExpr(node->right);
    delete node;
}
