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

class plugboard{
  public:

    // data members
    int connections[13][2]; // max number of connections is 13

    // member function definitions
    int check_connections(int inputted_letter, int connections[13][2]);
};


int main(int n_arg, char* v_arg[]){

  plugboard plugboard;

  plugboard.connections[0][0] = 23;
  plugboard.connections[0][1] = 6;
  plugboard.connections[1][0] = 9;
  plugboard.connections[1][1] = 5;
  plugboard.connections[2][0] = 21;
  plugboard.connections[2][1] = 0;
  plugboard.connections[3][0] = 18;
  plugboard.connections[3][1] = 8;
  plugboard.connections[4][0] = 1;
  plugboard.connections[4][1] = 11;
  plugboard.connections[5][0] = 24;
  plugboard.connections[5][1] = 4;
  plugboard.connections[6][0] = 14;
  plugboard.connections[6][1] = 20;
  plugboard.connections[7][0] = 12;
  plugboard.connections[7][1] = 3;
  plugboard.connections[8][0] = 10;
  plugboard.connections[8][1] = 25;
  plugboard.connections[9][0] = 7;
  plugboard.connections[9][1] = 17;


  for(int i = 10; i<= 12; i++){
    plugboard.connections[i][0] = 0;
    plugboard.connections[i][1] = 0;
  }

  plugboard.check_connections(23, plugboard.connections);
  plugboard.check_connections(5, plugboard.connections);
  plugboard.check_connections(21, plugboard.connections);
  plugboard.check_connections(18, plugboard.connections);
  plugboard.check_connections(11, plugboard.connections);
  plugboard.check_connections(24, plugboard.connections);
  plugboard.check_connections(20, plugboard.connections);
  plugboard.check_connections(12, plugboard.connections);
  plugboard.check_connections(10, plugboard.connections);
  plugboard.check_connections(17, plugboard.connections);

  return 0;
}

// Function currently working on:

void check_notches(int starting_pos, int notches[26]){
  for (int j=0; j<= 25; j++){
    if (notches[j] == starting_pos){
      // tell next rotor to rotate...
    }
  }
}

// Function definitions:

int plugboard::check_connections(int inputted_letter, int connections[13][2]){
  cout << endl << "The inputted letter is: " << inputted_letter << endl;
  for(int i=0; i <= 12; i++){
    if (connections[i][0] == inputted_letter){
      cout << "There is a connection in the first column; connected to: "
           << connections[i][1] << endl << endl;
      return connections[i][1];
    }
    if (connections[i][1] == inputted_letter){
      cout << "There is a connection in the second column; connected to: "
           << connections[i][0] << endl << endl;
      return connections[i][0];
    }
  }
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
