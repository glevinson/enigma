#include<iostream>
#include<fstream>
#include<cstring>
#include"enigma.h"

using namespace std;



// main Function

int main(int argc, char** argv){

int number_rotors = (argc - 4);

int starting_positions[number_rotors];
load_positions(starting_positions, argv, argc);

rotor rotor_array[number_rotors];

for(int i = 0; i < number_rotors; i++){
  load_map(rotor_array[i].map, argv[i+3]); //argv[3] corresponds to the first rotor
  load_notches(rotor_array[i].notches, argv[i+3]);
  rotor_array[i].starting_pos = starting_positions[i];
}

// Example arguments tests:


// Rotor 1 map & notches

cout << endl << "Rotor 1 map: " << endl << endl;
for (int i= 0; i < 26; i++){
  for (int j = 0; j < 2; j++){
    cout << rotor_array[0].map[i][j] << " ";
  }
  cout << endl;
}


cout << endl << "Rotor 1 notches:" << endl << endl;
for(int i = 0; i < 26; i++){
  cout << rotor_array[0].notches[i] << " ";
}
cout << endl;

cout << endl << "Rotor 1 starting position: ";
cout << rotor_array[0].starting_pos << endl << endl;

// Rotor 2 map & notches

cout << endl << "Rotor 2 map: " << endl << endl;
for (int i= 0; i < 26; i++){
  for (int j = 0; j < 2; j++){
    cout << rotor_array[1].map[i][j] << " ";
  }
  cout << endl;
}

cout << endl << "Rotor 2 notches:" << endl << endl;
for(int i = 0; i < 26; i++){
  cout << rotor_array[1].notches[i] << " ";
}
cout << endl;

cout << endl << "Rotor 2 starting position: ";
cout << rotor_array[1].starting_pos << endl << endl;

// Rotor 3 map & notches

cout << endl << "Rotor 3 map: " << endl << endl;
for (int i= 0; i < 26; i++){
  for (int j = 0; j < 2; j++){
    cout << rotor_array[2].map[i][j] << " ";
  }
  cout << endl;
}

cout << endl << "Rotor 3 notches:" << endl << endl;
for(int i = 0; i < 26; i++){
  cout << rotor_array[2].notches[i] << " ";
}
cout << endl;

cout << endl << "Rotor 3 starting position: ";
cout << rotor_array[2].starting_pos << endl << endl;



return 0;
}




//can work out number of rotors from argc
//do a for loop to go throuhg each of the rotors

  // Checking starting_positions is well formed
/*
  for (int j = 0; j < number_rotors; j++){

  }

}*/
