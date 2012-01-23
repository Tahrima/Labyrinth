#ifndef _Prim_h_
#define _Prim_h_

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Convert.h"
#include <algorithm>
#include "DarkGDK.h"
#include <sstream>
#include "FirstDepth.h"
#include "create.h"
#include "fileiop.h"

using namespace std;

class PrimCell : public Cell
{
friend void pushbacker(Cell&, int, vector<string> *, int);
friend void walldestiny(vector<string> *, int);

private:
	int visited;
	void DirectionSet(string, string);
	
public:
	int Visited();
	int rowprim;
	int colprim;
	void setVisited(int a){visited = a;}
	PrimCell();
	PrimCell(string, string);
	PrimCell(int);
};

int PrimCell::Visited(){
	return visited;
}

PrimCell::PrimCell(){
	border.setAll(0,0,0,0);
	walls.setAll(1,1,1,1);
	backtrack.setAll(0,0,0,0);
	solution.setAll(0,0,0,0);
	visited = 0;
}

PrimCell::PrimCell(string info, string setting){
	DirectionSet(info, setting);
}

PrimCell::PrimCell(int a)
: visited(a)
{}

void PrimCell::DirectionSet(string info, string setting){
	char north = setting.at(0);
	char south = setting.at(1);
	char east = setting.at(2);
	char west = setting.at(3);

	int n = north - 48;
	int s = south - 48;
	int e = east - 48;
	int w = west - 48;

	if (info == "border")
		border.setAll(n,s,e,w);
	else if (info == "walls")
		walls.setAll(n,s,e,w);
	else if (info == "backtrack")
		backtrack.setAll(n,s,e,w);
	else if (info == "solution")
		solution.setAll(n,s,e,w);
}

void pinitialize (int r, int c, PrimCell ** pmaze){
	for (int k = 1; k <= r; ++k){  // sets E and W borders for maze
		pmaze[k][1].setCell("border", 'w', 1);
		pmaze[k][20].setCell("border",'e', 1);
	}

	for (int l = 1; l <= c; ++l){ // sets N and S borders for maze
		pmaze[1][l].setCell("border", 'n', 1);
		pmaze[20][l].setCell("border", 's', 1);
	}
}

//int decide = 1;

void pushbacker (PrimCell & current, int cur, vector<string> &list, int count, int r, int c){


	current.setVisited(1);
	current.rowprim = r;
	current.colprim = c;

	if(Returncreation() == 1)
	{
	dbLoadImage("bakround.png",4998);
	dbSprite(4998,0,0,4998);
	dbSizeSprite ( 4998, 640, 500 );
	dbSync();
	for(int i = 0; i < 4000; i++)
		dbSetSpritePriority(i,5);
	dbSetSpritePriority(4998,2);
	dbSync();
	createDelete(getarr(r,c));
	}
	else
	{}


	//remove("temp.txt");
	//ofstream write("temp.txt", ios::app);
	stringstream walln, walls, walle, wallw;
	string final;

	if (current.border.n != 1 && current.walls.n != 0){
		walln << cur;
		final = walln.str() + "n";
		list.push_back(final);
	}
	if (current.border.s != 1 && current.walls.s != 0){
		walls << cur;
		final = walls.str() + "s";
		list.push_back(final);
	}
	if (current.border.e != 1 && current.walls.e != 0){
		walle << cur;
		final = walle.str() + "e";
		list.push_back(final);
	}
	if (current.border.w != 1 && current.walls.w != 0){
		wallw << cur;
		final = wallw.str() + "w";
		list.push_back(final);
	}


	stringstream num;
	num << count;
	string cool = num.str();
	string text = "walllist" + cool + ".txt";
	//remove("walllist.txt");

	random_shuffle(list.begin(), list.end());

	ofstream w(text.c_str());
	for (int i = 0; i < list.size(); ++i)
		w << list[i] << endl;

}

void walldestiny (vector<string> &list, PrimCell ** pmaze){

	int count = 1;
	string wall;
	char num[3];
	ofstream store("order.txt", ios::app);
	//for (int x = 0; x < 600; ++x)
	while(!list.empty())
	{
		wall.clear();
		memset(num, 0, sizeof(num));

        int size = list.size(); // gets size of wall list
		store << "SIZE = " << size << endl;
        int s = (rand() % size); // gets random # from wall list
		store << "RAND = " << s << endl;

        wall = list[s]; // gets that string from wall list[random #]
        store << wall << endl;

        int w = wall.size(); // parsing of string to int and char
        //store << w << endl;
        for (int k = 0; k < w - 1; ++k)
            num[k] = wall[k];
        int numero = atoi (num);
        char wallo = wall[w-1];

//NOW THE RANDOM WALL HAS BEEN SEPARATED INTO NUMBER(numero) AND DIRECTION(wallo)

		int rand_row = getrow(numero);
		int rand_col = getcol(numero);

        int neighbor; // finds the neighbor cell number depending on char from the string

		if (wallo == 'n' && pmaze[rand_row][rand_col].border.n != 1)
            neighbor = numero - 20;
        else if (wallo == 's' && pmaze[rand_row][rand_col].border.s != 1)
            neighbor = numero + 20;
        else if (wallo == 'e' && pmaze[rand_row][rand_col].border.e != 1)
            neighbor = numero + 1;
        else if (wallo == 'w' && pmaze[rand_row][rand_col].border.w != 1)
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

		ofstream wr("deleted.txt", ios::app);

        if (pmaze[r][c].Visited() == 0){//checks if neighboring cell is NOT visited
				

			if (wallo == 'n'){
			  int send = (20 * (rand_row - 1)) + rand_col + 1000; // wall/line deletion
			  if(Returncreation() == 0)
			  dbDeleteSprite((20 * (rand_row - 1)) + rand_col + 1000);
			  else if(Returncreation() == 1)
			  createDelete(send);
				wr << wall <<endl;}
			else if (wallo == 's'){
               int send = (20 * (rand_row)) + rand_col + 1000;
			   	if(Returncreation() == 0)
			   dbDeleteSprite((20 * (rand_row)) + rand_col + 1000);
				else if(Returncreation() == 1)
			   createDelete(send);
				wr << wall <<endl;}
			else if (wallo == 'e'){
                int send = (21 * (rand_row - 1)) + rand_col + 1 + 500;
				if(Returncreation() == 0)
				dbDeleteSprite((21 * (rand_row - 1)) + rand_col + 1 + 500);
				else if(Returncreation() == 1)
				createDelete(send);
				wr << wall <<endl;}
			else if (wallo == 'w'){
               int send = (21 * (rand_row - 1)) + rand_col + 500;
			   if(Returncreation() == 0)
				dbDeleteSprite((21 * (rand_row - 1)) + rand_col + 500);
			   else if(Returncreation() == 1)
				createDelete(send);
				wr << wall <<endl;}

			pmaze[r][c].setCell("walls", opposite, 0);
            pmaze[rand_row][rand_col].setCell("walls", wallo, 0);

			int a= r,b = c;
			pushbacker(pmaze[r][c], neighbor, list, count,a,b);

            ++count;

			vector<string>::iterator check;
            check = find(list.begin(), list.end()-1, nstring);
			
            if(*check == nstring)
            {
                 list.erase(remove(list.begin(), list.end(), nstring), list.end()); // REMOVE NEIGHBOR WALL FROM WALL LIST
            }
			list.erase(remove(list.begin(), list.end(), wall), list.end());

	
            //list.erase(remove(list.begin(), list.end(), nstring), list.end()); // REMOVE NEIGHBOR WALL FROM WALL LIST

        }
        else if (pmaze[r][c].Visited() == 1){//checks if neighboring cells IS visited

			vector<string>::iterator check;
            check = find(list.begin(), list.end()-1, nstring);

            if(*check == nstring)
            {
                 list.erase(remove(list.begin(), list.end(), nstring), list.end()); // REMOVE NEIGHBOR WALL FROM WALL LIST
            }
			list.erase(remove(list.begin(), list.end(), wall), list.end());
            //list.erase(remove(list.begin(), list.end(), nstring), list.end()); // REMOVE NEIGHBOR WALL FROM WALL LIST
		}
    }

	if(Returncreation() ==0)
	{
		for(int i = 1; i < 401; ++i)
			dbDeleteSprite(i);
	}


}

#endif