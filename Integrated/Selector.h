#ifndef _Selector_h_
#define _Selector_h_

#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include "Convert.h"
#include "CellImp.h"
#include "FirstDepth.h"
#include "Prim.h"
#include "DarkGDK.h"
#include "Maze.h"
#include "AutoSolver.h"
#include "functionslab.h"
#include "fileiop.h"
#include "menusystem.h"


using namespace std;

void Detect_Key(Cell **, PrimCell **, int, int, int, int, int, bool);

void Gend()
{
	int backt = 2000;
	for(int y = 0; y < 20; y++)
		for(int x = 0; x < 20; x++)
		{
			dbDeleteSprite(backt);
			backt++;
		}	
	dbDeleteSprite(5000);
}

void Gent()
{
	srand((unsigned)time(0));
	dbLoadImage("tile1.bmp",7,1);
	dbLoadImage("tile2.bmp",8,1);
	dbLoadImage("tile3.bmp",9,1);
	dbLoadImage("end.bmp",10,1);
	int backt = 2000;
	for(int y = 0; y < 20; y++)
		for(int x = 0; x < 20; x++)
		{
			if(((rand() % 3) + 1) == 1)
				dbSprite(backt, (x+6) * 20, (y+3) * 20, 7);
			else if(((rand() % 3) + 1) == 2)
				dbSprite(backt, (x+6) * 20, (y+3) * 20, 8);
			else if(((rand() % 3) + 1) == 3)
				dbSprite(backt, (x+6) * 20, (y+3) * 20, 9);
			else
				dbSprite(backt, (x+6) * 20, (y+3) * 20, 9);
			dbSetSpritePriority(backt,2);
			backt++;
		}	
	//int exitnum = (rand() % 410) + 10;
	dbSprite(5000, 500, 440, 10);
	dbSetSpritePriority(5000,2);
	
}

void First_Depth (int r, int c, Cell ** maze){
	initialize(r, c, maze);
	algorithm(maze);
}

void Prim (int r, int c, PrimCell** pmaze){	

	pinitialize(r, c, pmaze);

	srand((unsigned)time(0));	
	int Current = (rand()% 400) + 1;
	
	int row = getrow(Current); // returns row from Convert.h
	int col = getcol(Current); // returns column

	//maze[row][col].setVisited(1); // marked as part of the  maze

	ofstream store("order.txt", ios::app);
	store << row << " " << col << endl;

	int count = 1;
	vector<string> list;
	pushbacker(pmaze[row][col], Current, list, count, row, col);
	walldestiny(list, pmaze);
}

int Choose_Maze (void){

	int flag = -1;
	while ( LoopGDK ()){

		if (dbSpaceKey() == 1){
			flag = 1;
			return flag;
		}
		else if (dbEscapeKey() == 1){
			flag = 0;
			return flag;
		}
		dbSync();	
	}
}


void Detect_Key (Cell ** maze, PrimCell ** pmaze, int xint, int yint, int r, int c, int choice, bool once)
{
	dbLoadSound ( "hit.wav", 5 );
	int level = 1;
	int maxtime = 500;
	//int yint = 63;
	//int xint = 125;
	
	dbLoadMusic("level2.mp3", 1);
	dbLoadMusic("preview.mp3", 2);
	dbPlayMusic(1);
	int vol = 100;


	dbLoadImage("newconcrete.png",4998);
	dbSprite(4998,0,0,4998);
	dbSizeSprite ( 4998, 640, 500 );
	dbSetSpritePriority(4998,6);
	dbHideSprite(4998);

	dbLoadImage("Backdrop.bmp",4999);
	dbSprite(4999,0,0,4999);
	dbSetSpritePriority(4999,6);
	dbHideSprite(4999);
	
	dbLoadImage("sprite.png", 5);
	dbLoadImage("bakround.png",6);
	dbSprite(6,0,0,6);
	dbSizeSprite ( 6, 640, 500 );
	dbSetSpritePriority ( 6, 0 ); 
	dbCreateAnimatedSprite(5,"spriteold.png",3,4,4);
	dbSprite(5,xint,yint,4);
	dbSprite(1501,xint,yint,5);
	

	//position of scarfy
	int X=118;
	int Y=43;
	int opt = 0;

	char time[1]; //char array to hold time value
	int timer; //hold the seconds value
	int timenum;
	//int level = 1;
	char levels[3];
	//int maxtime = 500; //sets the max time for solving a level
	//srand((unsigned)time(0));

	for (int i = 1; i < 2000; i++)
		dbSetSpritePriority (i, 5);
	dbSetSpritePriority(6,2);

	dbDrawSpritesFirst();
	AddFontResource("Sketchy.ttf");	
	dbSetTextSize(60);
	dbSetTextFont ("Sketchy"); 
	dbInk (dbRGB(255,255,255),dbRGB(0,0,0));


	clock_t begin = clock(); 

	Gent();
	bool finished = false;
	while ( LoopGDK ())
	{
		if(dbSpriteCollision(1501,5000))
		{
			if(once == true)
				return;
			else
				finished = true;
		}
		timer = (clock() - begin) / CLOCKS_PER_SEC; //"reset" the clock
		dbText(5,0,"Time: ");
		timenum = maxtime - timer; //get the amount of time passed
		itoa(timenum,time,10);//convert
		dbText(115,0,time); //display it

		dbText(430,0,"Level: ");
		itoa(readlevel(),levels,10);//convert
		dbText(550,0,levels); //display it
		

		

		//if ( dbMouseClick() == 1 )
		//	bClick = true;
		if(finished == true)
		{
			finished = false;
			Gend();
			draw();		
			for(int i = 3000; i < 9000; i++)
				dbDeleteSprite(i);
			addlevel();
			if (choice == 1)
			{
				
				Cell ** maze = new Cell*[r+1]; // declares a dynamic object with 2 dimensions. 1st dimension = d1
				for (int i = 1; i <= r; ++i) 
					maze[i] = new Cell[c+1]; // creates 2nd dimension (d2)
				First_Depth(r, c, maze);

				dbCreateAnimatedSprite(5,"spriteold.png",3,4,4);
				dbSprite(5, 118, 43, 4);
				dbSprite(6,0,0,6);
				Gent();
				for (int i = 1; i < 2000; i++)
					dbSetSpritePriority (i, 5);
				dbSetSpritePriority(6,0);
				dbSizeSprite ( 6, 640, 500 );
				dbDrawSpritesFirst();
				level++;
				dbSprite(1501,125,63,5);
				X=118;
				Y=43;
				begin = clock(); 

				if(maxtime > 50)
					maxtime -= 50;
				
			}
			else
			{
				finished = false;
				Gend();
				//for(int i = 0; i < 6000; i++)
				//	dbDeleteSprite(i);

				PrimCell ** pmaze = new PrimCell*[r+1]; // declares a dynamic object with 2 dimensions. 1st dimension = d1
				for (int i = 1; i <= r; ++i) 
					pmaze[i] = new PrimCell[c+1]; // creates 2nd dimension (d2)

				Prim(r,c, pmaze);

				dbCreateAnimatedSprite(5,"spriteold.png",3,4,4);
				dbSprite(5, 118, 43, 4);
				dbSprite(6,0,0,6);
				Gent();
				for (int i = 1; i < 2000; i++)
					dbSetSpritePriority (i, 5);
			    dbSetSpritePriority(6,0);
				dbSizeSprite ( 6, 640, 500 );
				dbDrawSpritesFirst();
				dbSprite(1501,125,63,5);
				level++;
				begin = clock(); 
				X=118;
				Y=43;
				if(maxtime > 50)
					maxtime -= 50;
			}
		}

		
		if (dbShiftKey() == 1)
			finished = true;
		if (dbControlKey() == 1)
			maxtime = 0;

		dbHideSprite(1501);
		if(dbDownKey())
		{
			if (opt != 0)
				dbSetSpriteFrame ( 5, 4 );
			dbPlaySprite ( 5, 4, 6, 5 );

			dbRotateSprite(1501,180);
			dbMoveSprite(1501,2);
			dbRotateSprite(1501, 0);
			Y+=2;
					
			if(dbSpriteCollision(1501,0) > 500 &&  dbSpriteCollision(1501,0) < 2000)
			{
				//dbPlaySound (5); 
				dbRotateSprite(1501,0);
				dbMoveSprite(1501,2);
				dbRotateSprite(1501, 0);
				Y-=2;
			}
			opt = 0;
		}
		else if(dbUpKey())
		{
			if (opt != 1)
				dbSetSpriteFrame ( 5, 1 );
			dbPlaySprite ( 5, 1, 3, 5 );

			Y-=2;
			dbRotateSprite(1501,0);
			dbMoveSprite(1501,2);
								
			if(dbSpriteCollision(1501,0) > 500 &&  dbSpriteCollision(1501,0) < 2000)
			{
				//dbPlaySound (5); 
				dbRotateSprite(1501,180);
				dbMoveSprite(1501,2);
				dbRotateSprite(1501, 0);
				Y+=2;
			}

			opt = 1;
		}
		else if(dbRightKey())
		{
			if (opt != 2)
				dbSetSpriteFrame ( 5, 7 );
			dbPlaySprite ( 5, 7, 9, 5 );
	
			dbRotateSprite(1501,90);
			dbMoveSprite(1501,2);
			dbRotateSprite(1501, 0);
			X+=2;
			
			if(dbSpriteCollision(1501,0) > 500 &&  dbSpriteCollision(1501,0) < 2000)
			{
				//dbPlaySound (5); 
				dbRotateSprite(1501,270);
				dbMoveSprite(1501,2);
				dbRotateSprite(1501, 0);
				X-=2;
			}
			opt = 2;
		}
		else if(dbLeftKey())
		{
			if (opt != 3)
				dbSetSpriteFrame ( 5, 10 );
			dbPlaySprite ( 5, 10, 12,5 );

			dbRotateSprite(1501,270);
			dbMoveSprite(1501,2);
			dbRotateSprite(1501, 0);
			X-=2;
		
			if(dbSpriteCollision(1501,0) > 500 && dbSpriteCollision(1501,0) < 2000)
			{
				//dbPlaySound (5); 
				dbRotateSprite(1501,90);
				dbMoveSprite(1501,2);
				dbRotateSprite(1501, 0);
				X+=2;
			}
			opt = 3;
		}

		if(timenum < 0)
		{
			if (once == true)
				return;
			else
			{
			dbHideSprite(5000);
			for (int i = 0; i < 4000;i++)
			{
				dbHideSprite(i);
				dbShowSprite(6);
				//dbSync();
			}
			RFade();
			
			dbLoadImage("newconcrete.png",4998);
			dbSprite(4998,0,0,4998);
			dbSizeSprite ( 4998, 640, 500 );
			dbSetSpritePriority(4998,6);
			dbHideSprite(6);
			dbSync();			
			dbSetTextSize ( 100 );
			dbShowSprite(4998);
			dbInk (dbRGB(0,0,0),dbRGB(0,0,0));
			dbSync();
			if(writefinal(readlevel()) == 1)
			{
				while(dbReturnKey() != 1)
				{
				char oldsc[10];
				dbText(40,-5,"Congratulations!");
				dbText(10,80,"Name:      Score:");
				string name = Returnname();
				name.resize(10);
				strcpy(oldsc,name.c_str());
				dbText(10,150,oldsc);
				dbText(400, 150, levels);
				dbText(95,230,"You beat the");
				dbText(45,310,"High Score of");
				itoa(Returnscore(),oldsc,10);
				dbText(530,310,oldsc);
				dbText(140,400,"Press Enter");
				dbSync();
				}
				dbHideSprite(4998);
				return;
			}
			else
			{
				while(dbReturnKey() != 1)
				{
				dbText(120,10,"Game Over");
				dbText(5,130,"You beat ");
				
				dbText(320,130,levels);
				if (Returnscore() == 1)
				{
					dbText(430,130," level");
				}
				else
				{
					dbText(430,130," levels");
				}
				dbText(130,280,"Press Enter");
				dbSync();
				}	
				dbHideSprite(4998);
				return;

			}
			dbSync();
			//Menu();
			}
		}


		  
		dbSprite(5, X, Y, 4);


		

		if(dbKeyState(2) != 0) 
		{
			dbStopMusic(2);
			dbPlayMusic(1);
		}
		if(dbKeyState(3) != 0)
		{
			dbStopMusic(1);
			dbPlayMusic(2);
		}
		if(dbKeyState(13) != 0)
			vol = vol + 3;
		if(dbKeyState(12) != 0)
			vol = vol - 3;
		dbSetMusicVolume(1, vol);
		dbSetMusicVolume(2, vol);
		if(dbKeyState(11) != 0)
		{	dbStopMusic(1); dbStopMusic(2);
		}
		dbSync();
	}
	return;
}

#endif