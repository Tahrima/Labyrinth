#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include "DarkGDK.h"
#include "Cell.h"
#include "Maze.h"
#include "CellImp.h"
#include "Convert.h"

using namespace std;

void draw ();
void initialize(int, int, Cell);
int Choose();
void First_Depth(Cell**);
void Prim (Cell**);

void DarkGDK ( void )
{	
	dbSyncOn  ();
	dbSyncRate (60);

	dbDisableEscapeKey ( );
	dbRandomize ( dbTimer ( ) );

	int choice = Choose();

	const int r = 20;
	const int c = 20;

	draw(); // draws the maze

	Cell ** all = new Cell*[r+1]; // declares a dynamic object with 2 dimensions. 1st dimension = d1
	for (int i = 1; i <= r; ++i) 
		all[i] = new Cell[c+1]; // creates 2nd dimension (d2)

	initialize(r, c, all);
	if (choice == 1)
		First_Depth(all);
	else if (choice == 0)
		Prim(all);

	//remove("neighbors.txt");
	remove("current.txt"); // deletes file at the beginning; otherwise would append forever
	remove("selection.txt"); // ^
	remove("order.txt");
	remove("walllist.txt");
	remove("deleted.txt");
	//remove("bool.txt");
	
	 // sets up Cell maze by setting borders
	
	// IF STATEMENT FOR FIRST DEPTH OR NOT

	int yint = 5;
	int xint = 5;
		
	dbLoadImage("sprite.png", 4);
	bool flag = true;
	dbSprite(1500, xint, yint, 4);
	
	while ( LoopGDK ( ) )
	{

		dbSetTextFont("Arial");
		dbSetTextSize(15);
		static bool bClick = false; 
		if ( dbMouseClick() == 1 )
			bClick = true;
		if( dbMouseClick() != 1 && bClick )
		{
			bClick = false;
			draw();
			Cell ** all2 = new Cell*[r+1]; // declares a dynamic object with 2 dimensions. 1st dimension = d1
			for (int i = 1; i <= r; ++i) 
				all2[i] = new Cell[c+1]; // creates 2nd dimension (d2)
			initialize(r, c, all2);
			if (choice == 1)
				First_Depth(all2);
			else if (choice == 0)
				Prim(all2);
		}

		if (dbUpKey() == 1){
			dbRotateSprite(1500,0);
			dbMoveSprite(1500,2);
					
			if(dbSpriteCollision(1500,0) > 500)
			{
			dbRotateSprite(1500,180);
			dbMoveSprite(1500,2);
			dbRotateSprite(1500, 0);
			}
		}
		else if (dbDownKey()== 1){
			dbRotateSprite(1500,180);
			dbMoveSprite(1500,2);
			dbRotateSprite(1500, 0);
					
			if(dbSpriteCollision(1500,0) > 500)
			{
			dbRotateSprite(1500,0);
			dbMoveSprite(1500,2);
			dbRotateSprite(1500, 0);
			}
		}
		else if (dbRightKey()== 1){
			dbRotateSprite(1500,90);
			dbMoveSprite(1500,2);
			dbRotateSprite(1500, 0);
			
			if(dbSpriteCollision(1500,0) > 500)
			{
			dbRotateSprite(1500,270);
			dbMoveSprite(1500,2);
			dbRotateSprite(1500, 0);
			}
		}
		else if (dbLeftKey()== 1){
			dbRotateSprite(1500,270);
			dbMoveSprite(1500,2);
			dbRotateSprite(1500, 0);
		
			if(dbSpriteCollision(1500,0) > 500)
			{
			dbRotateSprite(1500,90);
			dbMoveSprite(1500,2);
			dbRotateSprite(1500, 0);
			}
		}
	
		if (dbSpriteCollision(1500, 0) > 500 && dbSpriteCollision(1500, 0) < 1500)
			flag = false;

		dbText(410, 0, "First Depth Search Algorithm");
		//write << counter;
		//dbText(440, 20, "COLLISION!!!");

		dbSync ( ); // updates screen
		//++i;
	}

	for(int i = 0; i <=r; ++i) 
		delete[] all[i];
	delete[] all;

	return;
}


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

int Choose (void){

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
