#ifndef _menusystem_h_
#define _menusystem_h_

#include "DarkGDK.h"
#include "functionslab.h"
#include "infinatemode.h"
#include "practice.h"
#include "intialize.h"
#include "settings.h"
void Menu();

void Menu()
{
main:
	//Play();
	createimages();
	dbHideSprite(599);
	int option = 0;

	int once = 0;
	while ( LoopGDK ( ) )
	{
		if (once == 0)
		{
			dbSetSpriteAlpha(75,100);
			dbSync();
			Fade();
		}
		dbSetSpriteAlpha(75,100);
		dbSync();
		dbSprite(7,dbMouseX(),dbMouseY(),7);
		dbHideSprite(7);
		dbScaleSprite ( 7, 50 );

		//Animation playing statements
		if (option == 1 && !(dbSpriteFrame ( 74 ) > 15)) 
			dbPlaySprite ( 74, 1, 16, 30);
		else if (option == 2 && !(dbSpriteFrame ( 73 ) > 15)) 
			dbPlaySprite ( 73, 1, 16, 30);
		else if (option == 3 && !(dbSpriteFrame ( 72 ) > 15)) 
			dbPlaySprite ( 72, 1, 16, 30);
		else if (option == 4 && !(dbSpriteFrame ( 71 ) > 15)) 
			dbPlaySprite ( 71, 1, 16, 30);
		else if (option == 5 && !(dbSpriteFrame ( 6 ) > 15)) 
			dbPlaySprite ( 70, 1, 16, 30);
		else
			option = 0;

		//Statements for what happens for each door:
		//Exit door
		if (dbSpriteFrame ( 70 ) > 15)
		{
			RFade();
			return;
		}
		//instructions

		if (dbSpriteFrame ( 71 ) > 15)
		{
			createimages();
			RFade();
			dbHideSprite(75);
			dbSync();
			dbShowSprite(599);
			dbSync();
			while(dbMouseClick() != 1)
			{dbShowSprite(599);
			dbSync();}
			dbSetSpriteFrame ( 71, 1);
			option = 0;
			dbHideSprite(599);
			dbShowSprite(75);
			dbSync();
			Fade();		
		}

		
		if (dbSpriteFrame ( 74 ) > 15)
		{
			RFade();
			for ( int i = 0; i < 100;i++)
				dbHideSprite(i);
			dbSetSpriteFrame ( 74, 1);
			dbCLS();
			dbSync();
			
			Infinate();
			createimages();
			option = 0;
			for ( int i = 0; i < 100;i++)
				dbShowSprite(i);
			dbHideSprite(599);
			dbSync();
			Fade();		
			//goto main;
		}

		if (dbSpriteFrame (72) > 15)
		{
			RFade();
			for ( int i = 0; i < 100;i++)
				dbHideSprite(i);
			dbSetSpriteFrame ( 72, 1);
			dbCLS();
			dbSync();
			Settings();
			createimages();
			option = 0;
			for ( int i = 0; i < 100;i++)
				dbShowSprite(i);
			dbHideSprite(599);
			dbSync();
			Fade();	
		}

		if (dbSpriteFrame ( 73 ) > 15)
		{
			RFade();
			for ( int i = 0; i < 100;i++)
				dbHideSprite(i);
			dbSetSpriteFrame ( 73, 1);
			dbCLS();
			dbSync();
			Practice();
			createimages();
			option = 0;
			for ( int i = 0; i < 100;i++)
				dbShowSprite(i);
			dbHideSprite(599);
			dbSync();
			Fade();	
			//goto main;
		}

		

		//colission detection
		if (dbSpriteCollision(7,74)==1 && dbMouseClick()==1)
			option = 1;
		else if (dbSpriteCollision(7,73)==1 && dbMouseClick()==1)
			option = 2;
		else if (dbSpriteCollision(7,72)==1 && dbMouseClick()==1)
			option = 3;
		else if (dbSpriteCollision(7,71)==1 && dbMouseClick()==1)
			option = 4;
		else if (dbSpriteCollision(7,70)==1 && dbMouseClick()==1)
			option = 5;

		if ( dbEscapeKey ( ) )
			break;

		// here we make a call to update the contents of the screen
		dbSync ( );
		once = 1;
	}
	return;
}

#endif