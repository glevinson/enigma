#include"enigma.h"
#include<iostream>
#include<fstream>

using namespace std;

// Function currently working on:
/*
void check_notches(int starting_pos, int notches[26]){
  for (int j=0; j<= 25; j++){
    if (notches[j] == starting_pos){
      // tell next rotor to rotate...
    }
  }
}*/

// function definitions

void load_plugboard(int plugboard[13][2], char** argv){

ifstream in_stream;
int character;

in_stream.open(argv[1]);

if (in_stream.fail()){
  cout << "File could not be opened :(";
}

int row = 0;
int column = 0;

in_stream >> character;

while(!in_stream.eof())
{

  cout << character << " is in [row][column]: " << row << " " << column << endl;
  plugboard[row][column] = character;

  int col = column;

  // updating position
  if (col == 0){
    column ++; // then column = 1 which means it applies to next boolean expression
  }

  if (col == 1){
    row ++;
    column --;
  }
  in_stream >> character;
}

in_stream.close();

// Now row points to the first column & next row of the last connection
for (row; row < 13; row++){
  plugboard[row][0] = -1; // filling remaining spaces with minus 1; so wont be confused & used by plugboard
  plugboard[row][1] = -1;
}
}

void load_map(int map[26][2], char* argv_component){

  // index the first column
  for (int i = 0; i < 26; i++){
    map[i][0] = i;
  }

  ifstream in_stream;
  int digit;

  in_stream.open(argv_component);

  if (in_stream.fail()){
    cout << "File could not be opened :(";
  }

  int row = 0;

  in_stream >> digit;

  while(!in_stream.eof())
  {

    map[row][1] = digit;
    row++;

    in_stream >> digit;
  }

  in_stream.close();
}

void load_notches(int notches[26], char* argv_component){
  ifstream in_stream;
  int ignore; //storing rotors map in the variable ignore so dont accidentally get a mapping digit in our notches array
  int notch;

  in_stream.open(argv_component);

  if (in_stream.fail()){
    cout << "File could not be opened :(";
  }

  for(int count = 0; count < 26; count++){ // cycling through the first 26 components so we are just accessing the notches
      in_stream >> ignore;
    }

  int row = 0;
  in_stream >> notch;

    while(!in_stream.eof())
    {

      notches[row] = notch;
      row++;

      in_stream >> notch;
    }

    in_stream.close();

  for(row; row < 26; row++){
    notches[row] = -1;
  }
  }


void load_positions(int starting_positions[], char** argv, int argc){
  ifstream in_stream;
  int digit;

  // int number_rotors = (argc - 4); // - executable, plugboard, reflectors & rotor positions

  in_stream.open(argv[argc-1]); // opens final argument

  if (in_stream.fail()){
    cout << "File could not be opened :(";
  }

  int i = 0;

  in_stream >> digit;

  while(!in_stream.eof())
  {
    starting_positions[i] = digit;
    i++;

    in_stream >> digit;
  }

  in_stream.close();
  }

  void load_rotors_array(rotor rotor_array[],int argc, char** argv){

  int number_rotors = (argc - 4);

  int starting_positions[number_rotors];
  load_positions(starting_positions, argv, argc);

  for(int i = 0; i < number_rotors; i++){
    load_map(rotor_array[i].map, argv[i+3]); //argv[3] corresponds to the first rotor
    load_notches(rotor_array[i].notches, argv[i+3]);
    rotor_array[i].starting_pos = starting_positions[i];
  }

  // Example arguments tests:
  /*
  // Rotor 1 map & notches

  cout << endl << "Rotor 1 map: " << endl << endl;
  for (int i= 0; i < 26; i++){
    for (int j = 0; j < 2; j++){
      cout << rotor_array[0].map[i][j] << " ";
    }
    cout << endl;
  }


  cout << endl << "Rotor 1 notches:" << endl << endl;
  for(int i = 0; i < 26; i++){
    cout << rotor_array[0].notches[i] << " ";
  }
  cout << endl;

  cout << endl << "Rotor 1 starting position: ";
  cout << rotor_array[0].starting_pos << endl << endl;

  // Rotor 2 map & notches

  cout << endl << "Rotor 2 map: " << endl << endl;
  for (int i= 0; i < 26; i++){
    for (int j = 0; j < 2; j++){
      cout << rotor_array[1].map[i][j] << " ";
    }
    cout << endl;
  }

  cout << endl << "Rotor 2 notches:" << endl << endl;
  for(int i = 0; i < 26; i++){
    cout << rotor_array[1].notches[i] << " ";
  }
  cout << endl;

  cout << endl << "Rotor 2 starting position: ";
  cout << rotor_array[1].starting_pos << endl << endl;

  // Rotor 3 map & notches

  cout << endl << "Rotor 3 map: " << endl << endl;
  for (int i= 0; i < 26; i++){
    for (int j = 0; j < 2; j++){
      cout << rotor_array[2].map[i][j] << " ";
    }
    cout << endl;
  }

  cout << endl << "Rotor 3 notches:" << endl << endl;
  for(int i = 0; i < 26; i++){
    cout << rotor_array[2].notches[i] << " ";
  }
  cout << endl;

  cout << endl << "Rotor 3 starting position: ";
  cout << rotor_array[2].starting_pos << endl << endl;
  */
  }

  void check_notches(rotor rotors_array[], int rotor_n, int argc){ // will put in rotor_n = 0

  //rotates current rotor regardless of whether there's then a notch or not
  int starting_pos = rotors_array[rotor_n].starting_pos;

  cout << "Rotor " << rotor_n << " has starting position: " << starting_pos << endl << endl;

  if (starting_pos == 25){
    rotors_array[rotor_n].starting_pos = 0;
  }

  if (starting_pos != 25){
  rotors_array[rotor_n].starting_pos ++;
  }

  cout << "starting position updated to: " << rotors_array[rotor_n].starting_pos << endl << endl;

  // checks if new starting position is a notch; if so updates the next rotors starting position by 1
  for (int i = 0; i < 26; i++){
    if (rotors_array[rotor_n].starting_pos == rotors_array[rotor_n].notches[i]){
      cout << rotors_array[rotor_n].starting_pos << " is a notch so next rotate next rotor..." << endl << endl;

      int number_rotors = (argc - 4);

      // iterates through the remaining rotors
      if (rotor_n+1 < number_rotors){
      check_notches(rotors_array, (rotor_n+1), argc);
      }
    }
  }
  }

// Member function definitions:

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
  cout << "There is not a connection";
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