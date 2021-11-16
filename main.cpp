#include<iostream>
#include<fstream>
#include<cstring>
#include"enigma.h"


using namespace std;



// main Function

int main(int argc, char** argv){

bool error = false;

/*class plugboard plugboard;

int map[13][2];

load_reflector(map, argv[2]);*/

do {
  encrypt(argc, argv);
}
while (error == false);



return 0;
}
