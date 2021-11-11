#include<iostream>
#include<fstream>
#include<cstring>
#include"enigma.h"


using namespace std;

// focussing on reading in teh data

// main Function

int main(int argc, char** argv){

cout << endl << endl << "Command line arguments: " << endl;

for (int i=0; i < argc; i++){
  cout << "Argument " << i << ": " << argv[i] << endl;
}

cout << endl;
cout << argv << endl; // memory address of argv*
cout << *argv << endl; // memory address of argv**
cout << **argv << endl; // character stored
cout << endl << endl;


  return 0;
}
