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

void initialize (int r, int c, Cell ** all){
	for (int k = 1; k <= r; ++k){  // E and W borders for maze
		all[k][1].setCell("border", 'w', 1);
		all[1][k].setCell("border",'e', 1);
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

void algorithm (Cell ** all){
	vector<int> numstacker (401);
	stack<int,vector<int> > cellstack (numstacker);
	
	int total = 400;
	srand((unsigned)time(NULL));

	int current = rand() % (400 + 1);

	dbDeleteSprite(current);

	int visited = 1;

	int row = getrow(current);
	int col = getcol(current);
	
	/*int ck = getarr(row, col);  testing if #s match position on grid
	ofstream cool ("rc.txt");
	cool << current << " " << ck;
	cool << " " << row << " " << col;*/

	int n, s, w, e;
	n = current - 20;
	s = current + 20;
	w = current - 1;
	e = current + 1;

	while (visited < total)
	{
		int onen, ones, onew, onee;
		onen = visited - 20;
		ones = visited + 20;
		onew = visited - 1;
		onee = visited + 1;
		
		/*int cool = all[0][0].getDirection("border", 'n');
		if (cool == 1)*/
		
	}
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