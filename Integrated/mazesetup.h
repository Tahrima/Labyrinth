#ifndef _mazesetup_h_
#define _mazesetup_h_


#include <iostream>
#include <fstream>
#include "DarkGDK.h"
#include "Prim.h"
#include "FirstDepth.h"
#include "CellImp.h"
#include "Maze.h"
#include "Selector.h"
#include <ctime>
#include "fileiop.h"


using namespace std;

void Mazemain(int choose)
{	
	writename("test");
	srand((unsigned)time(0));	

	int choice = 1;
	//int choose = 2;

	const int r = 20;
	const int c = 20;
	bool once = false;

	Cell ** maze = new Cell*[r+1]; // declares a dynamic object with 2 dimensions. 1st dimension = d1
	for (int i = 1; i <= r; ++i) 
		maze[i] = new Cell[c+1]; // creates 2nd dimension (d2)

	PrimCell ** pmaze = new PrimCell*[r+1]; // declares a dynamic object with 2 dimensions. 1st dimension = d1
	for (int i = 1; i <= r; ++i) 
		pmaze[i] = new PrimCell[c+1]; // creates 2nd dimension (d2)
	
	draw(); // draws the maze

	//if (choice == 1)
	//	First_Depth(r,c, maze); //old code
	//else if (choice == 0)
	//	Prim(r,c, pmaze);

	//remove("neighbors.txt");
	remove("current.txt"); // deletes file at the beginning; otherwise would append forever
	remove("selection.txt"); // ^
	remove("order.txt");
	remove("walllist.txt");
	remove("deleted.txt");
	//remove("bool.txt");
	
	 // sets up Cell maze by setting borders
	
	// IF STATEMENT FOR FIRST DEPTH OR NOT

	int yint = 63;
	int xint = 125;
		
	while ( LoopGDK ( ) )
	{
		//dbText(410, 100, "First Depth Search Algorithm");
		if(choose == 1)
		{
			once = true;
			if(((rand()% 2) + 1) == 1)
			{
				//First_Depth(r,c, maze, pmaze, xint, yint, choice, once);
				First_Depth(r,c, maze);
				Detect_Key(maze, pmaze, xint, yint, r, c, choice, once);
		
			}
			else
			{
				//Prim(r,c, pmaze, maze, xint, yint, choice, once);
				Prim(r,c, pmaze);
				Detect_Key(maze, pmaze, xint, yint, r, c, choice,once);
				
			}
		}
		else
		{
		once = false;
		if(choose == 2)
		{
			choice = 1;
			//First_Depth(r,c, maze, pmaze, xint, yint, choice, once);
			//Detect_Key (Cell ** maze, PrimCell ** pmaze, int xint, int yint, int r, int c, int choice, bool once
			First_Depth(r,c, maze);
			Detect_Key(maze, pmaze, xint, yint, r, c, choice, once);
		}
		else if (choose == 3)
		{
			choice = 0;
			//Prim(r,c, pmaze, maze, xint, yint, choice, once);
			//Detect_Key (Cell ** maze, PrimCell ** pmaze, int xint, int yint, int r, int c, int choice, bool once);
			Prim(r,c, pmaze);
			Detect_Key(maze, pmaze, xint, yint, r, c, choice,once);
		}
		}
		return;
		
		//write << counter;
		//dbText(440, 20, "COLLISION!!!");

		dbSync ( ); // updates screen
		//++i;
	}

	return;
}
#endif