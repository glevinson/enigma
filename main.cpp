#include<iostream>
#include<fstream>
#include<cstring>
#include"enigma.h"


using namespace std;

string input_string(string str);

void encrypt_string(string str, enigma enigma, int argc, char** argv);

// main Function

int main(int argc, char** argv){

enigma enigma;
string string;

string = input_string(string);

try
{
  encrypt_string(string, enigma, argc, argv);
}

// catching any error codes
catch (int error){
  cout << endl << "error code is: " << error << endl;
  return error;
}

return 0;
}
