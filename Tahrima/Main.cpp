#include "DarkGDK.h"
#include "Cell.h"
#include "Maze.h"
#include "CellImp.h"

void draw ();
void algorithm(int, int);

void DarkGDK ( void )
{	
	dbSyncOn   ( );
	dbSyncRate ( 60 );

	dbDisableEscapeKey ( );
	dbRandomize ( dbTimer ( ) );

	const int r = 20;
	const int c = 20;
	initialize(r, c);

	draw();
	algorithm(r, c);

	while ( LoopGDK ( ) )
	{
		
		dbSetTextFont("Arial");
		dbSetTextSize(15);
		dbText(500, 0, "Hii!");
		dbSync ( );

	}

	return;
}