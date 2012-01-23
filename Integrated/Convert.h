#ifndef _Convert_h_
#define _Convert_h_

#include <iostream>

using namespace std;

int getrow(int random){
	if (random%20 != 0)
		return random/20 + 1;
	else
		return random/20;
}

int getcol(int random){
	if (random%20 != 0)
		return random%20;
	else 
		return 20;
}

int getarr(int r, int c){
	r = r - 1;
	return r * 20 + c;
}

#endif