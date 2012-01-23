#ifndef _fileiop_h_
#define _fileiop_h_


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void showcreation(bool a)
{
	ofstream hisc;
	hisc.open ("storeseetings.dat");
	if(a == true)	
		hisc << 1 << endl;
	else
		hisc << 0 << endl;
	hisc.close();
}
int Returncreation()
{
  fstream realsc;
  realsc.open("storeseetings.dat");
  int holdscore;
  realsc >> holdscore;////gets the score
  realsc.close();
  return holdscore;
}

int Returnscore()
{
  fstream realsc;
  realsc.open("highscore.dat");
  string holdd;
  int holdscore;
  getline (realsc,holdd);
  getline (realsc,holdd,' ');
  
  realsc >> holdscore;////gets the score
  realsc.close();
  return holdscore;
}

string Returnname()
{
  ifstream hiscq;
  string holdname;
  hiscq.open ("temphighscore.dat");
  getline (hiscq,holdname);
  getline (hiscq,holdname,' '); //gets the name from the temp 
  hiscq.close();
  return holdname;
}

int readlevel()
{
  fstream realsc;
  realsc.open("temphighscore.dat");
  string holdd;
  int holdscore;
  getline (realsc,holdd);
  getline (realsc,holdd,' ');
  
  realsc >> holdscore;////gets the score
  realsc.close();
  return holdscore;
}

void addlevel()
{
	int oldlevel = readlevel();
	oldlevel++;
	string name = Returnname();
	ofstream hisc;
	hisc.open ("temphighscore.dat");
	hisc << "Temporary score, dont touch this!\n";
	hisc << name << " " << oldlevel << endl;
	hisc.close();
}


void writename(string name)
{
  ofstream hisc;
  hisc.open ("temphighscore.dat");
  hisc << "Temporary score, dont touch this!\n";
  hisc << name << " " << 1 << endl;
  hisc.close();
}

int writefinal(int score)
{
  ifstream hiscq;
  string holdname;
  string holdd;
  int holdscore;
  hiscq.open ("temphighscore.dat");
  getline (hiscq,holdname);
  getline (hiscq,holdname,' '); //gets the name from the temp 
  hiscq.close();

  fstream realsc;
  realsc.open("highscore.dat");
  getline (realsc,holdd);
  getline (realsc,holdd,' ');
  
  realsc >> holdscore;////gets the score
  realsc.close();
  if (score > holdscore)
  {
	  realsc.open("highscore.dat");
	  realsc << "Highscore for infinite mode: " << endl;
	  realsc << holdname << " " << score << "\n";
	  return 1;
  }
  else
	  return 0;
   
  
}
#endif