#ifndef _Cell_h_
#define _Cell_h_

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Cell{
friend void pushbacker(Cell&, int, vector<string>);
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

void pushbacker (Cell & current, int cur, vector<string> list){
	if (current.border.n != 1 && current.walls.n != 0)
		list.push_back(cur + "n");	
	if (current.border.s != 1 && current.walls.s != 0)
		list.push_back(cur + "s");
	if (current.border.e != 1 && current.walls.e != 0)
		list.push_back(cur + "e");
	if (current.border.w != 1 && current.walls.w != 0)
		list.push_back(cur + "w");
}

void walldestiny (vector<string> list, int cur){
	
	//ofstream store("order.txt", ios::app);

	//int w = rand() % list.size() + 1;
	/*string wall = list[w];

	store << wall << endl;

	int s = wall.size();
	char num[3];
	for (int k = 0; k < s - 1; ++k)
		num[k] = wall[k];
	int numero = atoi (num);
	char wallo = wall[s];

	store << numero << " " << wallo;*/
}
		
	
	
	/*int neighbors[4];
		neighbors[0] = cur - 20; //  N
		neighbors[1] = cur + 20; // S
		neighbors[2] = cur + 1; // E
		neighbors[3] = cur - 1; // W*/

#endif