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

bool all_walls_up(int, Cell ** );

void initialize (int r, int c, Cell ** all){
	for (int k = 1; k <= r; ++k){  // E and W borders for maze
		all[k][1].setCell("border", 'w', 1);
		all[k][20].setCell("border",'e', 1);
	}

	for (int l = 1; l <= c; ++l){ // N and S borders for maze
		all[1][l].setCell("border", 'n', 1);
		all[20][l].setCell("border", 's', 1);
	}
	
	/*for (int i = 1; i <= 20; ++i){  //stores border bits in output file
		for (int k = 1; k <= 20; ++k)
			all[i][k].display();
	}*/
}

void algorithm (Cell ** all){

	vector<int> numstacker (401);
	stack<int, vector<int> > cellstack (numstacker);

	//cellstack
	
	int total = 400;
	srand((unsigned)time(NULL));

	int current = rand() % (400 + 1);

	dbDeleteSprite(current);

	int visited = 1;

	while (visited < total){

		int row = getrow(current);
		int col = getcol(current);
		
	
		/*int ck = getarr(row, col);  testing if #s match position on grid
		ofstream cool ("rc.txt");
		cool << current << " " << ck;
		cool << " " << row << " " << col;*/

		int neighborN, neighborS, neighborW, neighborE;
		neighborN = current - 20;
		neighborS = current + 20;
		neighborW = current - 1;
		neighborE = current + 1;

		bool nN, nS, nW, nE;
		nN = all_walls_up(neighborN, all);
		nS = all_walls_up(neighborS, all);
		nE = all_walls_up(neighborE, all);
		nW = all_walls_up(neighborW, all);


		if (nN || nS || nW || nE){

			int j = 0;
			int neighborSelect[4] = {0};

			if (nN){
				neighborSelect[j] = neighborN;
				++j;
			}
			if (nS){
				neighborSelect[j] = neighborS;
				++j;
			}
			if (nE){
				neighborSelect[j] = neighborE;
				++j;
			}
			if (nW){
				neighborSelect[j] = neighborW;
				++j;
			}

			int ns = rand() % j;
			int nrow, ncol;

			cellstack.push(current);

			if (neighborSelect[ns] == neighborN){
				/*dbDeleteSprite(neighborN);
				nrow = getrow(neighborN);
				ncol = getcol(neighborN);
				all[nrow][ncol].setCell("walls", 's', 0);
				current = neighborN;*/
				;
			}
			else if (neighborSelect[ns] == neighborS){
				/*dbDeleteSprite(neighborS);
				nrow = getrow(neighborS);
				ncol = getcol(neighborS);
				all[nrow][ncol].setCell("walls", 'n', 0);
				current = neighborS;*/
				;
			}
			else if (neighborSelect[ns] == neighborE){
				/*dbDeleteSprite(neighborE);
				nrow = getrow(neighborE);
				ncol = getcol(neighborE);
				all[nrow][ncol].setCell("walls", 'w', 0);
				current = neighborE;*/
				;
			}
			else if (neighborSelect[ns] == neighborW){
				/*dbDeleteSprite(neighborW);
				nrow = getrow(neighborW);
				ncol = getcol(neighborW);
				all[nrow][ncol].setCell("walls", 'e', 0);
				current = neighborW;*/
				;
			}
			visited++;
		}

		else{
			current = cellstack.top();
			cellstack.pop();
		}
	}

	//j = 0; // redundant?

	//while (visited < total)

	/*Algorithm
	   
	-create a CellStack (LIFO) to hold a list of cell locations  
	-set TotalCells = number of cells in grid  
	-choose a cell at random and call it CurrentCell  
	-set VisitedCells = 1  
	   
	while VisitedCells < TotalCells 
	-find all neighbors of CurrentCell with all walls intact   
	if one or more found 
	-choose one at random  
	-knock down the wall between it and CurrentCell  
	push CurrentCell location on the CellStack  
	make the new cell CurrentCell  
	add 1 to VisitedCells
	else 
	pop the most recent cell entry off the CellStack  
	make it CurrentCell
	endIf
	endWhile  */

}

bool all_walls_up (int cell, Cell ** all){
	int row = getrow(cell);
	int col = getcol(cell);

	int counter = 0;

	if ( all[row][col].getDirection("walls", 'n') == 1)
		++counter;
	if ( all[row][col].getDirection("walls", 's') == 1)
		++counter;
	if ( all[row][col].getDirection("walls", 'e') == 1)
		++counter;
	if ( all[row][col].getDirection("walls", 'w') == 1)
		++counter;

	if (counter == 4)
		return true;
	else
		return false;
}

#endif