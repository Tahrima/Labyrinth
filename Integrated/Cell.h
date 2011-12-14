#ifndef _Cell_h_
#define _Cell_h_

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Convert.h"

using namespace std;

class Cell{
friend void pushbacker(Cell&, int, vector<string> *);
friend void walldestiny(vector<string> &, int);
private:
	class Direction{	// nested class Direction
		public:
			int n,s,e,w;
			void setNorth(int x){ n = x; };
			void setSouth(int x){ s = x; };
			void setEast(int x){ e = x; };
			void setWest(int x){ w = x; };
			void setAll(int a, int b, int c, int d){ n = a; s = b; e = c; w = d;};
		};
	int visited;
public:
	Cell ();
	void setCell(string, char, int);
	void setAllofCell(string, string);
	int getDirection(string, char);
	int Visited();

	Direction border; // using objects of class Dimension as private data members
	Direction walls;
	Direction solution;
	Direction backtrack;
};

void Cell::setCell(string info, char dir, int setting ){
	if (info == "border"){
		switch (dir){
			case 'n': border.setNorth(setting);	break;
			case 's': border.setSouth(setting);	break;
			case 'e': border.setEast(setting);	break;
			case 'w': border.setWest(setting);	break;
			default:							break;
		}
	}

	else if (info == "walls"){
		switch (dir){
			case 'n': walls.setNorth(setting);	break;
			case 's': walls.setSouth(setting);	break;
			case 'e': walls.setEast(setting);	break;
			case 'w': walls.setWest(setting);	break;
			default:							break;
		}
	}

	else if (info == "backtrack"){
		switch (dir){
			case 'n': backtrack.setNorth(setting);	break;
			case 's': backtrack.setSouth(setting);	break;
			case 'e': backtrack.setEast(setting);	break;
			case 'w': backtrack.setWest(setting);	break;
			default:								break;
		}
	}

	else if (info == "solution"){
		switch (dir){
			case 'n': solution.setNorth(setting);	break;
			case 's': solution.setSouth(setting);	break;
			case 'e': solution.setEast(setting);	break;
			case 'w': solution.setWest(setting);	break;
			default:								break;
		}
	}

}

void Cell::setAllofCell(string info, string setting){
	
	char north  = setting.at(0);
	char south = setting.at(1);
	char east = setting.at(2);
	char west = setting.at(3);

	int n = north - 48;
	int s = south - 48;
	int e = east - 48;
	int w = west - 48;

	ofstream come ("neigh.txt");
	come << n << s << e << w;
	
	if (info == "border")
		border.setAll(n,s,e,w);
	else if (info == "walls")
		walls.setAll(n,s,e,w);
	else if (info == "backtrack")
		backtrack.setAll(n,s,e,w);
	else if (info == "solution")
		solution.setAll(n,s,e,w);	
}

Cell::Cell(){
	border.setAll(0,0,0,0);
	walls.setAll(1,1,1,1);
	backtrack.setAll(0,0,0,0);
	solution.setAll(0,0,0,0);
}

int Cell::Visited(){
	return visited;
}

int Cell::getDirection(string info, char setting){
	if (info == "border"){
		switch (setting){
			case 'n': return border.n;	break;
			case 's': return border.s;	break;
			case 'e': return border.e;	break;
			case 'w': return border.w;	break;
		}
	}
	else if (info == "walls"){
		switch (setting){
			case 'n': return walls.n;	break;
			case 's': return walls.s;	break;
			case 'e': return walls.e;	break;
			case 'w': return walls.w;	break;
		}
	}
	else if (info == "backtrack"){
		switch (setting){
			case 'n': return backtrack.n;	break;
			case 's': return backtrack.s;	break;
			case 'e': return backtrack.e;	break;
			case 'w': return backtrack.w;	break;
		}
	}
	else if (info == "solution"){
		switch (setting){
			case 'n': return solution.n;	break;
			case 's': return solution.s;	break;
			case 'e': return solution.e;	break;
			case 'w': return solution.w;	break;
		}
	}
}

void walldestiny (vector<string> &, int, Cell **);

void pushbacker (Cell & current, int cur, vector<string> &list){

	ofstream write("walllist.txt", ios::app);
	ifstream read ("walllist.txt");
	string wall;

	if (current.border.n != 1 && current.walls.n != 0){
		write << cur << "n" << endl;
		read >> wall;
		list.push_back(wall);
	}
	if (current.border.s != 1 && current.walls.s != 0){
		write << cur << "s" << endl;
		read >> wall;
		list.push_back(wall);
	}
	if (current.border.e != 1 && current.walls.e != 0){
		write << cur << "e" << endl;
		read >> wall;
		list.push_back(wall);
	}
	if (current.border.w != 1 && current.walls.w != 0){
		write << cur << "w" << endl;
		read >> wall;
		list.push_back(wall);
	}
}

void walldestiny (vector<string> &list, int cur, Cell ** maze){
	
	ofstream store("order.txt", ios::app);

	int size = list.size();
	store << size << endl;
	
	int s = rand()% size;
	store << s << endl;
	
	string wall = list[s];
	store << wall << endl;

	int w = wall.size();
	store << w << endl;
	char num[3];
	for (int k = 0; k < w - 1; ++k)
		num[k] = wall[k];
	int numero = atoi (num);
	char wallo = wall[w-1];

	store << numero << " " << wallo;

	int neighbor;

	if (wallo == 'n')
		neighbor = cur - 20;
	else if (wallo == 's')
		neighbor = cur + 20;
	else if (wallo == 'e')
		neighbor = cur + 1;
	else if (wallo == 'w')
		neighbor = cur - 1;
	
	int r = getrow(neighbor);
	int c = getcol(neighbor);

	if (maze[r][c].Visited() == 0){
		list[s] = -2; // delete or neg value
	else if (maze[r][c].Visited() == 1){
		//delete the wall
		// 





}
/*
int* get_neighbors_with_walls (Cell ** all, int rc, int cc, int cur){

	int neighbors[4];
		neighbors[0] = cur - 20; //  N
		neighbors[1] = cur + 20; // S
		neighbors[2] = cur + 1; // E
		neighbors[3] = cur - 1; // W

	//ofstream haha ("neighbors.txt", ios::app);

	int final[5] = {0}; // final # of neighbors
	char dir[4] = { 'n', 's', 'e', 'w'}; // corresponds to neighbor array
	int c = 0;
	bool n[4]; // stores if neighbor will be in final array

	for(int k = 0; k < 4; ++k){

		if (neighbors[k] > 0 && neighbors[k] < 401){ // if neighbor in range

		int row = getrow(neighbors[k]); 
		int col = getcol(neighbors[k]);

		int counter = 0;

		// retreive if all walls  up

		if ( all[row][col].getDirection("walls", 'n') == 1)
			++counter;
		if ( all[row][col].getDirection("walls", 's') == 1)
			++counter;
		if ( all[row][col].getDirection("walls", 'e') == 1)
			++counter;
		if ( all[row][col].getDirection("walls", 'w') == 1)
			++counter;

		if (counter == 4){ // if all walls up
			n[k] = true;
		}
		else
			n[k] = false;
		}
		
		if (neighbors[k] < 0 || neighbors[k] > 400) // defensive programming against out of range neighbors
			n[k] = false;
		
		if (all[rc][cc].getDirection("border", dir[k]) == 1) // defensive programming against out of range neighbors due to border
			n[k] = false;

		if (n[k] == true){
			final[c+1] = neighbors[k]; // if bool is still true by the end of loop, store in final array
			//haha << final[c+1] << " ";
			++c;
		}
	}
	//haha << endl;
	//ofstream lala ("bool.txt", ios::app);
	//lala << rc << " " << cc << ": " << n[0] << " " << n[1] << " " << n[2] << " " << n[3] << endl;
	final[0] = c; // final[0] stores number of usable neighbors
	return final;
}

*/
#endif