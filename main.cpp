#include<iostream>
#include<fstream>
#include<cstring>


using namespace std;

/*enum letters{A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z};*/

class rotor{
  public:

      // data members
      int starting_pos; //that just needs to be a integer, as tells you which letter at 12 o'clock
      int notches[26]; //make dynamic
      int map[26][2];

      // member function declarations
      int mapping(int starting_pos, int map[26][2], int letter_dig); //does letter_dig also have to be a data memeber?
      // i.e. can you only use data members of a class in the member function?
};

int main(int n_arg, char* v_arg[]){
  cout << endl << endl;

  rotor rotor;

  rotor.starting_pos = 5;
  int digit = 9;

  for(int i=0; i<=25; i++){
    rotor.map[i][0] = (i);
  }

  for(int j=0; j<25; j++){
    rotor.map[j][1] = (j+1);
  }

  rotor.map[25][1] = 0;

  cout << endl;

  for(int i=0; i<26; i++){
    cout << rotor.map[i][1];
  }

  rotor.mapping(rotor.starting_pos, rotor.map, digit);

  return 0;
}



int rotor::mapping(int starting_pos, int map[26][2], int inputted_digit){
  // the inputted digit is in absolute form (i.e. not taking into account rotation)
  int rotation_transformation_1;
  int rotation_transformation_2;
  int mapped_digit;
  cout << endl << "Starting position (digit at 12 o'clock): " << starting_pos<<endl;

  cout << "Inputted (absolute) digit is: " << inputted_digit<<endl;
  // factoring in rotation to the inputted_digit
  // transforming inputted digit (absolute form) to corresponding relative form
  rotation_transformation_1 = inputted_digit + starting_pos; //takes into account rotation

  if (rotation_transformation_1 >= 26){
    rotation_transformation_1 = rotation_transformation_1 - 26;
  }
  cout << "Relative version is: " << rotation_transformation_1<<endl;

  // mapping the relative digit
  mapped_digit = map[rotation_transformation_1][1];
  cout << "Which has been mapped to: " << mapped_digit << endl;

  // removing affects of rotation
  // transforming relative form to corresponding absolute form
  rotation_transformation_2 = mapped_digit - starting_pos;

  if (rotation_transformation_2 < 0){
    rotation_transformation_2 = rotation_transformation_2 + 26;
  }

  cout << "Absolute version of this is: " << rotation_transformation_2 << endl << endl;
  return rotation_transformation_2;
}
