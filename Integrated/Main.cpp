#include <iostream>
#include <fstream>
#include "DarkGDK.h"
#include "Cell.h"
#include "Maze.h"
#include "CellImp.h"
#include "Convert.h"

using namespace std;

void draw ();
void initialize(int, int, Cell);

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
	
	//remove("neighbors.txt");
	remove("current.txt"); // deletes file at the beginning; otherwise would append forever
	remove("selection.txt"); // ^
	//remove("bool.txt");
	
	initialize(r, c, all); // sets up Cell maze by setting borders
	algorithm(all); // the entire algorithm

	ofstream write ("col.txt", ios::app);

	int yint = 5;
	int xint = 5;
		
	dbLoadImage("sprite.png", 4);
	dbLoadImage("bigsquare.png", 5);

	bool flag = true;
	char key = '0';
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
			algorithm(all2);
		}



		// NEED TO ACCOUNT FOR OUT OF RANGE COORDINATES 
		// NEED TO FIND OUT WHY IT GOES OTHER PLACES SOMETIMES DURING COLLISION

		/*while (flag == false){
			if (key == 'n'){
			while (dbSpriteCollision(1500, 0) > 500 && dbSpriteCollision(1500, 0) < 1500){
				yint += 2;
				dbText(410, 20, "COLLISION!!!");
				dbSprite(1500, xint, yint, 4);
			}
			flag = true;
			}
			else if (key == 's'){
			while (dbSpriteCollision(1500, 0) > 500 && dbSpriteCollision(1500, 0) < 1500){
				yint -= 2;
				dbText(410, 20, "COLLISION!!!");
				dbSprite(1500, xint, yint, 4);
			}
			flag = true;
			}
			else if (key == 'e'){
			while (dbSpriteCollision(1500, 0) > 500 && dbSpriteCollision(1500, 0) < 1500){
				xint -= 2;
				dbText(410, 20, "COLLISION!!!");
				dbSprite(1500, xint, yint, 4);
			}
			flag = true;
			}
			else if (key == 'w'){
			while (dbSpriteCollision(1500, 0) > 500 && dbSpriteCollision(1500, 0) < 1500){
				xint += 2;
				dbText(410, 20, "COLLISION!!!");
				dbSprite(1500, xint, yint, 4);
			}
			flag = true;
			}


		}*/



		//dbSprite(1499, 5, 5, 5);
/*
		if (flag == false){
			while (dbSpriteCollision(1500, 0) > 500 && dbSpriteCollision(1500, 0) < 1500){
				if (dbSpriteCollision(1500, 0) > 500 && dbSpriteCollision(1500,0) < 1001 && key == 'e'){
					//xint = 5; 
					//yint = 5;
					xint -= 2;
					dbText(410, 20, "Collision!!!");
					dbSprite(1500, xint, yint, 4);
				}
				else if (dbSpriteCollision(1500, 0) > 500 && dbSpriteCollision(1500,0) < 1001 && key == 'w'){
					xint += 2;
					//xint = 5; 
					//yint = 5;
					dbText(410, 20, "Collision!!!");
					dbSprite(1500, xint, yint, 4);
				}
				else if (dbSpriteCollision(1500, 0) > 1000 && dbSpriteCollision(1500,0) < 1500 && key == 'n'){
					yint += 2;
					//xint = 5; 
					//yint = 5;
					dbText(410, 20, "Collision!!!");
					dbSprite(1500, xint, yint, 4);
				}
				else if (dbSpriteCollision(1500, 0) > 1000 && dbSpriteCollision(1500,0) < 1500 && key == 's'){
					yint -= 2;
					//xint = 5; 
					//yint = 5;
					dbText(410, 20, "Collision!!!");
					dbSprite(1500, xint, yint, 4);
				}
			}
			flag = true;
		}
*/
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
		//if(dbSpriteCollision(1500,0) < 500)
			//break;
		/*if (dbSpriteCollision(1500, 0) > 500 && dbSpriteCollision(1500, 0) < 1500)
			flag = false;
*/
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


/*#include <iostream>
#include <ctime>
#include <vector>
#include "Cell.h"
#include "DarkGDK.h"
#include "Convert.h"
#include "CellImp.h"
#include <fstream>

using namespace std;

void DarkGDK ( void ){

	dbSyncOn   ( );
	dbSyncRate ( 60 );

	dbDisableEscapeKey ( );
	dbRandomize ( dbTimer ( ) );
	
	const int r = 20;
	const int c = 20;

	draw();

	Cell ** maze = new Cell *[r+1];

	for (int i = 1; i <= r; ++i)
		maze[i] = new Cell[c+1]; 

	initialize(r, c, maze); 

	srand((unsigned)time(0));	
	int Current = (rand()% 400) + 1;
	
	int row = getrow(Current); // returns row from Convert.h
	int col = getcol(Current); // returns column

	//maze[row][col].setVisited(1); // marked as part of the  maze

	remove("order.txt");
	remove("walllist.txt");
	remove("deleted.txt");

	ofstream store("order.txt", ios::app);
	store << row << " " << col << endl;

	int count = 1;
	vector<string> list;
	pushbacker(maze[row][col], Current, list, count);
	walldestiny(list, maze);

	while ( LoopGDK ( ) )
	{
		dbSync ( );
	}

}*/