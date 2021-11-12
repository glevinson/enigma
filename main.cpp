#include<iostream>
#include<fstream>
#include<cstring>
#include"enigma.h"

using namespace std;

void load_rotors_array(rotor rotor_array[], int argc, char** argv);

void check_notches(rotor rotors_array[], int rotor_n);

// main Function

int main(int argc, char** argv){

int number_rotors = (argc - 4);
rotor rotors_array[number_rotors];

load_rotors_array(rotors_array, argc, argv);

check_notches(rotors_array, 0);



return 0;
}


void check_notches(rotor rotors_array[], int rotor_n){ // will put in rotor_n = 0

//rotates current rotor regardless of whether there's then a notch or not
int starting_pos = rotors_array[rotor_n].starting_pos;

if (starting_pos == 25){
  rotors_array[rotor_n].starting_pos = 0;
}

if (starting_pos != 25){
rotors_array[rotor_n].starting_pos ++;
}

// checks if new starting position is a notch; if so updates the next rotors starting position by 1
for (int i = 0; i < 26; i++){
  if (rotors_array[rotor_n].starting_pos == rotors_array[rotor_n].notches[i]){
    cout << "Rotor " << rotor_n << " has starting position ( ";
    cout << rotors_array[rotor_n].starting_pos << " ) is a notch" << endl << endl;


    int next_rotor_starting_pos = rotors_array[rotor_n+1].starting_pos;

    if (next_rotor_starting_pos == 25){ // if match but next rotors starting_pos = 25, then moves to 1
      rotors_array[rotor_n + 1].starting_pos = 0;
    }
    if (next_rotor_starting_pos != 25){
      rotors_array[rotor_n + 1].starting_pos ++; // o.w. next rotor position just incremented by 1
    }

    cout << "Next rotor starting position is: " << rotors_array[rotor_n + 1].starting_pos;

    check_notches(rotors_array, (rotor_n+1));
  }
}

// The above should be its own function that keeps repeating

}


// want to use the above function with i & i + 1, and use iterively
// but need it to start at 0 and then stop
