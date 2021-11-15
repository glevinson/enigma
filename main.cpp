#include<iostream>
#include<fstream>
#include<cstring>
#include"enigma.h"

using namespace std;

// main Function

int main(int argc, char** argv){

char letter;
int reflector_map[26][2];
int number_rotors = (argc - 4);

cout << "Please input a letter: " << endl ;
cin >> letter;
int digit = letter_to_digit(letter);

cout << endl << endl << "Which corresponds to number: " << digit << endl << endl;

load_map(reflector_map, argv[2]);

cout << endl << reflector_mapping(reflector_map, digit);

rotor rotors_array[3];


load_rotors_array(rotors_array, argc, argv);

inverse_mapping(rotors_array, argc, digit);


return 0;
}

// We are going to inverse the map







/*
for (int rotor_n = 0; rotor_n < number_rotors; rotor_n++){
  cout << "Starting Positions: ";
  cout << rotors_array[(number_rotors-rotor_n)].starting_pos << " ";
}


for (int rotor_n = 0; rotor_n < number_rotors; rotor_n++){
  for (int i = 0; i < 26; i++){
    rotors_array[(number_rotors-rotor_n)].map[i][0] = rotors_array[(number_rotors-rotor_n)].map[i][1];
    rotors_array[(number_rotors-rotor_n)].map[i][1] = i;
  }
  cout << endl << endl << "We are in rotor: " << (number_rotors-rotor_n) << " Which has map: " << endl;
  for (int j = 0; j < 26; j++){
    cout << endl;
    cout << rotors_array[(number_rotors-rotor_n)].map[j][0] << " ";
    cout << rotors_array[(number_rotors-rotor_n)].map[j][1];
  }


  digit = rotors_array[(number_rotors-rotor_n)].mapping(rotors_array[(number_rotors-rotor_n)].starting_pos, rotors_array[(number_rotors-rotor_n)].map, digit);
  cout << endl << endl << "The outputted digit of rotor " << (number_rotors-rotor_n) << " is: "<< digit;
}

*/
