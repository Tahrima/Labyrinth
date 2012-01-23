#include <string>
#include "fileiop.h"

void Choosemaze ( void )
{
	dbCLS();
	dbLoadImage("choose.png",25,1);
	dbSprite(25,0,0,25);
	dbSizeSprite ( 25, 640, 500 );

	dbLoadImage("primm.png",34,1);
	dbSprite(34,40,220,34);
	dbScaleSprite ( 34, 50 );


	dbLoadImage("depthfirst.png",35,1);
	dbSprite(35,330,220,35);
	dbScaleSprite ( 35, 50 );


	dbLoadImage("buttonmask.png",26);
	int opt = 0;

	while (LoopGDK())
	{	

		dbSync();
		dbSprite(26,dbMouseX(),dbMouseY(),26);
		dbHideSprite(26);
		dbScaleSprite ( 26, 50 );
		
		if (dbSpriteCollision(35,26) && dbMouseClick()==1)
		{
			for(int i = 0; i < 9000; i++)
				dbDeleteSprite(i);
			Mazemain(2);
			for(int i = 0; i < 9000; i++)
				dbDeleteSprite(i);
			return;
		}

	    if (dbSpriteCollision(34,26) && dbMouseClick()==1)
		{
			for(int i = 0; i < 9000; i++)
				dbDeleteSprite(i);
			Mazemain(3);
			for(int i = 0; i < 9000; i++)
				dbDeleteSprite(i);
			return;
		}
		

	}


	return;
}