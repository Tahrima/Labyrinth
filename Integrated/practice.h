#include <string>

void Practice ( void )
{
	dbCLS();
	dbLoadImage("practice2.png",27,1);
	dbSprite(27,0,0,27);
	dbSizeSprite ( 27, 640, 500 );

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
		
		if (dbSpriteCollision(28,26) && dbMouseClick()==1)
		{
			dbDeleteSprite ( 26); 
			dbDeleteSprite ( 27);
			dbDeleteSprite ( 28);
			dbDeleteSprite ( 29);
			
			for(int i = 0; i < 9000; i++)
				dbDeleteSprite(i);
			Mazemain(1);
			for(int i = 0; i < 9000; i++)
				dbDeleteSprite(i);
			createimages();
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