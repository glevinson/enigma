#include<iostream>
#include<fstream>
#include<cstring>
#include"enigma.h"

using namespace std;

int letter_to_digit(char letter);

int reflector_map(int map[26][2], int digit);

// main Function

int main(int argc, char** argv){

char letter;
int map[26][2];

cout << "Please input a letter: " << endl ;
cin >> letter;
int number = letter_to_digit(letter);

cout << endl << endl << "Which corresponds to number: " << number << endl << endl;

load_map(map, argv[2]);

cout << endl << reflector_map(map, number);




return 0;
}

int reflector_map(int map[26][2], int digit){
  cout << endl << "The inputted digit is: " << digit << endl;
  for(int i=0; i < 26; i++){
    if (map[i][0] == digit){
      cout << "The digit is mapped to: "
           << map[i][1] << endl << endl;
      return map[i][1];
    }
  }
}

int letter_to_digit(char letter){
  int digit;
  digit = letter - 'A';
  return digit;
}
