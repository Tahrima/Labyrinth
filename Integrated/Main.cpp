#include "DarkGDK.h"
#include "menusystem.h"
#include "intro.h"
void DarkGDK ( void )
{
	dbSetWindowPosition ( dbScreenWidth()/3 , dbScreenHeight()/6); 
	dbSyncOn   ( );
	dbSyncRate ( 60 );
	dbSetWindowSize (800, 600);	
	dbSetWindowTitle ( "Labyrinth V 1.0");

	dbDisableEscapeKey ( );
	dbRandomize ( dbTimer ( ) );
	dbCLS();
	//Play();
	Menu();
	//Mazemain(2);
	return;
}
