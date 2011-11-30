#include <iostream>
#include <ctime>
#include <vector>
#include "DarkGDK.h"
using namespace std;


void primmaze3 ()
{

	srand(time(NULL));
	int cellnum = rand()%400 + 1;
	cout << "Starting cellnum is: " <<cellnum <<endl;

	vector <int> cell(401,0); //ignore 0th element; we want 1-400
	cell[cellnum] = 1;//initial cell to start maze

	//vector for wall list; 1-420 for horizontal, 421-840 for vertical 
	vector <int> wall(841,0);

	//assigning horizontal border walls -1
	for(int i = 1; i < 21; ++i)
	{
		wall[i] = -1;
		
	}
	for(int i = 1; i < 21; ++i)
	{
		wall[i + 400] = -1;
	}

	//assigning vertical border walls -1
	for(int i = 1; i < 21; ++i)
	{
		wall[i * 21 + 420] = -1;
	}
	for(int i = 0; i < 20; ++i)
	{
		wall[i*21 + 1 + 420] = -1;
	}

	//test to see if right elements were assigned -1
/*
	for(int i = 0; i <= 840; ++i)
	{
		cout << i  <<": " << wall[i] <<endl;
	}
	
*/



//	vector <int> pickwall(0);

	//put horizontal walls in wall list
	if(wall[cellnum] == 0 || wall[cellnum] == 1)
		wall[cellnum] = 1;
//	pickwall.push_back(cellnum);
	cout <<"Horizontal wall 1: " <<cellnum <<endl;

	if(wall[cellnum + 20] == 0 || wall[cellnum + 20] == 1)
	wall[cellnum + 20] = 1;
//	pickwall.push_back(cellnum + 20);
	cout <<"Horizontal wall 2: " <<cellnum + 20 <<endl;

	//put vertical walls in wall list
	int cellformula = cellnum + (cellnum/20) + 420;
	if(cellnum%20 == 0)
	{
		if(wall[cellformula - 1 ] == 0 || wall[cellformula - 1 ] ==1)
		wall[cellformula - 1 ] = 1;
//		pickwall.push_back(cellformula - 1);
		cout <<"Vertical wall 1: " <<cellformula - 1 <<endl;

		if(wall[cellformula] == 0 || wall[cellformula] == 1)
		wall[cellformula] = 1;
//		pickwall.push_back(cellformula);
		cout <<"Vertical wall 2: " <<cellformula <<endl;
	}
	else
	{
		if(wall[cellformula] == 0 || wall[cellformula] == 1)
		wall[cellformula] = 1;
//		pickwall.push_back(cellformula);
		cout <<"Vertical wall 1: " <<cellformula <<endl;

		if(wall[cellformula + 1 ] == 0 || wall[cellformula + 1 ] ==1)
		wall[cellformula + 1] = 1;
//		pickwall.push_back(cellformula + 1);
		cout <<"Vertical wall 2: " <<cellformula + 1 <<endl;
	}




	//check if there are walls in wall list

	int check = 0;
/*******************************************************	
		cout <<"The border walls are: " <<endl;
	for(int i = 0 ; i < 841; ++i)
	{
		if(wall[i] == -1)
			{
				cout <<i <<endl;
			}
		
	}
*****************************************************/

	cout <<"The walls in the wall list are: " <<endl;
	for(int i = 0 ; i < 841; ++i)
	{
		if(wall[i] ==1)
			{
				++check;
				
				cout <<i <<endl;
			}
		
	}

	

	while(check > 0)
	//for(int i = 0; i < 900; ++i)
	{
		srand(time(NULL));
		int randwall = rand()%840 + 1;
		while(wall[randwall] != 1)
		//while(wall[randwall] != 1 || randwall <= 20 || (randwall >= 400 && randwall <=420))
		{
			
			randwall = rand()%840 + 1;
		}

		cout <<"Random wall is: " << randwall <<endl;
		

		//determine if the wall is hori or vert
		if(randwall <= 420)//we know wall chosen is horizontal
		{
			if(randwall >= 400 || randwall <= 20)//ignore border wall to handle "vector subscript out of range" error
				wall[randwall] = -1;
			else if(cell[randwall] ==1 && cell[randwall - 20] ==1)//if cells bordering wall are both visited
			{
				//cout <<"Before check1: " <<endl;
				wall[randwall] = -2;//remove wall from wall list
				cout <<"Removed wall from wall list: " << randwall <<endl;
			}
			else//if cells bordering are not both visited
			{
				//cout <<"Before check2: " <<endl;
				wall[randwall] = -3;//delete wall
				cout <<"Deleted wall: " <<randwall << endl;
			dbDeleteSprite(randwall + 999);
				cell[randwall] = 1;//mark bordering cell as visited
				//cout <<"Reached check3: " <<endl;

				//add its walls to the list
				if(wall[randwall + 20] == 0 || wall[randwall + 20] == 1)
				{wall[randwall + 20] = 1;//add hwall to list
				cout <<"Added hwall: " << randwall+20 <<endl;}

				if(wall[randwall + randwall/20 + 420] == 0 || wall[randwall + randwall/20 + 420] == 1)
				{wall[randwall + randwall/20 + 420] = 1;//add vwall1 to list //ADDED 420
				cout <<"Added vwall1: " << randwall + randwall/20 + 420 <<endl;} //ADDED 420

				if(wall[randwall + randwall/20 + 1 + 420] == 0 || wall[randwall + randwall/20 + 1 + 420] == 1)
				{wall[randwall + randwall/20 + 1 + 420] = 1;//add vwall2 to list //ADDED 420
				cout <<"Added vwall2: " <<randwall + randwall/20 + 1+ 420<<endl;}  //ADDED 420


				cell[randwall - 20] =1;//mark bordering cell as visited
				//cout <<"Reached check7: " <<endl;
				//add its walls to the list
				if(wall[randwall - 20] == 0 || wall[randwall - 20] == 1)
				{wall[randwall - 20] = 1;//adding hwall to list
				cout <<"Added hwall: " <<randwall - 20 <<endl;}

				if(wall[(randwall - 20) + ((randwall - 20)/20)+ 420] == 0 || wall[(randwall - 20) + ((randwall - 20)/20)+ 420] == 1)
				{wall[(randwall - 20) + ((randwall - 20)/20)+ 420] = 1;//adding vwall1 to list //ADDED 420
				cout <<"Added vwall1: " <<(randwall - 20) + ((randwall - 20)/20)+ 420 <<endl;} //ADDED 420

				if(wall[(randwall - 20) + ((randwall - 20)/20) + 1+ 420] == 0 || wall[(randwall - 20) + ((randwall - 20)/20) + 1+ 420] == 1)
				{wall[(randwall - 20) + ((randwall - 20)/20) + 1+ 420] = 1;//adding vwall2 to list //ADDED 420
				cout <<"Added vwall2: " <<(randwall - 20) + ((randwall - 20)/20) + 1+ 420 <<endl;} //ADDED 420

			
			}
		}
		else //we know if wall chosen is vertical
		{
			if(randwall == 839) //SPECIAL CASE FOR 839
			{
				cell[399] = 1;
				wall[838] = 1;
				wall[399] = 1;
				
				cell[400] = 1;
				wall[400] = 1;
			}

			int randwallsub = randwall - 420;
			if(randwallsub > 21) //if wall is not in first row...coz algorithm for finding bordering cells is diff when vwall is in first row
			{
				
				if(cell[randwallsub - randwallsub/20] ==1 && cell[randwallsub - randwallsub/20 + 1] == 1)//if cells bordering wall are both visited
				{
						
						wall[randwall] = -2;//remove walls from wall list
						cout <<"Removed wall from wall list: " << randwall << endl;
				}
				else //if cells bordering are not both visited
				{	
					
					wall[randwall] = -3;
					cout <<"Deleted wall: " << randwall <<endl;
					dbDeleteSprite(randwallsub + 499);

					cell[randwallsub - randwallsub/20] = 1;//marking bordering cell as visited

					if(wall[randwallsub - randwallsub/20] == 0 || wall[randwallsub - randwallsub/20] == 1)
					{wall[randwallsub - randwallsub/20] = 1;//adding horizontal wall to wall list
					cout <<"Added hwall1: " << randwallsub - randwallsub/20 <<endl;}

					if(wall[randwallsub - randwallsub/20 + 20] == 0 || wall[randwallsub - randwallsub/20 + 20] == 1)
					{wall[randwallsub - randwallsub/20 + 20] = 1;//adding horizontal wall2 to wall list
					cout <<"Added hwall2: " << randwallsub - randwallsub/20 + 20 <<endl;}

					if(wall[(randwallsub - randwallsub/20) + ((randwallsub - randwallsub/20)/20) + 420] == 0 || wall[(randwallsub - randwallsub/20) + ((randwallsub - randwallsub/20)/20) + 420] == 1)
					{wall[(randwallsub - randwallsub/20) + ((randwallsub - randwallsub/20)/20) + 420] = 1; //adding vertical wall to list (cell + cell/20 + 420) //ADDED 420
					cout <<"Added vwall: " << (randwallsub - randwallsub/20) + ((randwallsub - randwallsub/20)/20) + 420 <<endl;} //ADDED 420


					cell[randwallsub - randwallsub/20 + 1] = 1;//marking bordering cell as visited

					if(wall[randwallsub - randwallsub/20 + 1] == 0 || wall[randwallsub - randwallsub/20 + 1] == 1)
					{wall[randwallsub - randwallsub/20 + 1] = 1;//adding horizontal wall to list
					cout <<"Added hwall1: " << randwallsub - randwallsub/20 + 1 <<endl;}

					if(wall[randwallsub - randwallsub/20 + 1 + 20] == 0 || wall[randwallsub - randwallsub/20 + 1 + 20] == 1)
					{wall[randwallsub - randwallsub/20 + 1 + 20] = 1;//adding horizontal wall2 to list
					cout <<"Added hwall2: " << randwallsub - randwallsub/20 + 1 + 20 <<endl;}

					if(wall[(randwallsub - randwallsub/20 + 1) + ((randwallsub - randwallsub/20 + 1)/20) + 421] == 0 || wall[(randwallsub - randwallsub/20 + 1) + ((randwallsub - randwallsub/20 + 1)/20) + 421] == 1)
					{wall[(randwallsub - randwallsub/20 + 1) + ((randwallsub - randwallsub/20 + 1)/20) + 421] = 1; //adding vertical wall to list
					cout <<"Added vwall: " << (randwallsub - randwallsub/20 + 1) + ((randwallsub - randwallsub/20u + 1)/20) + 421 <<endl;}
					
					
				}
			}
			else //if wall is in first row
			{
				if(cell[randwallsub - randwallsub/20] ==1 && cell[randwallsub - randwallsub/20 - 1] ==1) //if cells bordering wall are both visited
					{wall[randwall] = -2;//removing wall from wall list
				cout <<"Removed wall from wall list: " <<randwall <<endl;}
				else
				{
					wall[randwall] = -3;
					cout <<"Deleted wall: " <<randwall <<endl;
					dbDeleteSprite(randwallsub + 499);


					cell[randwallsub - randwallsub/20] =1;//mark bordering cell as visited

					//add its walls to the list
					if(wall[randwallsub - randwallsub/20 + 20] == 0 || wall[randwallsub - randwallsub/20 + 20] == 1)
					{wall[randwallsub - randwallsub/20 + 20] = 1;//ONLY ONE HORIZONTAL WALL ADDED BECAUSE OTHER IS BORDER WALL
					cout <<"Added hwall1: " << randwallsub - randwallsub/20 + 1 <<endl;}

					if(wall[(randwallsub - randwallsub/20) + ((randwallsub - randwallsub/20)/20)] == 0 || wall[(randwallsub - randwallsub/20) + ((randwallsub - randwallsub/20)/20)] == 1)
				{wall[(randwallsub - randwallsub/20) + ((randwallsub - randwallsub/20)/20)] = 1;//adding vwall to list
					cout <<"Added vwall: " << (randwallsub - randwallsub/20) + ((randwallsub - randwallsub/20)/20) <<endl;}

					if(wall[(randwallsub - randwallsub/20) + ((randwallsub - randwallsub/20)/20) - 1] == 0 || wall[(randwallsub - randwallsub/20) + ((randwallsub - randwallsub/20)/20) - 1] == 1)
				{wall[(randwallsub - randwallsub/20) + ((randwallsub - randwallsub/20)/20) - 1] = 1;//adding vwall2 to list
					cout <<"Added vwall: " << (randwallsub - randwallsub/20) + ((randwallsub - randwallsub/20)/20) - 1 <<endl;}



					cell[randwallsub - randwallsub/20 - 1] =1;//mark bordering cell as visited
					
					//add its walls to the list
					if(wall[randwallsub - randwallsub/20 - 1 + 20] == 0 || wall[randwallsub - randwallsub/20 - 1 + 20] == 1)
					{wall[randwallsub - randwallsub/20 - 1 + 20] = 1;//ONLY ONE HORIZONTAL WALL ADDED BECAUSE OTHER IS BORDER WALL
						cout <<"Added hwall1: " << randwallsub - randwallsub/20 - 1 + 20<<endl;
					}

					if(wall[(randwallsub - randwallsub/20 - 1) + ((randwallsub - randwallsub/20 - 1)/20)+ 420] == 0 || wall[(randwallsub - randwallsub/20 - 1) + ((randwallsub - randwallsub/20 - 1)/20)+ 420] == 1)
					{wall[(randwallsub - randwallsub/20 - 1) + ((randwallsub - randwallsub/20 - 1)/20)+ 420] = 1;//ADDED 420
					cout <<"Added vwall: " << (randwallsub - randwallsub/20 - 1) + ((randwallsub - randwallsub/20 - 1)/20)+ 420 <<endl;}//ADDED 420
					
					if(wall[(randwallsub - randwallsub/20 - 1) + ((randwallsub - randwallsub/20 - 1)/20) - 1+ 420] == 0 || wall[(randwallsub - randwallsub/20 - 1) + ((randwallsub - randwallsub/20 - 1)/20) - 1+ 420] == 1)
					{wall[(randwallsub - randwallsub/20 - 1) + ((randwallsub - randwallsub/20 - 1)/20) - 1+ 420] = 1;//ADDED 420
					cout <<"Added vwall: " << (randwallsub - randwallsub/20 - 1) + ((randwallsub - randwallsub/20 - 1)/20) - 1+ 420 <<endl;} //ADDED 420
				
				}
			}
		}

		
		check = 0;
		
		cout <<"Walls in wall list: " <<endl;
		for(int i = 0; i < 841; ++i)
		{
			if(wall[i] ==1)
			{
				++check;
				cout << i <<endl;
				
			}
			
		}

		
	
		}//end of while loop
	
		cout <<"Thats all folks..." <<endl;


	


			//for(int i = 0; i < pickwall.size(); ++i)
				//cout << i <<": " <<pickwall[i] <<endl;
			
		


}