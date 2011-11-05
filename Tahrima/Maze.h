#ifndef _Maze_h_
#define _Maze_h_

#include <iostream>

using namespace std;

void draw()
{
	dbLoadImage("cell.png", 1); // 20 x 20
	dbLoadImage("v.png", 2); // 20 x 1
	dbLoadImage("h.png", 3); // 1 x 20
	
int sc = 1; // cell counter
int scv = 500; // vertical line counter
int sch = 1000; // horizontal line counter

for(int y = 0; y < 21; ++y) // horizontal 
{
	for (int x = 0; x < 20; ++x){
		dbDrawSpritesFirst();
		dbSprite(sch, x * 20, y * 20, 3);
		++sch;
	}
}
for (int  y =0; y < 20; ++y){ // vertical + cell
	
	for (int x = 0; x < 21; ++x){
		dbDrawSpritesFirst();
		dbSprite(scv, x * 20, y * 20, 2);
		++scv;
	}

	for(int x = 0; x < 20; ++x)
	{   dbDrawSpritesFirst();
		dbSprite(sc, x * 20, y * 20, 1);
		++sc;
	}
}
}

#endif