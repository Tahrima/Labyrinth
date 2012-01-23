#include <string>
#include "fileiop.h"
#include "mazesetup.h"
#include "selector.h"
#include "intialize.h"
#include "choosemaze.h"
#include <algorithm>
void Infinate ( void )
{
	dbCLS();
	AddFontResource("AngryChalk.ttf") ; //Enter text of choice here, eg "Times New Roman
	char input[10];
	std::string name;
	dbLoadImage("input.png",61,1);
	dbSprite(61,0,0,61);
	dbSizeSprite ( 61, 640, 500 );
	dbShowSprite(61);

	dbLoadImage("cont.png",63,1);
	dbSprite(63,170,380,63);
	dbScaleSprite ( 63, 60 );

	dbLoadImage("contii.png",62,1);
	dbSprite(62,146,367,62);
	dbScaleSprite ( 62, 60 );
	dbHideSprite(62);

	dbDrawSpritesFirst();
	dbSetTextSize(450);
	dbSetTextFont ("AngryChalk"); 
	dbInk (dbRGB(198,17,17),dbRGB(0,0,0));
	dbLoadImage("buttonmask.png",26);
	int opt = 0;

	while (LoopGDK())
	{	

		dbSync();
		dbText ( 100, 270, input);
		dbSprite(26,dbMouseX(),dbMouseY(),26);
		dbHideSprite(26);
		dbScaleSprite ( 26, 50 );
		
		dbSetCursor(100,270);
		if (opt == 0)
		{
		strcpy( input, dbInput());
		name = input;
		if (name == "")
		{
			strcpy( input, "default");
			name = "default";
		}	
		opt = 1;
		}

		dbText ( 100, 270, input);


		if (dbSpriteCollision(63,26) && dbMouseClick()==1)
		{
			dbDeleteSprite ( 23); 
			dbDeleteSprite ( 63);
			dbDeleteSprite ( 62);
			dbDeleteSprite ( 26);
			dbDeleteSprite (61);
			//erase spaces in name here
			writename(name);
			Choosemaze();
			createimages();
			return;
		}
		else if (dbSpriteCollision(63,26))
		{
			dbHideSprite(63);
			dbShowSprite(62);
		}
		else
		{
			dbHideSprite(62);
			dbShowSprite(63);
		}

	}

	return;
}