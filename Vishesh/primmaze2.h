#include <iostream>
#include <ctime>
#include <vector>
//#include "DarkGDK.h"
using namespace std;


void primmaze2 ()
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
	wall[cellnum] = 1;
//	pickwall.push_back(cellnum);
	cout <<"Horizontal wall 1: " <<cellnum <<endl;

	wall[cellnum + 20] = 1;
//	pickwall.push_back(cellnum + 20);
	cout <<"Horizontal wall 2: " <<cellnum + 20 <<endl;

	//put vertical walls in wall list
	int cellformula = cellnum + (cellnum/20) + 420;
	if(cellnum%20 == 0)
	{
		wall[cellformula - 1 ] = 1;
//		pickwall.push_back(cellformula - 1);
		cout <<"Vertical wall 1: " <<cellformula - 1 <<endl;

		wall[cellformula] = 1;
//		pickwall.push_back(cellformula);
		cout <<"Vertical wall 2: " <<cellformula <<endl;
	}
	else
	{
		wall[cellformula] = 1;
//		pickwall.push_back(cellformula);
		cout <<"Vertical wall 1: " <<cellformula <<endl;

		wall[cellformula + 1] = 1;
//		pickwall.push_back(cellformula + 1);
		cout <<"Vertical wall 2: " <<cellformula + 1 <<endl;
	}




	//check if there are walls in wall list
	int check = 0;
	int size1 = wall.size();
	for(int i = 0 ; i < size1; ++i)
	{
		if(wall[i] ==1)
			{
				++check;
				break;
			}
		
	}

	//while(check > 0)
	for(int i = 0; i < 900; ++i)
	{
		srand(time(NULL));
		int randwall = rand()%840 + 1;
		while(wall[randwall] != 1 || randwall <= 20 || (randwall >= 400 && randwall <=420))
		{
			
			randwall = rand()%840 + 1;
		}

		cout <<"Random wall is: " << randwall <<endl;
		if(randwall <= 20 || randwall >= 400)
			wall[randwall] = -1;
		else if(randwall < 400 && randwall > 20)//we know wall chosen is horizontal and not border
		{
			if(cell[randwall] ==1 && cell[randwall - 20] ==1)//if cells bordering wall are both visited
			{
				cout <<"Before check1: " <<endl;
				wall[randwall] = -1;//remove wall from wall list
				cout <<"Reached check1: " <<endl;
			}
			else//if cells bordering are not both visited
			{
				cout <<"Before check2: " <<endl;
				wall[randwall] = -1;//delete wall
				cout <<"Reached check2: " <<endl;
				dbDeleteSprite(randwall + 500);
				cell[randwall] = 1;//mark bordering wall as visited
				cout <<"Reached check3: " <<endl;

				//add its walls to the list
				wall[randwall + 20] = 1;//add hwall to list
				cout <<"Reached check4: " <<endl;
				wall[randwall + randwall/20] = 1;//add vwall1 to list
				cout <<"Reached check5: " <<endl;
				wall[randwall + randwall/20 + 1] = 1;//add vwall2 to list
				cout <<"Reached check6: " <<endl;

				cell[randwall - 20] =1;//mark bordering wall as visited
				cout <<"Reached check7: " <<endl;

				//add its walls to the list
				wall[randwall - 20] = 1;//adding hwall to list
				cout <<"Reached check8: " <<endl;
				wall[(randwall - 20) + ((randwall - 20)/20)] = 1;
				cout <<"Reached check9: " <<endl;
				wall[(randwall - 20) + ((randwall - 20)/20) + 1] = 1;
				cout <<"Reached check10: " <<endl;

				cout <<"DELETE: " <<randwall <<endl;
			}
		}
		else //we know if wall chosen is vertical
		{
			int randwallsub = randwall - 420;
			if(randwallsub > 21) //if wall is not in first row
			{
				
				if(cell[randwallsub - randwallsub/20] ==1 && cell[randwallsub - randwallsub/20 + 1] == 1)//if cells bordering wall are both visited
				{
						
						wall[randwall] = -1;//remove walls from wall list
				}
				else //if cells bordering are not both visited
				{	
					
					wall[randwall] = -1;
					dbDeleteSprite(randwall + 1000);

					cell[randwallsub - randwallsub/20] = 1;//marking bordering cell as visited

					wall[randwallsub - randwallsub/20] = 1;//adding horizontal wall to wall list
					wall[randwallsub - randwallsub/20 + 20] = 1;//adding horizontal wall2 to wall list
					wall[(randwallsub - randwallsub/20) + ((randwallsub - randwallsub/20)/20) + 420] = 1; //adding vertical wall to list (cell + cell/20 + 420)


					cell[randwallsub - randwallsub/20 + 1] = 1;//marking bordering cell as visited
					wall[randwallsub - randwallsub/20 + 1] = 1;//adding horizontal wall to list
					wall[randwallsub - randwallsub/20 + 1 + 20] = 1;//adding horizontal wall2 to list
					wall[(randwallsub - randwallsub/20 + 1) + ((randwallsub - randwallsub/20u + 1)/20) + 421] = 1; //adding vertical wall to list
					
					
					cout <<"DELETE: " <<randwall <<endl;
				}
			}
			else //if wall is in first row
			{
				if(cell[randwallsub - randwallsub/20] ==1 && cell[randwallsub - randwallsub/20 - 1] ==1) //if cells bordering wall are both visited
					wall[randwall] = -1;
				else
				{
					wall[randwall] = -1;
					dbDeleteSprite(randwall + 1000);


					cell[randwallsub - randwallsub/20] =1;//mark bordering cell as visited

					//add its walls to the list
					wall[randwallsub - randwallsub/20 + 20] = 1;//ONLY ONE HORIZONTAL WALL ADDED BECAUSE OTHER IS BORDER WALL
					wall[(randwallsub - randwallsub/20) + ((randwallsub - randwallsub/20)/20)] = 1;//adding vwall to list
					wall[(randwallsub - randwallsub/20) + ((randwallsub - randwallsub/20)/20) - 1] = 1;//adding vwall2 to list




					cell[randwallsub - randwallsub/20 - 1] =1;//mark bordering cell as visited
					
					//add its walls to the list
					wall[randwallsub - randwallsub/20 - 1 + 20] = 1;//ONLY ONE HORIZONTAL WALL ADDED BECAUSE OTHER IS BORDER WALL
					wall[(randwallsub - randwallsub/20 - 1) + ((randwallsub - randwallsub/20 - 1)/20)] = 1;
					wall[(randwallsub - randwallsub/20 - 1) + ((randwallsub - randwallsub/20 - 1)/20) - 1] = 1;
					cout <<"DELETE: " <<randwall <<endl;
				}
			}
		}

		
		check = 0;
		
		int size = wall.size();
		for(int i = 0; i < size; ++i)
		{
			if(wall[i] ==1)
			{
				++check;
				cout <<check <<endl;
				
			}
			
		}
	
		}
	
		//cout <<"Thats all folks..." <<endl;


	


			//for(int i = 0; i < pickwall.size(); ++i)
				//cout << i <<": " <<pickwall[i] <<endl;
			
	
}