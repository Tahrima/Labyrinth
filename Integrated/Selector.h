#ifndef _Selector_h_
#define _Selector_h_

#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include "Convert.h"
#include "CellImp.h"
#include "Cell.h"
#include "DarkGDK.h"

using namespace std;

void First_Depth (Cell** maze){
	algorithm(maze);
}

void Prim (Cell** maze){
	srand((unsigned)time(0));	
	int Current = (rand()% 400) + 1;
	
	int row = getrow(Current); // returns row from Convert.h
	int col = getcol(Current); // returns column

	//maze[row][col].setVisited(1); // marked as part of the  maze

	ofstream store("order.txt", ios::app);
	store << row << " " << col << endl;

	int count = 1;
	vector<string> list;
	pushbacker(maze[row][col], Current, list, count);
	walldestiny(list, maze);
}

int Choose_Maze (void){

	int flag = -1;
	while ( LoopGDK ()){

		if (dbUpKey() == 1){
			flag = 1;
			return flag;
		}
		else if (dbDownKey() == 1){
			flag = 0;
			return flag;
		}
		dbSync();	
	}
}




#endif