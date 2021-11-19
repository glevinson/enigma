#include<iostream>
#include<fstream>
#include<cstring>
#include"enigma.h"


using namespace std;

string input_string();

void encrypt_string(string str, enigma enigma, int argc, char** argv);

// main Function

int main(int argc, char** argv){

enigma enigma;

return enigma.welcome(argc, argv);
}
