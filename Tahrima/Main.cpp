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

	bool flag = true;
	char key = 'x';

	while ( LoopGDK ( ) )
	{

		dbSetTextFont("Arial");
		dbSetTextSize(15);
		/* REDRAWS MAZE
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
		}*/

		dbSprite(1500, xint, yint, 4);

		// NEED TO ACCOUNT FOR OUT OF RANGE COORDINATES 
		// NEED TO FIND OUT WHY IT GOES OTHER PLACES SOMETIMES DURING COLLISION

		while (flag == false){
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


		}

		if (dbUpKey() && flag == true){
			yint -= 1;
			key = 'n';
		}
		else if (dbDownKey() && flag == true){
			yint += 1;
			key = 's';
		}
		else if (dbRightKey() && flag == true){
			xint += 1;
			key = 'e';
		}
		else if (dbLeftKey() && flag == true){
			xint -= 1;
			key = 'w';
		}

		if (dbSpriteCollision(1500, 0) > 500 && dbSpriteCollision(1500, 0) < 1500)
			flag = false;

		dbText(410, 0, "First Depth Search Algorithm");

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

	Cell ** maze = new Cell *[r+1];

	for (int i = 1; i <= r; ++i)
		maze[i] = new Cell[c+1]; 

	for (int k = 1; k <= r; ++k){  // sets E and W borders for maze
		maze[k][1].setCell("border", 'w', 1);
		maze[k][20].setCell("border",'e', 1);

		}
	for (int l = 1; l <= c; ++l){ // sets N and S borders for maze
		maze[1][l].setCell("border", 'n', 1);
		maze[20][l].setCell("border", 's', 1);
		}

	srand(time(NULL));	
	int Current = rand()%400 + 1;
	
	int row = getrow(Current); // returns row from Convert.h
	int col = getcol(Current); // returns column

	remove("order.txt");
	remove("walllist.txt");
	ofstream store("order.txt", ios::app);
	store << Current << " " << row << " " << col << endl;

	vector<string> list;
	pushbacker(maze[row][col], Current, list);
	walldestiny(list, Current, maze);

	while ( LoopGDK ( ) )
	{
		dbSync ( );
	}

}*/