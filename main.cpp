#include<iostream>
#include<fstream>
#include<cstring>
#include"enigma.h"

using namespace std;

void load_rotors_array(rotor rotor_array[], int argc, char** argv);

// main Function

int main(int argc, char** argv){

int number_rotors = (argc - 4);
rotor rotor_array[number_rotors];

load_rotors_array(rotor_array, argc, argv);


return 0;
}




//can work out number of rotors from argc
//do a for loop to go throuhg each of the rotors

  // Checking starting_positions is well formed
/*
  for (int j = 0; j < number_rotors; j++){

  }

}*/
