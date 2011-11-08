#include "DarkGDK.h"
#include "Cell.h"
#include "Maze.h"
#include "CellImp.h"

void draw ();
void initialize(int, int);

void DarkGDK ( void )
{	
	dbSyncOn   ( );
	dbSyncRate ( 60 );

	dbDisableEscapeKey ( );
	dbRandomize ( dbTimer ( ) );

	const int r = 20;
	const int c = 20;

	draw();

	Cell ** all = new Cell*[r+1]; // declares a dynamic object with 2 dimensions. 1st dimension = d1
	for (int i = 1; i <= r; ++i) 
		all[i] = new Cell[c+1]; // creates 2nd dimension (d2)

	/*for(int i = 0; i <=r; ++i) What is the purpose of this? I don't really know.
		delete[] all[i];
	delete[] all;*/
	
	initialize(r, c, all);
	algorithm(all);

	while ( LoopGDK ( ) )
	{
		dbSetTextFont("Arial");
		dbSetTextSize(15);
		dbText(500, 0, "Hii!");
		dbSync ( );
		//++i;
	}

	return;
}