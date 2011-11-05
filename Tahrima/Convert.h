#include <iostream>

using namespace std;


int getrow(int random){
	return random/20;
}

int getcol(int random){
	return random%20;
}

int getarr(int r, int c){
	return r * 20 + c;
}
