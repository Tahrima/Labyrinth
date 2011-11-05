#ifndef _Cell_h_
#define _Cell_h_

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Cell{

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

	Direction border; // using objects of class Dimension as private data members
	Direction walls;
	Direction solution;
	Direction backtrack;

public:
	Cell ();
	void setCell(string, char, int);
	void setAllofCell(string, string);
	void display(); // function for testing 
	void drawMaze(int, int);
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

	int n = north;
	int s = south;
	int e = east;
	int w = west;
	
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

void Cell::display(){
	ofstream out("cell.txt", ios::app);
	out << border.n << " ";
	out << border.s << " ";
	out << border.e << " ";
	out << border.w << " ";
	out << endl;
}

void Cell::drawMaze(int length, int height){
}

#endif