/*
    Joseph Lee (Sangwoo)
    sl5nj
    9 Oct 2020
    postLab5
*/

#include "AVLNode.h"
#include "AVLTree.h"
#include <iostream>
#include <string>
using namespace std;

AVLTree::AVLTree() {
    root = NULL;
}

AVLTree::~AVLTree() {
    delete root;
    root = NULL;
}

// insert finds a position for x in the tree and places it there, rebalancing
// as necessary.
void AVLTree::insert(const string& x) {
    // YOUR IMPLEMENTATION GOES HERE
    insert(root, x);
}

void AVLTree::insert(AVLNode*& n, const string& x)
{
    //set the value to the string at the end
    if (n == NULL)
    {
        n = new AVLNode();
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

    n->height = 1 + max(height(n->left), height(n->right));
    balance(n);
}

// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) {
    root = remove(root, x);
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string AVLTree::pathTo(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
    if(!find(x))
    {
        return "";
    }
    return pathTo(root, x); //check
}

string AVLTree::pathTo(AVLNode* n, const string& x) const
{
    if(n == NULL)
    {
        return "";
    }
    else if(x < n->value)
    {
        return n->value + " " + pathTo(n->left, x); //search left
    }
    else if(x > n->value)
    {
        return n->value + " " + pathTo(n->right, x); //search right
    }
    else
        return x; // or n->value; //matched
}


// find determines whether or not x exists in the tree.
bool AVLTree::find(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
    return find(root, x);
}

bool AVLTree::find(AVLNode* n, const string& x) const
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
        return true; //matched
}

// numNodes returns the total number of nodes in the tree.
int AVLTree::numNodes() const {
    // YOUR IMPLEMENTATION GOES HERE
    return numNodes(root);
}

int AVLTree::numNodes(AVLNode* root) const
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

// balance mxakes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.
void AVLTree::balance(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE

    //Note that balance factor here is assumed to be (height of right subtree - height of left subtree)
    int factor = height(n->right) - height(n->left);
    //check if need to rotate left
    if(factor == 2)
    {
       // cout << "balance left called" << endl;
        //check if it also need to rotate right
        //if balance factor of right child is negative
        if(height(n->right->right) - height(n->right->left) < 0)
        {
           rotateRight(n->right);
        }
        //rotate left on node
       rotateLeft(n);
    }
    //check if need to rotate right
    else if(factor == -2)
    {
       // cout << "balance right called" << endl;
        //check if it also need to rotate left
        //if balance factor of left child is positive
        if(height(n->left->right) - height(n->left->left) > 0)
        {
           // cout << "balance right left called" << endl;
           rotateLeft(n->left);
        }
        //rotate right on node
       rotateRight(n);
    }
}

// rotateLeft performs a single rotation on node n with its right child.
AVLNode* AVLTree::rotateLeft(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
  
    AVLNode* x = n->right->left;
    n->right->left = n;
    n = n->right;
    n->left->right = x;

    n->height++;
    n->left->height--;
    
    return n;
}

// rotateRight performs a single rotation on node n with its left child.
AVLNode* AVLTree::rotateRight(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
   
    AVLNode* x = n->left->right;
    n->left->right = n;
    n = n->left;
    n->right->left = x;
   
    n->height++;
    n->right->height--;
    //n->height = 1 + max(height(n->left), height(n->right));
    return n;
}

// private helper for remove to allow recursion over different nodes.
// Returns an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
    if (n == NULL) {
        return NULL;
    }

    // first look for x
    if (x == n->value) {
        // found
        if (n->left == NULL && n->right == NULL) {
            // no children
            delete n;
            n = NULL;
            return NULL;
        } else if (n->left == NULL) {
            // Single child (left)
            AVLNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        } else if (n->right == NULL) {
            // Single child (right)
            AVLNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        } else {
            // two children -- tree may become unbalanced after deleting n
            string sr = min(n->right);
            n->value = sr;
            n->right = remove(n->right, sr);
        }
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }

    // Recalculate heights and balance this subtree
    n->height = 1 + max(height(n->left), height(n->right));
    balance(n);

    return n;
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
    // go to bottom-left node
    if (node->left == NULL) {
        return node->value;
    }
    return min(node->left);
}

// height returns the value of the height field in a node.
// If the node is null, it returns -1.
int AVLTree::height(AVLNode* node) const {
    if (node == NULL) {
        return -1;
    }
    return node->height;
}

// max returns the greater of two integers.
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
    if (p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void AVLTree::printTree(AVLNode* root, Trunk* prev, bool isRight) {
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

void AVLTree::printTree() {
    printTree(root, NULL, false);
}
