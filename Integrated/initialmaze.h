#include <iostream>
#include <fstream>
#include "DarkGDK.h"
#include "Prim.h"
#include "FirstDepth.h"
#include "CellImp.h"
#include "Maze.h"
#include "Selector.h"
#include <ctime>


using namespace std;

void Mazesetup(int choose)
{	

	dbSyncOn  ();
	dbSyncRate (60);
	dbSetWindowSize (800, 600);
	dbSetImageColorKey ( 255, 2, 255 );

	dbDisableEscapeKey ( );
	dbRandomize ( dbTimer ( ) );
	int choice = 1;
	srand((unsigned)time(0));
	if (choose == 1)
	{
		if (((rand() % 2) + 1) == 1)
		{	
			choice = 1;
			First_Depth(r,c, maze, pmaze, xint, yint, choice);
		}
		else
		{
			choice = 0;
			Prim(r,c, pmaze, maze, xint, yint, choice);
		}
	}
	else
		choice = 1;
	

	const int r = 20;
	const int c = 20;

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
		if (choice == 1)
			First_Depth(r,c, maze, pmaze, xint, yint, choice);
		else if (choice == 0)
			Prim(r,c, pmaze, maze, xint, yint, choice);
		return;
		
		//write << counter;
		//dbText(440, 20, "COLLISION!!!");

		dbSync ( ); // updates screen
		//++i;
	}

	return;
}