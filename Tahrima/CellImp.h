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

void initialize(int r, int c){

	Cell ** all = new Cell*[r+1]; // declares a dynamic object with 2 dimensions. 1st dimension = d1
	cout << r;
	for (int i = 1; i <= r; ++i) 
		all[i] = new Cell[c+1]; // creates 2nd dimension (d2)
	for (int k = 1; k <= r; ++k){  // E and W borders for maze
		all[k][1].setCell("border", 'w', 1);
		all[k][r].setCell("border",'e', 1);
	}

	for (int l = 1; l <= c; ++l){ // N and S borders for maze
		all[1][l].setCell("border", 'n', 1);
		all[c][l].setCell("border", 's', 1);
	}

	/*for (int i = 1; i <= 20; ++i){  //stores border bits in output file
		for (int k = 1; k <= 20; ++k)
			all[k][i].display();
	}*/
}

void algorithm(int r, int c){
	
	vector<int> numstacker (401);
	stack<int,vector<int> > cellstack (numstacker);
	
	int total = 400;
	srand((unsigned)time(NULL)); 
	int current = rand() % (400 + 1);
	dbDeleteSprite(current);
	int visited = 1;

	int row = getrow(current);
	int col = getcol(current);
	
	/*Algorithm
	   
	-create a CellStack (LIFO) to hold a list of cell locations  
	-set TotalCells = number of cells in grid  
	-choose a cell at random and call it CurrentCell  
	-set VisitedCells = 1  
	   
	while VisitedCells < TotalCells 
	find all neighbors of CurrentCell with all walls intact   
	if one or more found 
	choose one at random  
	knock down the wall between it and CurrentCell  
	push CurrentCell location on the CellStack  
	make the new cell CurrentCell  
	add 1 to VisitedCells
	else 
	pop the most recent cell entry off the CellStack  
	make it CurrentCell
	endIf
	endWhile  */

}

#endif