#ifndef _functionslab_h_
#define _functionslab_h_

#include "DarkGDK.h"
void Fade ( void )
{
		dbLoadImage("Backdrop.bmp", 5001);
		dbSprite(5001,0,0,5001);
		dbShowSprite(5001);
		dbSetSpritePriority(5001,6);
		for (int i = 255; i > 0; i-=4)
		{
				dbWait(1);
				dbSetSpriteAlpha( 5001, i);
				dbFastSync();
		}
		dbHideSprite(5001);
		dbSync();
		return;
}

void RFade ( void )
{
		dbLoadImage("Backdrop.bmp", 5001);
		dbSprite(5001,0,0,5001);
		dbShowSprite(5001);
		dbSetSpritePriority(5001,6);
		for (int i = 0; i < 255; i+=4)
		{
				dbWait(1);
				dbSetSpriteAlpha( 5001, i);
				dbSync();
		}
		dbHideSprite(5001);
		dbFastSync();
		return;
}
#endif