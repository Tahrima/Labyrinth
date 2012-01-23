#ifndef _intialize_h_
#define _intialize_h_

#include "DarkGDK.h"

void createimages()
{
	dbLoadImage ( "brickback.bmp", 55 ,1);
	dbSprite ( 55, 0, 0, 55 );
	dbSizeSprite ( 55, 640, 500 );
	dbSetImageColorKey ( 255, 2, 255 );
	dbCreateAnimatedSprite ( 74, "brown.png", 8, 2, 74 );
	dbScaleSprite ( 74, 82 );
	dbSprite ( 74, 126, 257, 74 );

	dbLoadImage ( "cc2.png", 599,1 );
	dbSprite(599,0,0,599);
	dbSizeSprite ( 599, 640, 500 );
	dbHideSprite(599);

	dbCreateAnimatedSprite ( 73, "yellow.png", 8, 2, 73 );
	dbScaleSprite ( 73, 82 );
	dbSprite ( 73, -4, 257, 3 );

	dbCreateAnimatedSprite ( 72, "blue.png", 8, 2, 72 );
	dbScaleSprite ( 72, 82 );
	dbSprite ( 72, 256, 257, 72 );

	dbCreateAnimatedSprite ( 71, "gray.png", 8, 2, 71 );
	dbScaleSprite ( 71, 82 );
	dbSprite ( 71, 386, 257, 71 );

	dbCreateAnimatedSprite ( 70, "red.png", 8, 2, 70 );
	dbScaleSprite ( 70, 82 );
	dbSprite ( 70, 516, 257, 70 );


	dbLoadImage ( "practice.png", 69, 1);
	dbLoadImage ( "infinate.png", 68, 1);
	dbLoadImage ( "Settings.png", 67, 1);
	dbLoadImage ( "instrutions.png", 66, 1);
	dbLoadImage ( "quit.png", 65, 1 ); 
	dbSprite ( 69, -6, 200, 69 ); 
	dbSprite ( 68, 125, 200,68 ); 
	dbSprite ( 67, 256, 200, 67 ); 
	dbSprite ( 66, 386, 200, 66 ); 
	dbSprite ( 65, 516, 200, 65 ); 

	dbScaleSprite (  66,14 );
	dbScaleSprite ( 67,14 );
	dbScaleSprite ( 68,14 );
	dbScaleSprite ( 69,14 ); 
	dbScaleSprite ( 65,14 ); 

	dbLoadImage("buttonmask.png",7);
	dbSprite(7,dbMouseX(),dbMouseY(),7);
	dbHideSprite(7);
	dbScaleSprite ( 7, 50 );
	int option = 0;


	dbLoadImage("labry.png", 76, 1);
	dbSprite(76,10,10,76);
	dbScaleSprite(76,80);

	dbLoadImage("nick.png", 77, 1);
	dbSprite(77,430,120,77);
	dbScaleSprite(77,40);
	dbLoadImage("vish.png", 78, 1);
	dbSprite(78,25,105,78);
	dbScaleSprite(78,40);
	dbLoadImage("francis.png", 79, 1);
	dbSprite(79,280,115,79);
	dbScaleSprite(79,40);
	dbLoadImage("Tahrima.png", 80, 1);
	dbSprite(80,140,160,80);
	dbScaleSprite(80,40);


	dbLoadImage("Backdrop.bmp", 75);
	dbSprite(75,0,0,75);
}
#endif
