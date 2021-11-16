/*
  Joseph Lee (Sangwoo)
  sl5nj
  4 Oct 2020
*/

// Insert your header information here
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

#include "TreeCalc.h"
#include <iostream>

using namespace std;

// Constructor
TreeCalc::TreeCalc() {
    // in TreeCalc.h "expressionStack" is what I am using
}

// Destructor - frees memory
TreeCalc::~TreeCalc() {
    cleanTree(expressionStack.top());
}

// Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* tree) {
    //might need two separate statement (tree->left != null tree->right != null)
    if(tree != NULL) // not (tree->value != "")
    {
        cleanTree(tree->left);
        cleanTree(tree->right);
        delete tree;
    }
}

// Gets data from user
// DO NOT MODIFY
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0] == '/' || response[0] == '*'
            || response[0] == '-' || response[0] == '+') {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

// Puts value in tree stack
void TreeCalc::insert(const string& val) {
    // insert a value into the tree
    //if val is number simple push it in
    if(isdigit(val[0]) || (val[0] == '-' && isdigit(val[1])))
    {
        TreeNode * number = new TreeNode(val);
        expressionStack.push(number);
    }
    //if val is not a number (operator) top/pop then push
    else //(val[0] == '+' || val[0] == '-' || val[0] == '*' || val[0] == '/')
    {
        TreeNode * operate = new TreeNode(val);
        TreeNode * rightVal = expressionStack.top();
        expressionStack.pop();
        TreeNode * leftVal = expressionStack.top();
        expressionStack.pop();
        operate->right = rightVal;
        operate->left = leftVal;
        expressionStack.push(operate);
    }
}

// Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* tree) const {
    // print the tree in prefix format
    if(tree != NULL)
    {
        cout << tree->value << " ";
        printPrefix(tree->left);
        printPrefix(tree->right);
    }
}

// Prints data in infix form
void TreeCalc::printInfix(TreeNode* tree) const {
    // print tree in infix format with appropriate parentheses
    if(tree->left != NULL)
    {
        cout << "(";
        printInfix(tree->left);
    }
    cout << " " << tree->value << " ";
    if(tree->right != NULL)
    {
        printInfix(tree->right);
        cout << ")";
    }
}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* tree) const {
    // print the tree in postfix form
    if(tree != NULL)
    {
        printPostfix(tree->left);
        printPostfix(tree->right);
        cout << tree->value << " ";
    }
}

// Prints tree in all 3 (post, in, pre) forms
// DO NOT MODIFY
void TreeCalc::printOutput() const {
    if (expressionStack.size() != 0 && expressionStack.top() != NULL) {
        TreeNode* tree = expressionStack.top();
        cout << "Expression tree in postfix expression: ";
        printPostfix(tree);
        cout << endl;

        cout << "Expression tree in infix expression: ";
        printInfix(tree);
        cout << endl;

        cout << "Expression tree in prefix expression: ";
        printPrefix(tree);
        cout << endl;
    } else {
        cout << "Size is 0." << endl;
    }
}

// Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* tree) const {
    // Traverse the tree and calculates the result
    int outcome = 0;
    if(tree->value == "+")
    {
        int left = calculate(tree->left);
        int right = calculate(tree->right); 
        outcome = left + right;
    }
    else if(tree->value == "-")
    {
        int left = calculate(tree->left);
        int right = calculate(tree->right);
        outcome = left - right;
    }
    else if(tree->value == "*")
    {
        int left = calculate(tree->left);
        int right = calculate(tree->right);
        outcome = left * right;
    }
    else if(tree->value == "/")
    {
        int left = calculate(tree->left);
        int right = calculate(tree->right);
        outcome = left / right;
    }
    else
    {
        outcome = stoi(tree->value);
    }
    return outcome;
}

//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
    // call private calculate method here
    int result;
    result = calculate(expressionStack.top());

    return result;
}
