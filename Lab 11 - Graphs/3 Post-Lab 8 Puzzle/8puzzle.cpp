/*
    Joseph Lee (Sangwoo)
    sl5nj
    CS2150 Lab 11 - Post-Lab
    8puzzle.cpp
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

void bfs(string start, unordered_map<string, int> dist);
vector<string> genNeighbors(string state);
string swap(string s, int i, int j);

int main() {

	//unordered_map<string, vector<string> > states; 

	string state;
	for (int i = 0; i < 9; i++){
		char temp;
		cin >> temp;
		state += temp;
	}
	

	//queue<string> q;
	unordered_map<string, int> dist; //string == state, int == shortest distance

	bfs(state, dist);

	return 0;
}

/**
* @brief Takes initial state and unordered_map to solve 8 puzzle
*
* @param start Takes initial state (string)
* @param dist Takes unordered_map<string, int> string == state, int == distance
* @return void function so returns nothing
* @todo if state is "123456780" return the shortest distance
*/
void bfs(string start, unordered_map<string, int> dist) {
	queue<string> q; // queue is for states
	q.push(start); 
	dist[start] = 0; // unordered map is for distance

	while (q.size() > 0) {
		string curNode = q.front();
		q.pop();

		if(curNode == "123456780") {
			//cout << "Found!" << endl;
			cout << dist["123456780"] << endl;
			return;
		}

		//look at all neighbors
		vector<string> neighbor = genNeighbors(curNode);

		for(int i = 0; i < neighbor.size(); i++) {
			//dist.count(neighbor) == 0 
			string neigh = neighbor[i];
			if(dist.find(neigh) == dist.end()) {
				dist[neigh] = dist[curNode] + 1;
				q.push(neigh);
			}
		}
	}

	cout << "IMPOSSIBLE" << endl;
}

/**
* @brief generate neighbors of passed state
*
* @param cur Takes state from the queue (string)
* @return returns vector<string> of generated neighbors
*/
vector<string> genNeighbors(string cur) {

	vector<string> neighbors;

	//find hole in the string
	int hole = cur.find('0');

	//cout << hole % 3 << endl;
	//try to swap up
	if(hole >= 3) {
		neighbors.push_back(swap(cur, hole, hole - 3));
	}

	//try to swap down
	if(hole <= 5) {
		neighbors.push_back(swap(cur, hole, hole + 3));
	}

	//swap left
	if(hole % 3 != 0) {
		neighbors.push_back(swap(cur, hole, hole - 1));
	}

	//swap right
	if(hole % 3 != 2) {
		neighbors.push_back(swap(cur, hole, hole + 1));
	}

	return neighbors;
}

/**
* @brief returns new string with chars i and j in s swapped
*
* @param state Takes current state from the queue
* @param i Position of hole
* @param j Position the hole is moving
* @return returns the string of swapped state
*/
string swap(string state, int i, int j) {
	
	//string temp = state;
	for(int x = 0; x < state.size(); x++) {
		char t = state[i];
		state[i] = state[j];
		state[j] = t;
	}

	return state;
}