#include<iostream>
#include<fstream>
#include<cstring>
#include"enigma.h"

using namespace std;

// main Function

int main(int argc, char** argv){

int number_rotors = (argc - 4);
rotor rotors_array[number_rotors];

load_rotors_array(rotors_array, argc, argv);

check_notches(rotors_array, 0, argc);



return 0;
}


// The above should be its own function that keeps repeating



// want to use the above function with i & i + 1, and use iterively
// but need it to start at 0 and then stop
