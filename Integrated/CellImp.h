#ifndef _CellImp_h_
#define _CellImp_h_

#include <iostream>
#include "Cell.h"
#include "maze.h"
#include "Convert.h"
#include <fstream>
#include <ctime>
#include <vector>
#include <stack>

using namespace std;

int* get_neighbors_with_walls(Cell **, int, int, int );

void initialize (int r, int c, Cell ** all){
	for (int k = 1; k <= r; ++k){  // sets E and W borders for maze
		all[k][1].setCell("border", 'w', 1);
		all[k][20].setCell("border",'e', 1);
	}

	for (int l = 1; l <= c; ++l){ // sets N and S borders for maze
		all[1][l].setCell("border", 'n', 1);
		all[20][l].setCell("border", 's', 1);
	}
	
	/*for (int i = 1; i <= 20; ++i){  //stores border bits in output file ; 
		for (int k = 1; k <= 20; ++k)
			all[i][k].display();
	}*/
}

void algorithm (Cell ** all){

	vector<int> numstacker (401); // vector for stack
	stack<int, vector<int> > cellstack (numstacker); // initializing stack with 401 elements
	
	int total = 400;
	srand((unsigned)time(NULL));

	int current = rand() % (400 + 1); // selects random cell to start with
	//dbDeleteSprite(current); // selects box that corresponds to cell

	ofstream cool ("current.txt", ios::app); // stores current cell

	int visited = 1; // initializes counter that stores # of cells visited

	while (visited < total){ // makes sure all cells are visited

		int row = getrow(current); // returns row from Convert.h
		int col = getcol(current); // returns column
	
		//int ck = getarr(row, col);  //testing if #s match position on grid
		//cool << current << " " << ck;
		cool << " " << row << " " << col << endl; // fileio

		int neighbors[4]; // array for storing neighbors of current cell
		neighbors[0] = current - 20; //  N
		neighbors[1] = current + 20; // S
		neighbors[2] = current + 1; // E
		neighbors[3] = current - 1; // W

		int* temp = {0}; // array with indefinite size declared to store available neighbors
		temp = get_neighbors_with_walls(all, row, col, current); //stores the neighbors with all walls up
		int adjacentCells[4] = {0}; // array with definite size to store neighbors
		int size = temp[0]; // temp[0] contains size of temp, which is stored in size

		for (int k = 0; k < size; ++k)
			adjacentCells[k] = temp[k+1]; // starting with temp[1], stores usable neighbors in definite size array

		ofstream sec ("selection.txt", ios::app); // for storing selection

		if (size > 0){

			int ns = rand() % size; // depending on # of available neighbors, choose a random number in that range
			int nrow, ncol;

			nrow = getrow(adjacentCells[ns]); // get row and col of the cell that is stored in the array location of random number gotten
			ncol = getcol(adjacentCells[ns]);
			//cool << " " << adjacentCells[ns] << endl;

			sec << nrow << " " << ncol << endl;
			//sec << ns << endl << adjacentCells[ns];

			if (neighbors[0] == adjacentCells[ns]){ // N DELETES HORIZONTAL
			all[nrow][ncol].setCell("walls", 's', 0); // sets S wall bit of new cell to 0
			all[row][col].setCell("walls", 'n', 0); // sets N wall  bit of current cell to 0
			dbDeleteSprite( (20 * (row - 1)) + col + 1000); // line deletion
			dbDeleteSprite(adjacentCells[ns]); // box deletion
			}
			else if (neighbors[1] == adjacentCells[ns]){ //S DELETES HORIZONTAL
			all[nrow][ncol].setCell("walls", 'n', 0); // sets N wall bit of new cell to 0
			all[row][col].setCell("walls", 's', 0); // sets S wall bit of current cell to 0
			dbDeleteSprite( (20 * (row)) + col + 1000); // line deletion
			dbDeleteSprite(adjacentCells[ns]); // box deletion
			}
			else if (neighbors[2] == adjacentCells[ns]){ // E DELETES VERTICAL
			all[nrow][ncol].setCell("walls", 'w', 0); // sets W wall bit of new cell to 0
			all[row][col].setCell("walls", 'e', 0); // sets E wall bit of current cell to 0
			dbDeleteSprite( (21 * (row -1)) + col + 1 + 500); // line deletion
			dbDeleteSprite(adjacentCells[ns]); // box deletion
			}
			else if (neighbors[3] == adjacentCells[ns]){ // W DELETES VERTICAL
			all[nrow][ncol].setCell("walls", 'e', 0); // sets E wall bit of new cell to 0
			all[row][col].setCell("walls", 'w', 0); // sets W wall bit of current cell to 0
			dbDeleteSprite( (21 * (row - 1)) + col + 500); // line deletion
			dbDeleteSprite(adjacentCells[ns]); // box deletion
			}
			
			cellstack.push(current); // pushes current cell to the stack
			current = adjacentCells[ns]; // makes current cell the random cell selected
			visited++; //increments visited cells 
		}
		else{ // if no neighbors are found
			current = cellstack.top(); // make current cell the cell at the top of the stack
			cellstack.pop(); // remove the cell at the top of the stack
		}
	}
}

int* get_neighbors_with_walls (Cell ** all, int rc, int cc, int cur){

	int neighbors[4];
		neighbors[0] = cur - 20; //  N
		neighbors[1] = cur + 20; // S
		neighbors[2] = cur + 1; // E
		neighbors[3] = cur - 1; // W

	//ofstream haha ("neighbors.txt", ios::app);

	int final[5] = {0}; // final # of neighbors
	char dir[4] = { 'n', 's', 'e', 'w'}; // corresponds to neighbor array
	int c = 0;
	bool n[4]; // stores if neighbor will be in final array

	for(int k = 0; k < 4; ++k){

		if (neighbors[k] > 0 && neighbors[k] < 401){ // if neighbor in range

		int row = getrow(neighbors[k]); 
		int col = getcol(neighbors[k]);

		int counter = 0;

		// retreive if all walls  up

		if ( all[row][col].getDirection("walls", 'n') == 1)
			++counter;
		if ( all[row][col].getDirection("walls", 's') == 1)
			++counter;
		if ( all[row][col].getDirection("walls", 'e') == 1)
			++counter;
		if ( all[row][col].getDirection("walls", 'w') == 1)
			++counter;

		if (counter == 4){ // if all walls up
			n[k] = true;
		}
		else
			n[k] = false;
		}
		
		if (neighbors[k] < 0 || neighbors[k] > 400) // defensive programming against out of range neighbors
			n[k] = false;
		
		if (all[rc][cc].getDirection("border", dir[k]) == 1) // defensive programming against out of range neighbors due to border
			n[k] = false;

		if (n[k] == true){
			final[c+1] = neighbors[k]; // if bool is still true by the end of loop, store in final array
			//haha << final[c+1] << " ";
			++c;
		}
	}
	//haha << endl;
	//ofstream lala ("bool.txt", ios::app);
	//lala << rc << " " << cc << ": " << n[0] << " " << n[1] << " " << n[2] << " " << n[3] << endl;
	final[0] = c; // final[0] stores number of usable neighbors
	return final;
}

#endif