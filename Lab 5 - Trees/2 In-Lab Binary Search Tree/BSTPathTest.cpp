/*
    Joseph Lee (Sangwoo)
    sl5nj
    6 Oct 2020
    inLab5
*/

#include "BinarySearchTree.h"

#include <iostream>
using namespace std;

int main() {
    BinarySearchTree bst;
    while (cin.good()) {
        string instr, word;
        cin >> instr;
        cin >> word;
        if (instr == "I") {
            bst.insert(word);
        } else if (instr == "R") {
            bst.remove(word);
        } else if (instr == "L") {
            cout << "BST path: " << bst.pathTo(word) << endl;
        }
    }
    cout << "BST numNodes: " << bst.numNodes() << endl;
}