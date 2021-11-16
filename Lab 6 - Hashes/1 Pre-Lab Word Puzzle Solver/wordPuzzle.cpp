/*
	Joseph Lee (Sangwoo)
	sl5nj
	11 Oct 2020
	preLab 6
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
//#include <unordered_set>
#include "timer.h"
#include "hashTable.h"

using namespace std;

#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];

bool readInGrid(string filename, int& rows, int& cols);
string getWordInGrid(int startRow, int startCol, int dir, int len,
					 int numRows, int numCols);

int main (int argc, char* argv[]) {
   
   int countSize = 0;
   timer t;
	//opens dictionary
   ifstream inFile;
   inFile.open(argv[1]);

   //unordered_set <string> stringSet;

   string dict;
	hashTable * myHash = new hashTable(countSize);
   //prints out dictionary
   while(inFile >> dict)
   {
   	//stringSet.insert(x);
   	myHash->insert(dict);
   	//cout << x << endl;
   	countSize++;
   }


   //close dictionary
   inFile.close();

   //myHash->insert(dict);

   //get the grid
   int rows, cols;

   // attempt to read in the file
   bool result = readInGrid(argv[2], rows, cols);

   if (!result) {
        cout << "Error reading in file!" << endl;
        return 1;
    }

   // cout << endl;
   // for (int i = 0; i < 8; i++) {
   //     cout << i << ": " << getWordInGrid(2, 2, i, 10, rows, cols) << endl;
   // }

   //print out direction
   string dir;
   int counts = 0;
   //start the timer
   t.start();
   for(int r = 0; r < rows; r++)
   {
   	for(int c = 0; c < cols; c++)
   	{
   		for(int d = 0; d < 8; d++)
   		{
   			for(int len = 3; len < 23; len++)
   			{
   				string word = getWordInGrid(r, c, d, len, rows, cols);
   				if(len > word.length()) break;
   				//if(stringSet.find(word) != stringSet.end())
   				if(myHash->contains(word))
   				{
   					counts++;
   					if(d == 0)
   					{
   						dir = "N (" ;
   					}
   					else if(d == 1)
   					{
   						dir = "NE (" ;
   					}
   					else if(d == 2)
   					{
   						dir = "E (" ;
   					}
   					else if(d == 3)
   					{
   						dir = "SE (" ;
   					}
   					else if(d == 4)
   					{
   						dir = "S (" ;
   					}
   					else if(d == 5)
   					{
   						dir = "SW (" ;
   					}
   					else if(d == 6)
   					{
   						dir = "W (" ;
   					}
   					else if(d == 7)
   					{
   						dir = "NW (" ;
   					}

   					cout << dir << r << "," << c << "): " << word << endl;
   				}
   			}
   		}
   	}
   }
   //ends the timer
   t.stop();
   cout << counts << " words found" << endl;
   //cout << "Runtime: " << t.getTime() << "s" << endl;


   return 0;

    // // the command-line parameters are stored as C-style strings in the
    // // argv[] array. argc contains 1 more than the number of command
    // // line parmaeters specified.
    // // the 0th command line parameter is always the program name.
    // // we can print a C-style string directly through cout:
    // cout << "This program is called '" << argv[0] << "'" << endl;
    // cout << "The following are the command line parameters you specified: " << endl;
    // // this for loop starts at 1 to avoid printing the name of the program
    // for ( int i = 1; i < argc; i++ ) {
    //     // we can convert the C-style strings into C++-style strings:
    //     string s(argv[i]);
    //     // and then print them out:
    //     cout << "\t" << s << endl;
    // }
    // return 0;
}

bool readInGrid(string filename, int &rows, int &cols)
{
	   // try to open the file
    ifstream file(filename);
    // upon an error, return false
    if (!file.is_open()) {
        return false;
    }

    // first comes the number of rows
    file >> rows;
    //cout << "There are " << rows << " rows." << endl;

    // then the columns
    file >> cols;
    //cout << "There are " << cols << " cols." << endl;

    // and finally the grid itself
    string data;
    file >> data;

    // close the file
    file.close();

    // convert the string read in to the 2-D grid format into the
    // grid[][] array.
    // In the process, we'll print the grid to the screen as well.
    int pos = 0; // the current position in the input data
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            grid[r][c] = data[pos++];
            //cout << grid[r][c];
        }
        //cout << endl;
    }
    return true;
}

string getWordInGrid (int startRow, int startCol, int dir, int len,
                      int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocation.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static string output;
    output.clear(); // Since it's static we need to clear it
    output.reserve(256); // Can't set capacity in the constructor so do it the first time here

    // the position in the output array, the current row, and the
    // current column
    int r = startRow, c = startCol;
    // iterate once for each character in the output
    for (int i = 0; i < len; i++) {
        // if the current row or column is out of bounds, then break
        if (c >= numCols || r >= numRows || r < 0 || c < 0) {
            break;
        }

        // set the next character in the output array to the next letter
        // in the grid
        output += grid[r][c];

        // move in the direction specified by the parameter
        switch (dir) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }

    return output;
}
