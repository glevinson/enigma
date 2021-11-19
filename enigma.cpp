#include"enigma.h"
#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

// Rotor class member functions:

void Rotor::load_positions(int starting_positions[], char** argv, int argc){

  ifstream in_stream;
  int digit;
  int number_rotors = (argc - 4);

  // opens instream to final argument (rotor starting positions)
  in_stream.open(argv[argc-1]);

  // error if fails
  if (in_stream.fail()){
    cerr << "ERROR_OPENING_CONFIGURATION_FILE";
    throw 11;
  }

  // counts number of starting positions in file
  int count = 0;

  in_stream >> digit;

  while(!in_stream.eof())
  {
    // non numeric character if instream fails after file opened
    if (in_stream.fail()){
      cerr << "NON_NUMERIC_CHARACTER 1";
      throw 4;
    }

    // filling starting positions array with inputted digits
    starting_positions[count] = digit;
    count++;

    in_stream >> digit;

  }

  // error if there are rotors but not correct amount of starting positions
  if (number_rotors != 0 && count != number_rotors){
    cerr << "NO_ROTOR_STARTING_POSITION";
    throw 8;
  }

  in_stream.close();
  }

void Reflector::load_reflector(int map[13][2], char* argv_component){

  ifstream in_stream;
  int digit, count, count_2;
  int row, column;

  in_stream.open(argv_component);

  // error if file does not open
  if (in_stream.fail()){
    cerr << "ERROR_OPENING_CONFIGURATION_FILE";
    throw 11;
  }

  row = 0;
  column = 0;
  // counts number of digits in input stream
  count = 0;

  in_stream >> digit;

  while(!in_stream.eof())
  {

    // non numeric character if instream fails after file opened
    if (in_stream.fail()){
      cerr << "Non-numeric character in reflector file reflector.rf";
      throw 4;
  }

  // error if digit not between 0 & 25
  if ( digit < 0 || digit > 25 ){
    cerr << "INVALID_INDEX";
    throw 3;
  }

  count++;

  // save digit into map array
  map[row][column] = digit;

  // update map component position
  // iterates along rows & when at end moves to start of row below
  int col = column;

  if (col == 0){
    column ++;
  }

  if (col == 1){
    row ++;
    column --;
  }
  in_stream >> digit;
  }

  in_stream.close();

  // error if not exactly 26 digits in input stream
  if (count != 26){
    cerr << "Insufficient number of mappings in reflector file: reflector.rf";
    throw 10;
  }

  // checking if a number maps to itself or appears more than once

  count_2 = 0;
  // iterates through all the numbers (0 - 25)
  for (int number = 0; number < 26; number++){
    // iterates through every row
    for (int j = 0; j < 13; j++){
      // error if a digit maps to itself
      if (map[j][0] == map[j][1]){
        cerr << "INVALID_REFLECTOR_MAPPING";
        throw 9;
    }
    // If number appears in a connection, count it
    if (map[j][0] == number || map[j][1] == number){
      count_2++;
    }
  }
  // error if number appears more than once in a connection
  if (count_2 > 1){
    cerr << "INVALID_REFLECTOR_MAPPING";
    throw 9;
  }
  count_2 = 0;
}
}

void Plugboard::load_plugboard(int plugboard[13][2], char* argv_component){

  ifstream in_stream;
  int digit, row, column;

  in_stream.open(argv_component);

  // error if plugboard file fails to open
  if (in_stream.fail()){
    cerr << "ERROR_OPENING_CONFIGURATION_FILE";
    throw 11;
  }

  row = 0;
  column = 0;
  int i = 0;

  in_stream >> digit;

  while(!in_stream.eof())
  {

    // non numeric character if instream fails after file opened
    if (in_stream.fail()){
      cerr << "Non-numeric character in plugboard file plugboard.pb";
      throw 4;
    }

    // error if digit is not between 0 & 25
    if (digit < 0 || digit > 25){
      cerr << "INVALID_INDEX";
      throw 3;
    }

    // enters digit into plugboard array
    plugboard[row][column] = digit;
    i++;

    int col = column;

    // updating position
    // if in first collumn, move to the second
    if (col == 0){
      column ++;
    }

    // if in second column, move to first column of row below
    if (col == 1){
      row ++;
      column --;
    }
    in_stream >> digit;

  }

  in_stream.close();

  // error if plugboard parameters not even
  if (i % 2 != 0){
    cerr << "Incorrect number of parameters in plugboard file plugboard.pb";
    throw 6;
  }

  // error if digit maps to itself or appears more than once
  int count = 0;
  // iterates through all the numbers (0 - 25)
  for (int number = 0; number < 26; number++){
    // iterates through every row
    for (int j = 0; j < row; j++){
      // error if a digit maps to itself
      if (plugboard[j][0] == plugboard[j][1]){
        cerr << "IMPOSSIBLE_PLUGBOARD_CONFIGURATION";
        throw 5;
      }
      // counting each time a number appears in a row
      if (plugboard[j][0] == number || plugboard[j][1] == number){
        count++;
      }
    }

    // error if number appears in more than one connection (row)
    if (count > 1){
      cerr << "IMPOSSIBLE_PLUGBOARD_CONFIGURATION";
      throw 5;
    }
    count = 0;
  }

  // Fill uninitalised array spaces with -1 so cannot accidentally be used
  for (; row < 13; row++){
    plugboard[row][0] = -1;
    plugboard[row][1] = -1;
  }
}


void Rotor::load_map(int map[26][2], char* argv_component){

  // index map array's first column
  for (int i = 0; i < 26; i++){
    map[i][0] = i;
  }

  ifstream in_stream;
  int digit, row;

  in_stream.open(argv_component);

  // error if rotor configuration file doesn't open
  if (in_stream.fail()){
    cerr << "ERROR_OPENING_CONFIGURATION_FILE";
    throw 11;
  }

  row = 0;

  in_stream >> digit;

  while(!in_stream.eof())
  {

    // non numeric character if instream fails after file opened
    if (in_stream.fail()){
      cerr << "NON_NUMERIC_CHARACTER 4";
      throw 4;
    }

    // error if digit is not between 0 & 25
    if ( digit > 25 || digit < 0 ){
      cerr << "INVALID_INDEX";
      throw 3;
    }

    // filling second column map array with digit
    map[row][1] = digit;
    row++;

    in_stream >> digit;

  }

  in_stream.close();

  // error if number appears twice in rotor mapping
  int count = 0;
  // iterates through all numbers (0 - 25)
  for (int number = 0; number < 26; number ++){
    // iterates through maps second column counting each time the number appears
    for (int i = 0; i < 26; i++){
      if (map[i][1] == number){
        count ++;
      }
    }
    // error if a number appears more than once in the second column
    if (count > 1){
      cerr << "INVALID_ROTOR_MAPPING";
      throw 7;
    }
    count = 0;
  }
}

void Rotor::load_notches(int notches[26], char* argv_component){
  ifstream in_stream;
  int row, ignore, notch;

  in_stream.open(argv_component);

  // error if rotors configuration file doesn't open
  if (in_stream.fail()){
    cerr << "ERROR_OPENING_CONFIGURATION_FILE";
    throw 11;
  }

  // cycling through the first 26 characters to get to the notches
  // storing in variable random so they don't get mixed up
  for(int count = 0; count < 26; count++){
      in_stream >> ignore;
    }

  row = 0;
  in_stream >> notch;

    // fill notches array with remaining instream remaining digits
    while(!in_stream.eof())
    {

      notches[row] = notch;
      row++;

      in_stream >> notch;
    }

    in_stream.close();

  // Fill uninitalised array spaces with -1 so cannot accidentally be used
  for(; row < 26; row++){
    notches[row] = -1;
  }
}


void Rotor::load_rotors_array(Rotor rotor_array[],int argc, char** argv){

  int number_rotors = (argc - 4);
  int starting_positions[number_rotors];

  // loading starting positions into starting positions array
  rotor_array[0].load_positions(starting_positions, argv, argc);

  // loading data into rotor array's rotor data members
  for(int i = 0; i < number_rotors; i++){
    // argv[i+3] corresponds to the first rotor argument
    rotor_array[i].load_map(rotor_array[i].map, argv[i+3]);
    rotor_array[i].load_notches(rotor_array[i].notches, argv[i+3]);
    rotor_array[i].starting_pos = starting_positions[i];
  }
}

void Rotor::check_notches(Rotor rotors_array[], int rotor_n, int argc){

  //rotates current rotor regardless of whether there's then a notch or not
  int starting_pos = rotors_array[rotor_n].starting_pos;

  if (starting_pos == 25){
    rotors_array[rotor_n].starting_pos = 0;
  }

  if (starting_pos != 25){
  rotors_array[rotor_n].starting_pos ++;
  }

  // if new starting position is a notch,
  // check next rotor for notches & update its starting position
  for (int i = 0; i < 26; i++){
    if (rotors_array[rotor_n].starting_pos == rotors_array[rotor_n].notches[i]){
      // check next rotor unless we are at the final rotor
      if (rotor_n-1 >= 0){
      rotors_array[rotor_n].check_notches(rotors_array, (rotor_n-1), argc);
      }
    }
  }
}

int Enigma::letter_to_digit(char letter){
  int digit;
  digit = letter - 'A';
  return digit;
}

char Enigma::digit_to_letter(int digit){
  char letter;
  letter = digit + 'A';
  return letter;
}

int Rotor::inverse_mapping(Rotor rotors_array[], int argc, int digit){

  int number_rotors = (argc - 4);
  int unordered_map[26];

  // inversing each rotors map & saving into respective inverse_map array:

  // iterates through each rotor
  for (int rotor_n = 0; rotor_n < number_rotors; rotor_n++){
    // iterates through each number (0 - 25)
    for (int number = 0; number < 26; number++){
      // iterates through selected rotors second column rows (the mappings)
      for (int j = 0; j < 26; j++){
        // if there is a match, copy the match's index to unordered map array
        if (rotors_array[rotor_n].map[j][1] == number){
          unordered_map[number] = rotors_array[rotor_n].map[j][0];
        }
      }
    }

    // indexing the first column of the inverse map array
    // copying unordered_map into second column
    for (int i = 0; i < 26; i++){
      rotors_array[rotor_n].inverse_map[i][0] = i;
      rotors_array[rotor_n].inverse_map[i][1] = unordered_map[i];
    }
  }

  // iterate through rotors mappings
  // update digit using inverse maps in mapping function
  for (int rotor_n = 0; rotor_n < number_rotors; rotor_n++){
  digit = rotors_array[rotor_n].mapping(rotors_array[rotor_n].starting_pos,
                                        rotors_array[rotor_n].inverse_map,
                                        digit);
  }

  return digit;
}


void encrypt_string(string str, Enigma enigma, int argc, char** argv){

  int number_rotors = (argc - 4);
  char inputted_letter, outputted_letter;
  int ascii;
  int string_length = str.size();

  // error unless there is at least plugboard, reflector & rotor positions
  if (argc < 4){
    cerr << "usage: enigma plugboard-file reflector-file (<rotor-file>)* rotor-positions";
    throw 1;
  }

  // Load the plugboard connections & reflector map
  enigma.plugboard.load_plugboard(enigma.plugboard.connections, argv[1]);
  enigma.reflector.load_reflector(enigma.reflector.map, argv[2]);

  // loading rotors array
  class Rotor rotors_array[number_rotors];
  rotors_array[0].load_rotors_array(rotors_array, argc, argv);

  // Iterate through each of the string's letters
  for (int letter_n = 0; letter_n < string_length; letter_n++){

    inputted_letter = str[letter_n];
    ascii = inputted_letter;

    // check if character valid
    if (enigma.invalid_input_character(ascii)){
      cerr << "INVALID_INPUT_CHARACTER";
      throw 2;
    }

    // encryption if have no rotors (for non whitespaces)
    if (ascii != 9 && ascii != 13 && ascii != 32 && number_rotors == 0){
      outputted_letter = enigma.no_rotors_encrypt(inputted_letter, enigma);
      cout << outputted_letter;
    }

    // encryption if have rotors (for non whitespaces)
    if (ascii != 9 && ascii != 13 && ascii != 32 && number_rotors > 0){
      outputted_letter = enigma.encrypt(inputted_letter, enigma, rotors_array,
                                        argc);
      cout << outputted_letter;
    }
  }
}

bool Enigma::invalid_input_character(int ascii){
  // ascii: 9, 13 & 32 all correspond to whitespaces
  // ascii: 65 - 90 correspond to A - Z

  if (ascii < 9){
    return true;
  }

  if (ascii > 9 && ascii < 13){
    return true;
  }

  if (ascii > 13 && ascii < 32){
    return true;
  }

  if (ascii > 32 && ascii < 65){
    return true;
  }

  if (ascii > 90){
    return true;
  }
  return false;
}

string input_string(){

  string str;
  getline(cin,str);
  return str;

}

int Enigma::welcome(int argc, char** argv){

  Enigma enigma;

  // using try, throw & catch to return error codes
  try
  {
    encrypt_string(input_string(), enigma, argc, argv);
  }

  catch (int error){
    return error;
  }
  return 0;
}

char Enigma::no_rotors_encrypt(char inputted_letter, Enigma enigma){

  char outputted_letter;

  // Convert to corresponding digit
  int digit = enigma.letter_to_digit(inputted_letter);

  // Run through plugboard
  digit = enigma.check_connections(digit, enigma.plugboard.connections);

  // Run through relector
  digit = enigma.check_connections(digit, enigma.reflector.map);

  // Run back through the plugboard
  digit = enigma.check_connections(digit, enigma.plugboard.connections);

  // Convert from integer into chracter
  outputted_letter = enigma.digit_to_letter(digit);

  return outputted_letter;
}

char Enigma::encrypt(char inputted_letter, Enigma enigma, Rotor rotors_array[],
                     int argc){

  char outputted_letter;
  int number_rotors = (argc - 4);

  // Rotate rotor & check notches
  rotors_array[0].check_notches(rotors_array, number_rotors-1, argc);

  // Convert to corresponding digit
  int digit = enigma.letter_to_digit(inputted_letter);

  // Run through plugboard
  digit = enigma.check_connections(digit, enigma.plugboard.connections);

  // Run through rotors (in descending order to the first one)
  for (int n = number_rotors-1; n >= 0 ; n--){
    digit = rotors_array[n].mapping(rotors_array[n].starting_pos,
                                    rotors_array[n].map, digit);
  }

  // Run through relector
  digit = enigma.check_connections(digit, enigma.reflector.map);

  // Run back through the rotors
  digit = rotors_array[0].inverse_mapping(rotors_array, argc, digit);

  // Run back through the plugboard
  digit = enigma.check_connections(digit, enigma.plugboard.connections);

  // Convert from integer into chracter
  outputted_letter = enigma.digit_to_letter(digit);

  return outputted_letter;

  }

int Enigma::check_connections(int digit, int connections[13][2]){

  // iterate through connections array rows
  // if number appears in a row, return its pair (same row, other collumn entry)
  for(int i=0; i <= 12; i++){
    if (connections[i][0] == digit){
      return connections[i][1];
    }
    if (connections[i][1] == digit){
      return connections[i][0];
    }
  }

  // digit is unchanged if no connections
  return digit;
}

int Rotor::mapping(int starting_pos, int map[26][2], int inputted_digit){

  // inputted digit corresponds to a absolute position

  int rotation_transformation_1;
  int rotation_transformation_2;
  int mapped_digit;

  // transforming inputted digit (absolute pos) to corresponding relative pos
  rotation_transformation_1 = inputted_digit + starting_pos;

  if (rotation_transformation_1 >= 26){
    rotation_transformation_1 = rotation_transformation_1 - 26;
  }

  // through rotor map
  mapped_digit = map[rotation_transformation_1][1];

  // transforming outputted digit (relative pos) to corresponding absolute pos
  rotation_transformation_2 = mapped_digit - starting_pos;

  if (rotation_transformation_2 < 0){
    rotation_transformation_2 = rotation_transformation_2 + 26;
  }

  // return outputted digit (absolute pos)
  return rotation_transformation_2;
}
