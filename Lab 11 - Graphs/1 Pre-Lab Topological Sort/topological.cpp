/*
    Joseph Lee (Sangwoo)
    sl5nj
    CS2150 Lab 11 - Pre-Lab
    topological.cpp
*/

// This program shows how C++-based file I/O works.
// It will open a file, read in the first two strings, and print them to the screen.

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <unordered_map>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <algorithm>
#include <queue>

using namespace std;

/**
* @brief graph class which defines private and public members
*
* @author Joseph Lee
* @date 11/16/20
*
*/

class graph {

private:
	int vertice; //number of vertices
	list<int>* adj; //pointer to an array containing adjacency listsList
	//A function used by topologicalSort (helper method)
	void topSortHelper(int vertice, bool visited[], stack<int>& stack);

public:
	graph(int v); //constructor
	~graph(); //destructor
	void addEdge(string v, string w); //function to add an edge to graph
	void topSort(); //pritns a Topological sort of the complete graph

	unordered_map<int, string> map;
};

/**
* @brief constructor of graph class
*
* @param v is the number of vertices
* initialize list of int that has size of vertices
*/

graph::graph(int v) {
	vertice = v; // set vertices to v
	adj = new list<int>[v]; // initialize adj list with size of v
}

/**
* @brief destructor of graph class
*
* deletes the adjacency list
*/

graph::~graph() {
	delete [] adj;
}

/**
* @brief main function which takes in one command line parameter
* @return main returns 0 when ran sucessfully
* @param argc is the number of arguments
* @param argv is the values of the arguments
*/

// we want to use parameters
int main(int argc, char** argv) {
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    list<string> edge;
    priority_queue<string, vector<string>, greater<string> > pq;
    // read in two strings
    string s1, s2;
    while (true){

   		file >> s1;
    	file >> s2;
    	//cout << s1 << endl;
    	//cout << s2 << endl;

   		 if(s1 == "0") {
    		break;
   		 }
   		 edge.push_back(s1);
   		 edge.push_back(s2);
	}

	edge.sort();
	edge.unique();

	//cout << edge.back() << endl;

	while(!edge.empty()){
		string temp = edge.back();
		edge.pop_back();
		pq.push(temp);
	}

	while (!pq.empty()){
		cout << pq.top() << "\t";
		pq.pop();
	}

	cout << endl;
	
	//edge.sort();
	//edge.unique();


    // close the file before exiting
    file.close();

    return 0;
}