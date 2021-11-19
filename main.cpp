#include<iostream>
#include<fstream>
#include"enigma.h"


using namespace std;

// Prompts user to input a string
string input_string();
// Encrypts inputted string
void encrypt_string(string str, Enigma enigma, int argc, char** argv);

// main Function

int main(int argc, char** argv){

Enigma enigma;

return enigma.welcome(argc, argv);
}
