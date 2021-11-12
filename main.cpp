#include<iostream>
#include<fstream>
#include<cstring>
#include"enigma.h"

using namespace std;

// main Function

int main(int argc, char** argv){

plugboard plugboard;

int letter_to_digit(char letter);

char letter;
int digit;

// Enter letter
cout << "Please enter a letter: ";
cin >> letter;

// Update rotor positions
int number_rotors = (argc - 4);
rotor rotors_array[number_rotors];

load_rotors_array(rotors_array, argc, argv);
check_notches(rotors_array, 0, argc);

// Current runs round circuit
digit = letter_to_digit(letter);
cout << "which corresponds to the digit " << digit << endl << endl;

// Runs through plugboard (updates to outputted digit)
load_plugboard(plugboard.connections, argv);

digit = plugboard.check_connections(digit, plugboard.connections);
cout << endl << endl << "The digit outputted by the plugboard is: " << digit;

// Runs through rotors

for (int i = 0; i < number_rotors; i++){
  digit = rotors_array[i].mapping(rotors_array[i].starting_pos, rotors_array[i].map, digit);
}

cout << endl << endl << "The digit after the rotors mapping is: " << digit;



return 0;
}

int letter_to_digit(char letter){
  int number;
  number = letter;
  return (number - 'A');
}

void load_reflector(rotor reflector){
  reflector.mapping
}


// The above should be its own function that keeps repeating



// want to use the above function with i & i + 1, and use iterively
// but need it to start at 0 and then stop
