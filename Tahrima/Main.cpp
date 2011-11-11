#include <iostream>
#include <fstream>
#include "DarkGDK.h"
#include "Cell.h"
#include "Maze.h"
#include "CellImp.h"
#include "Convert.h"

using namespace std;

void draw ();
void initialize(int, int);
int getrow(int);
int getcol(int);

void DarkGDK ( void )
{	
	dbSyncOn   ( );
	dbSyncRate ( 60 );

	dbDisableEscapeKey ( );
	dbRandomize ( dbTimer ( ) );

	const int r = 20;
	const int c = 20;

	draw(); // draws the maze

	Cell ** all = new Cell*[r+1]; // declares a dynamic object with 2 dimensions. 1st dimension = d1
	for (int i = 1; i <= r; ++i) 
		all[i] = new Cell[c+1]; // creates 2nd dimension (d2)

	/*for(int i = 0; i <=r; ++i) What is the purpose of this? I don't really know.
		delete[] all[i];
	delete[] all;*/
	
	//remove("neighbors.txt");
	remove("current.txt"); // deletes file at the beginning; otherwise would append forever
	remove("selection.txt"); // ^
	//remove("bool.txt");
	
	initialize(r, c, all); // sets up Cell maze by setting borders
	algorithm(all); // the entire algorithm

	while ( LoopGDK ( ) )
	{
		dbSetTextFont("Arial");
		dbSetTextSize(15);
		dbText(500, 0, "I work!! Yay!");
		dbSync ( );
		//++i;
	}

	return;
}