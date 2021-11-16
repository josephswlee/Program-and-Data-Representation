/*
    Joseph Lee (Sangwoo)
    sl5nj
    CS2150 Lab 11 - In-Lab
    traveling.cpp
*/

#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

#include "middleearth.h"

float computeDistance(MiddleEarth &me, const string& start, vector<string> dests);
void printRoute(const string& start, const vector<string>& dests);
void printRoute2(const string& start, const vector<string>& dests);

/**
* @brief main function calculating traveling salesperson problem
* @param argc Counts the command line arguments
* @param argv Takes vector of command line arguments
* @return when ran successfully it returns 0
* @todo Pass the write comman line arguments to run the program
*/
int main(int argc, char** argv) {
    // check the number of parameters
    if (argc != 6) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }

    // we'll assume the parameters are all well-formed
    int width = stoi(argv[1]);
    int height = stoi(argv[2]);
    int num_cities = stoi(argv[3]);
    int rand_seed = stoi(argv[4]);
    int cities_to_visit = stoi(argv[5]);

    // create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);

    // TODO: YOUR CODE HERE

    vector<string> newDes = dests;
    float shortDist = computeDistance(me, dests[0], dests);
    
    //sort before using next_permutation
    sort(dests.begin()+1, dests.end());
    float newDist = 0;

    while (next_permutation(dests.begin()+1, dests.end())){
    	newDist = computeDistance(me, dests[0], dests);
    	if (newDist < shortDist) {
    		shortDist = newDist;
    		newDes = dests;  
    	}
    }

    cout << "Minimum path has distance: " ;
    cout << shortDist ;
    printRoute(newDes[0], newDes);
  
    return 0;
}

/**
* @brief This method will compute the full distance of the cycle that starts
* at the 'start' parameter, goes to each of the cities in the dests
* vector IN ORDER, and ends back at the 'start' parameter.
* @param me The instance of middleEarth 
* @param start The starting city's name (string)
* @param dests The vector of cities to visit (vector<string>)
* @return The method returns the calculated distance (float) 
*/
float computeDistance(MiddleEarth &me, const string& start, vector<string> dests) {
    // TODO: YOUR CODE HERE
    float dist = 0;
    for (int i = 1; i < dests.size(); i++) {
    	dist = dist + me.getDistance(dests[i-1], dests[i]);
    }
    dist = dist + me.getDistance(dests.at(0), dests.back());
    return dist;
}

/**
* @brief This method will print the entire route, starting and ending at the
* 'start' parameter.
* The output should be similar to:
* Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
* @param start The starting city's name (string)
* @param dests The vector of cities to visit (vector<string>)
* @return The method is void so returns nothing
*/
void printRoute(const string& start, const vector<string>& dests) {
    // TODO: YOUR CODE HERE
    for (auto itr = dests.begin(); itr != dests.end(); itr++) {
    	cout << *itr << " -> ";
    }
    cout << start << endl;
}