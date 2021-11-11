#include<iostream>
#include<fstream>
#include<cstring>
#include"enigma.h"

using namespace std;

// main Function

int main(int argc, char** argv){

int notches[26];

load_notches(notches, argv[5]);

for (int i=0; i<26; i++){
  cout << notches[i] << " ";
}

return 0;
}

//can work out number of rotors from argc
//do a for loop to go throuhg each of the rotors
