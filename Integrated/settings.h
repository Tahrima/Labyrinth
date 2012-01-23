#include <string>
#include "fileiop.h"

void Settings ( void )
{
	dbCLS();
	dbLoadImage("settings2.png",25,1);
	dbSprite(25,0,0,25);
	dbSizeSprite ( 25, 640, 500 );

	dbLoadImage("yes.png",30,1);
	dbSprite(30,100,220,30);
	dbScaleSprite ( 30, 60 );
	dbLoadImage("yesglow.png",31,1);
	dbSprite(31,100,220,31);
	dbScaleSprite ( 31, 60 );
	dbHideSprite(31);

	dbLoadImage("no.png",32,1);
	dbSprite(32,450,220,32);
	dbScaleSprite ( 32, 60 );

	dbLoadImage("noglow.png",33,1);
	dbSprite(33,450,220,33);
	dbScaleSprite ( 33, 60 );
	dbHideSprite(33);


	dbLoadImage("cont.png",28,1);
	dbSprite(28,170,380,28);
	dbScaleSprite ( 28, 60 );

	dbLoadImage("contii.png",29,1);
	dbSprite(29,146,367,29);
	dbScaleSprite ( 29, 60 );
	dbHideSprite(29);
	dbLoadImage("buttonmask.png",26);
	int opt = 0;

	while (LoopGDK())
	{	

		dbSync();
		dbSprite(26,dbMouseX(),dbMouseY(),26);
		dbHideSprite(26);
		dbScaleSprite ( 26, 50 );
		
		if (dbSpriteCollision(30,26) && dbMouseClick()==1)
		{
			dbShowSprite(32);
			dbHideSprite(33);
			dbHideSprite(30);
			dbShowSprite(31);
			showcreation(true);
		}

	    if (dbSpriteCollision(32,26) && dbMouseClick()==1)
		{
			dbShowSprite(33);
			dbHideSprite(32);
			dbHideSprite(31);
			dbShowSprite(30);
			showcreation(false);
		}


		
		if (dbSpriteCollision(28,26) && dbMouseClick()==1)
		{
			dbDeleteSprite ( 26); 
			dbDeleteSprite ( 27);
			dbDeleteSprite ( 28);
			dbDeleteSprite ( 29);
			
			return;

		}
		else if (dbSpriteCollision(28,26))
		{
			dbHideSprite(28);
			dbShowSprite(29);
		}
		else
		{
			dbHideSprite(29);
			dbShowSprite(28);
		}

	}


	return;
}