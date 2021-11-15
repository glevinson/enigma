#include<iostream>
#include<fstream>
#include<cstring>
#include"enigma.h"


using namespace std;



// main Function

int main(int argc, char** argv){

encrypt(argc, argv);

return 0;
}

char digit_to_letter(int digit){
  char letter;
  letter = digit + 'A';
  return letter;
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
