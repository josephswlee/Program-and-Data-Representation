/*
    Joseph Lee (Sangwoo)
    sl5nj
    6 Oct 2020
    inLab5
*/

#include "BinaryNode.h"
#include "BinarySearchTree.h"
#include <iostream>
#include <string>
using namespace std;

BinarySearchTree::BinarySearchTree() {
    root = NULL;
}

BinarySearchTree::~BinarySearchTree() {
    delete root;
    root = NULL;
}

// insert finds a position for x in the tree and places it there.
void BinarySearchTree::insert(const string& x) {
    // YOUR IMPLEMENTATION GOES HERE
    insert(root, x);
    //printTree();
}

void BinarySearchTree::insert(BinaryNode*& n, const string& x)
{
    //set the value to the string at the end
    if (n == NULL)
    {
        n = new BinaryNode();
        n->value = x;
    }
    else if (x < n->value)
    {
        insert(n->left, x);
    }
    else if (x > n->value)
    {
        insert(n->right, x);
    }
    else
        ; // duplicate... do nothing
}

// remove finds x's position in the tree and removes it.
void BinarySearchTree::remove(const string& x) {
    root = remove(root, x);
}

// private helper for remove to allow recursion over different nodes. returns
// a BinaryNode* that is assigned to the original node.
BinaryNode* BinarySearchTree::remove(BinaryNode*& n, const string& x) {
    if (n == NULL) {
        return NULL;
    }

    // first look for x
    if (x == n->value) {
        // found
        if (n->left == NULL && n->right == NULL) {
            // no children
            // just delete it :)
            delete n;
            n = NULL;
            return NULL;
        } else if (n->left == NULL) {
            // single child (right)
            // remove current node and return right child node for parent
            BinaryNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        } else if (n->right == NULL) {
            // single child (left)
            // remove current node and return left child node for parent
            BinaryNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        } else {
            // two children
            // replace current node with right child node's minimum, then remove that node
            string value = min(n->right);
            n->value = value;
            n->right = remove(n->right, value);
        }
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }
    return n;
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string BinarySearchTree::pathTo(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
    string isItWorking = "";
    //int count;
    BinaryNode * ptr = root;
    if(!find(x))
    {
        return "";
    }
    while(ptr != NULL)
    {
        if(x < ptr->value) 
        {
            isItWorking += ptr->value;
            isItWorking = isItWorking + " ";
            ptr = ptr->left;
        }
        else if(x > ptr->value)
        {
            isItWorking += ptr->value;
            isItWorking = isItWorking + " ";
            ptr = ptr->right;
        }
        else if(x == ptr->value)
        {
            isItWorking += ptr->value;
            ptr = NULL;
            //break;
        }
    }
    return isItWorking;
    //if I want to use recursion its similar to find
}

// find determines whether or not x exists in the tree.
bool BinarySearchTree::find(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
    return find(root, x);
}

bool BinarySearchTree::find(BinaryNode* n, const string& x) const
{
    if(n == NULL)
    {
        return false;
    }
    else if(x < n->value)
    {
        return find(n->left, x); //search left
    }
    else if(x > n->value)
    {
        return find(n->right, x); //search right
    }
    else
        return n; //matched
}

// numNodes returns the total number of nodes in the tree.
int BinarySearchTree::numNodes() const {
    // YOUR IMPLEMENTATION GOES HERE
    //similar to pathTo
    //or helper method 3 parameters
    // int count = pathTo()
    // helper is one parameter BinarynODE root
    // if else recurse left and right then add +1 root
    //BinaryNode * n = root;
    return numNodes(root);
}

int BinarySearchTree::numNodes(BinaryNode* root) const
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        int leftNum = numNodes(root->left);
        int rightNum = numNodes(root->right);
        return leftNum+rightNum+1;
    }
}

// min finds the string with the smallest value in a subtree.
string BinarySearchTree::min(BinaryNode* node) const {
    // go to bottom-left node
    if (node->left == NULL) {
        return node->value;
    }
    return min(node->left);
}

// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
    if (p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}

void BinarySearchTree::printTree() {
    printTree(root, NULL, false);
}

// Recursive function to print binary tree
// It uses inorder traversal
void BinarySearchTree::printTree(BinaryNode* root, Trunk* prev, bool isRight) {
    if (root == NULL) return;

    string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight) {
        trunk->str = ".---";
        prev_str = "   |";
    } else {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->value << endl;

    if (prev) prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);

    delete trunk;
}
