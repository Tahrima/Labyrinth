#ifndef _create_h_
#define _create_h_


#include <iostream>
#include "DarkGDK.h"
#include "Prim.h"
#include "CellImp.h"
#include "FirstDepth.h"

void createDelete (int num)
{
	while ( LoopGDK ())
	{
			dbSync();

		dbDeleteSprite(num);
		
		int t = dbTimer();
		while(dbTimer() < t+30)
		{;
		}
		break;
dbSync();
				
	}
}


#endif