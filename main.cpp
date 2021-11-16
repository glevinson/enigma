#include<iostream>
#include<fstream>
#include<cstring>
#include"enigma.h"


using namespace std;

string input_string(string string);

string encrypt_string(string string, int argc, char** argv);

// main Function

int main(int argc, char** argv){

bool error = false;

//cout << encrypt('A', argc, argv);

string string;

string = input_string(string);

encrypt_string(string, argc, argv);

return 0;
}

string input_string(string string){
  cin >> string;
  cout << "the string is " << string << "   ";
  return string;
}

string encrypt_string(string str, int argc, char** argv){
  cout << "the string in encrypt_string is " << str << "   ";

  int string_length = str.size();

  cout << endl << endl << "The string length is: " << string_length << endl << endl;

  for (int letter_n = 0; letter_n < string_length; letter_n++){

    char inputted_letter = str[letter_n];
    cout << "inputted letter" << inputted_letter;
    char outputted_letter;
    int ascii;

    ascii = inputted_letter;
    cout << "ascii number " << ascii << endl << endl;

    /*if (ascii == 9 || ascii == 13 || ascii == 32){
    }*/

    if (ascii < 9){
      cerr << "INVALID_INPUT_CHARACTER";
    }
    if (ascii > 9 && ascii < 13){
      cerr << "INVALID_INPUT_CHARACTER";
    }

    if (ascii > 13 && ascii < 32){
      cerr << "INVALID_INPUT_CHARACTER";
    }

    if (ascii > 32 && ascii < 65){
      cerr << "INVALID_INPUT_CHARACTER";
    }

    if (ascii > 90){
      cerr << "INVALID_INPUT_CHARACTER";
    }

    if (ascii == 9 || ascii == 13 || ascii == 32){
      str[letter_n] = ' ';
    }

    if (ascii != 9 && ascii != 13 && ascii != 32){ // Keep asking for input letter if input a letter (tab, return, space)
      outputted_letter = encrypt(inputted_letter, argc, argv);
      str[letter_n] = outputted_letter;
    }
  }
  return str;
}
