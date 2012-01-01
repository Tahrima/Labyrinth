#ifndef _Cell_h_
#define _Cell_h_

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Convert.h"
#include <algorithm>
#include "DarkGDK.h"
#include <sstream>

using namespace std;

class Cell{
friend void pushbacker(Cell&, int, vector<string> *, int);
friend void walldestiny(vector<string> *, int);
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
	int count;
	Cell ();
	void setCell(string, char, int);
	void setAllofCell(string, string);
	int getDirection(string, char);
	int Visited();
	void setVisited(int a){visited = a;}

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
	visited = 0;
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

//void walldestiny (vector<string> &, int, Cell **);

void pushbacker (Cell & current, int cur, vector<string> &list, int count){
	
	remove("temp.txt");
	ofstream write("temp.txt", ios::app);
	stringstream walln, walls, walle, wallw;
	string final;

	if (current.border.n != 1 && current.walls.n != 0){
		walln << cur;
		final = walln.str() + "n";
		write << final << endl;
		list.push_back(final);
	}
	if (current.border.s != 1 && current.walls.s != 0){
		walls << cur;
		final = walls.str() + "s";
		write << final << endl;
		list.push_back(final);
	}
	if (current.border.e != 1 && current.walls.e != 0){
		walle << cur;
		final = walle.str() + "e";
		write << final << endl;
		list.push_back(final);
	}
	if (current.border.w != 1 && current.walls.w != 0){
		wallw << cur;
		final = wallw.str() + "w";
		write << final << endl;
		list.push_back(final);
	}

	current.setVisited(1);

	stringstream num;
	num << count;
	string cool = num.str();
	string text = "walllist" + cool + ".txt";
	//remove("walllist.txt");
	
	ofstream w(text.c_str());
	for (int i = 0; i < list.size(); ++i)
		w << list[i] << endl;

}

void walldestiny (vector<string> &list, Cell ** maze){

	int count = 1;

	for (int x = 0; x < 300; ++x){
    
        ofstream store("order.txt", ios::app);

        int size = list.size(); // gets size of wall list 
		store << "SIZE = " << size << endl;
        int s = (rand() % size) + 1;  // gets random # from wall list
		store << "RAND = " << s << endl;

        string wall = list[s-1]; // gets that string from wall list[random #]
        store << wall << endl;

        int w = wall.size(); // parsing of string to int and char
        //store << w << endl;
        char num[3];
        for (int k = 0; k < w - 1; ++k)
            num[k] = wall[k];
        int numero = atoi (num);
        char wallo = wall[w-1];
		
		//NOW THE RANDOM WALL HAS BEEN SEPARATED INTO NUMBER(numero) AND DIRECTION(wallo)

		int rand_row = getrow(numero);
		int rand_col = getcol(numero);

        int neighbor;   // finds the neighbor cell number depending on char from the string

		if (wallo == 'n' && maze[rand_row][rand_col].border.n != 1)
            neighbor = numero - 20;
        else if (wallo == 's' && maze[rand_row][rand_col].border.s != 1)
            neighbor = numero + 20;
        else if (wallo == 'e' && maze[rand_row][rand_col].border.e != 1)
            neighbor = numero + 1;
        else if (wallo == 'w' && maze[rand_row][rand_col].border.w != 1)
            neighbor = numero - 1;
        
        int r = getrow(neighbor);
        int c = getcol(neighbor);

        char temp[5];
        itoa(neighbor, temp, 10);

        string nstring = temp;
        char opposite;
        
        if(wallo == 'n'){
            nstring.append("s");
            opposite = 's';
        }
        else if(wallo == 's'){
            nstring.append("n");
            opposite = 'n';
        }
        else if(wallo == 'e'){
            nstring.append("w");
            opposite = 'w';
        }
        else if(wallo == 'w'){
            nstring.append("e");
            opposite = 'e';
        }
        
        //WE NOW HAVE THE DUPLICATE WALL OF THE RANDOM WALL IN 'nstring'
        //NOW WE MUST REMOVE 'nstring' ALONG WITH THE RANDOM WALL FROM THE WALL LIST

        if (maze[r][c].Visited() == 0){//checks if neighboring cell is NOT visited

            if (wallo == 'n')
                dbDeleteSprite( (20 * (rand_row - 1)) + rand_col + 1000); // wall/line deletion
            else if (wallo == 's')
                dbDeleteSprite( (20 * (rand_row)) + rand_col + 1000);
            else if (wallo == 'e')
                dbDeleteSprite( (21 * (rand_row - 1)) + rand_col + 1 + 500);
            else if (wallo == 'w')
                dbDeleteSprite( (21 * (rand_row - 1)) + rand_col + 500);

			maze[r][c].setCell("walls", opposite, 0);
            maze[rand_row][rand_col].setCell("walls", wallo, 0);


            ++count;

			vector<string>::iterator check;
            check = find(list.begin(), list.end()-1, nstring);

            if(*check == nstring)
            {
                 list.erase(remove(list.begin(), list.end(), nstring), list.end()); // REMOVE NEIGHBOR WALL FROM WALL LIST
            }
			list.erase(remove(list.begin(), list.end(), wall), list.end()); 

			pushbacker(maze[r][c], neighbor, list, count);
            //list.erase(remove(list.begin(), list.end(), nstring), list.end()); // REMOVE NEIGHBOR WALL FROM WALL LIST

        }
        else if (maze[r][c].Visited() == 1){//checks if neighboring cells IS visited

			vector<string>::iterator check;
            check = find(list.begin(), list.end()-1, nstring);

            if(*check == nstring)
            {
                 list.erase(remove(list.begin(), list.end(), nstring), list.end()); // REMOVE NEIGHBOR WALL FROM WALL LIST
            }
			list.erase(remove(list.begin(), list.end(), wall), list.end()); 
            //list.erase(remove(list.begin(), list.end(), nstring), list.end()); // REMOVE NEIGHBOR WALL FROM WALL LIST
        }
		
		//dbWait(1000);
    }
} 

#endif