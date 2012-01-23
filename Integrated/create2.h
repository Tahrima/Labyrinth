#ifndef _create2_h_
#define _create2_h_


#include <iostream>
#include "DarkGDK.h"
//#include "Prim.h"
#include "CellImp.h"
#include "FirstDepth.h"

void deletion(int num)
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