#include <Vfw.h>
#include <globstruct.h>
#pragma comment ( lib , "Vfw32.lib" )
//Thanks to Hassan on the Dark Gdk Forums for help with the video playing code.
//Begins Here:
HWND MCIWnd;UINT length = 0;
void PlayVideo ( HWND hwnd_ParentWindow, LPSTR lpstr, int OriginX, int OriginY, int Width, int Height, UINT* length ) 
{	
	MCIWnd = MCIWndCreate ( hwnd_ParentWindow, GetModuleHandle(NULL),
		WS_CHILD | WS_VISIBLE | MCIWNDF_NOTIFYMODE | MCIWNDF_NOPLAYBAR, NULL );

	MCIWndOpen ( MCIWnd, lpstr, NULL ); // new device in window

	SetWindowPos ( MCIWnd, HWND_TOPMOST, OriginX, OriginY, Width, Height, SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE );

    MCIWndPlay ( MCIWnd ); // plays device

	if ( length )
			*length = MCIWndGetLength ( MCIWnd );
}
//Ends here.


void Play(void)
{
	//Settings:
	//dbSyncOn   ( );
	//dbSyncRate ( 60 );
	//dbSetWindowSize ( 800 , 600 );
	//dbSetImageColorKey ( 100,100,100 );
	
	dbLoadImage("Media/Default.bmp",1); //Black screen that acts as a cover for the lightbulb,
	dbSprite(1,10,0,1);           //I haven't found a good way to fade into this yet
	dbLoadMusic ( "Media/stonesteps.mp3", 1 ); //But I like how it turned out
	dbLoadMusic ("Media/bmusic.mp3", 2); //Errie backround music
	dbLoopMusic ( 2 ); 
	dbPlayMusic ( 1 );
	dbPlayMusic ( 2 );
	
	dbWait(8000);	//Wait for the walking to stop
	dbDeleteSprite ( 1 );

	dbLoadSound("Media/lightsound.wav",2); //Load and play the chain being pulled
	dbPlaySound ( 2 );

	//Main loop varibles
	bool play = true;
	int count = 0;

	while ( LoopGDK ( ) )
	{
	if (play == true)
		PlayVideo ( g_pGlob->hWnd, "Media/intromovie.AVI", 0, 0, 800, 600, &length );
	else if (count == 10) //if the screen runs for a minute
	{
		return; //exit
	}
	else
	{
		return; //exit
	}
	
	for (int i = 0; i < 3950; i++) 
	{
		dbWait(1); //1ms delay + delay of running the loop.
		if (dbMouseClick()) //If the user clicks the mouse
		{
			play = false; //Get ready to exit;
			break;
		}
	}
	count++;
	
	DestroyWindow ( MCIWnd ); //Remove video for looping playback
	}
	DestroyWindow ( MCIWnd ); //JIC
	RFade();
	dbSync();
	return;
}