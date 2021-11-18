#include"enigma.h"
#include<iostream>
#include<fstream>

using namespace std;

// Rotor class member functions:

void rotor::load_positions(int starting_positions[], char** argv, int argc){
  ifstream in_stream;
  int digit;
  int number_rotors = (argc - 4);

  // int number_rotors = (argc - 4); // - executable, plugboard, reflector & rotors' positions

  in_stream.open(argv[argc-1]); // opens final argument

  if (in_stream.fail()){
    cerr << "ERROR_OPENING_CONFIGURATION_FILE";
    throw 11;
  }

  int count = 0;

  in_stream >> digit;

  while(!in_stream.eof())
  {

    if (in_stream.fail()){
      cerr << "NON_NUMERIC_CHARACTER 1";
      throw 4;
    }

    starting_positions[count] = digit;
    count++;

    in_stream >> digit;

  }

  if (number_rotors != 0 && count != number_rotors){ // I.e. if the number of positions is less than the number of rotors
    cerr << "NO_ROTOR_STARTING_POSITION";
    throw 8;
  }

  in_stream.close();
  }

void reflector::load_reflector(int map[13][2], char* argv_component){ //argv[2]

ifstream in_stream;
int digit, count, count_2;

in_stream.open(argv_component);

if (in_stream.fail()){
  cerr << "ERROR_OPENING_CONFIGURATION_FILE";
  throw 11;
}

int row = 0;
int column = 0;
count = 0;

in_stream >> digit;

while(!in_stream.eof())
{

  if (in_stream.fail()){ //CHECKING FOR NON_NUMERIC CHARACTER
    cerr << "Non-numeric character in reflector file reflector.rf";
    throw 4;
  }

  //cout << digit << " is in [row][column]: " << row << " " << column << endl;

  if ( digit < 0 || digit > 25 ){
    cerr << "INVALID_INDEX";
    throw 3;
  }

  count++;

  map[row][column] = digit;

  int col = column;

  // updating position
  if (col == 0){
    column ++; // then column = 1 which means it applies to next boolean expression
  }

  if (col == 1){
    row ++;
    column --;
  }
  in_stream >> digit;
}

in_stream.close();

if (count != 26){ // tells us if theres too litle parameters
  cerr << "Insufficient number of mappings in reflector file: reflector.rf";
  throw 10;
}

/*cout << "MAPPING IS: " << endl;
for (int j = 0; j < 13; j++){
  cout << map[j][0] << " " << map[j][1] << endl;
}*/

count_2 = 0;
for (int number = 0; number < 26; number++){ // iterates through all the numbers (0 - 25)
  for (int j = 0; j < 13; j++){ // iterates through every row
    if (map[j][0] == map[j][1]){ // if a digit maps to itself
      cerr << "INVALID_REFLECTOR_MAPPING";
      throw 9;

    }
    if (map[j][0] == number || map[j][1] == number){ // If a number appears in a connection, count it
      count_2++;
    }
  }
  if (count_2 > 1){ // if a number appears more than once in connections (i.e. more than 1)
    cerr << "INVALID_REFLECTOR_MAPPING";
    throw 9;
  }
  count_2 = 0;
}
}

void plugboard::load_plugboard(int plugboard[13][2], char* argv_component){

ifstream in_stream;
int digit;

in_stream.open(argv_component);

if (in_stream.fail()){
  cerr << "ERROR_OPENING_CONFIGURATION_FILE";
  throw 11;
}

int row = 0;
int column = 0;
int i = 0;

in_stream >> digit;

//cout << "I VALUE : " << i << endl;

while(!in_stream.eof())
{

  if (in_stream.fail()){ //CHECKING FOR NON_NUMERIC CHARACTER
    cerr << "Non-numeric character in plugboard file plugboard.pb";
    throw 4;
  }

  if (digit < 0 || digit > 25){
    cerr << "INVALID_INDEX";
    throw 3;
  }

  //cout << digit << " is in [row][column]: " << row << " " << column << endl;
  plugboard[row][column] = digit;
  i++;

  int col = column;

  // updating position
  if (col == 0){
    column ++; // then column = 1 which means it applies to next boolean expression
  }

  if (col == 1){
    row ++;
    column --;
  }
  in_stream >> digit;

  //cout << "LOOP I VALUE: " << i << endl;
}

in_stream.close();

//cout << "I VALUE IS : " << i << endl << endl;

if (i % 2 != 0){ // checking if number of inputted digits is even
  cerr << "Incorrect number of parameters in plugboard file plugboard.pb";
  throw 6;
}
//cout << "ROW " << row;
int count = 0;
for (int number = 0; number < 26; number++){ // iterates through all the numbers (0 - 25)
  for (int j = 0; j < row; j++){ // iterates through every row
    if (plugboard[j][0] == plugboard[j][1]){ // if a digit maps to itself
      cerr << "IMPOSSIBLE_PLUGBOARD_CONFIGURATION";
      throw 5;
    }
    if (plugboard[j][0] == number || plugboard[j][1] == number){ // If a number appears in a connection, count it
      count++;
    }
  }
  //cout << endl << "NUMBER: " << number << "WITH COUNT: " << count << endl;
  if (count > 1){ // if a number appears more than once in connections (i.e. more than 1)
    cerr << "IMPOSSIBLE_PLUGBOARD_CONFIGURATION";
    throw 5;
  }
  count = 0;
}

// Now row points to the first column & next row of the last connection
for (row; row < 13; row++){
  plugboard[row][0] = -1; // filling remaining spaces with minus 1; so wont be confused & used by plugboard
  plugboard[row][1] = -1;
}
}


void rotor::load_map(int map[26][2], char* argv_component){

  // index the first column
  for (int i = 0; i < 26; i++){
    map[i][0] = i;
  }

  ifstream in_stream;
  int digit;

  in_stream.open(argv_component);

  if (in_stream.fail()){
    cerr << "ERROR_OPENING_CONFIGURATION_FILE";
    throw 11;
  }

  int row = 0;

  in_stream >> digit;


  while(!in_stream.eof())
  {

    if (in_stream.fail()){ //CHECKING FOR NON_NUMERIC CHARACTER
      cerr << "NON_NUMERIC_CHARACTER 4";
      throw 4;
    }

    if ( digit > 25 || digit < 0 ){
      cerr << "INVALID_INDEX";
      throw 3;
    }

    map[row][1] = digit;
    row++;

    in_stream >> digit;

  }

  in_stream.close();

// iterates through the maps second column
// If a number appears twice, get INVALID_ROTOR_MAPPING error

int count = 0;
for (int number = 0; number < 26; number ++){ // checks each number
  for (int i = 0; i < 26; i++){ // iterates through second column checking for each number
    if (map[i][1] == number){
      count ++;
    }
  }
  if (count > 1){
    cerr << "INVALID_ROTOR_MAPPING";
    throw 7;
    //cout << "number: " << number << " ";
    //cout << "count " << count << " ";
  }
  count = 0;
}

}

void rotor::load_notches(int notches[26], char* argv_component){
  ifstream in_stream;
  int ignore; //storing rotors map in the variable ignore so dont accidentally get a mapping digit in our notches array
  int notch;

  in_stream.open(argv_component);

  if (in_stream.fail()){
    cerr << "ERROR_OPENING_CONFIGURATION_FILE";
    throw 11;
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


  void rotor::load_rotors_array(rotor rotor_array[],int argc, char** argv){

  int number_rotors = (argc - 4);

  int starting_positions[number_rotors];
  rotor_array[0].load_positions(starting_positions, argv, argc);

  for(int i = 0; i < number_rotors; i++){
    rotor_array[i].load_map(rotor_array[i].map, argv[i+3]); //argv[3] corresponds to the first rotor
    rotor_array[i].load_notches(rotor_array[i].notches, argv[i+3]);
    rotor_array[i].starting_pos = starting_positions[i];
  }

  // Example arguments tests:

  // Rotor 1 map & notches

  /*cout << endl << "Rotor 1 map: " << endl << endl;
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

  void rotor::check_notches(rotor rotors_array[], int rotor_n, int argc){ // will put in rotor_n = 0 // ROTATE THE THIRD ONE TO THE LEFT MOST

  //rotates current rotor regardless of whether there's then a notch or not
  int starting_pos = rotors_array[rotor_n].starting_pos;

  //cout << "Rotor " << rotor_n << " has starting position: " << starting_pos << endl << endl;

  if (starting_pos == 25){
    rotors_array[rotor_n].starting_pos = 0;
  }

  if (starting_pos != 25){
  rotors_array[rotor_n].starting_pos ++;
  }

  //cout << "starting position updated to: " << rotors_array[rotor_n].starting_pos << endl << endl;

  // checks if new starting position is a notch; if so updates the next rotors starting position by 1
  for (int i = 0; i < 26; i++){
    if (rotors_array[rotor_n].starting_pos == rotors_array[rotor_n].notches[i]){
      //cout << rotors_array[rotor_n].starting_pos << " is a notch so next rotate next rotor..." << endl << endl;

      // iterates through the remaining rotors
      if (rotor_n-1 >= 0){
      rotors_array[rotor_n].check_notches(rotors_array, (rotor_n-1), argc);
      }
    }
  }
  }

int enigma::letter_to_digit(char letter){
  int digit;
  digit = letter - 'A';
  return digit;
}

char enigma::digit_to_letter(int digit){
  char letter;
  letter = digit + 'A';
  return letter;
}

int rotor::inverse_mapping(rotor rotors_array[], int argc, int digit){
int number_rotors = (argc - 4);

int unordered_map[26];

/*cout << "Before inversing: " << endl;
for (int i = 0; i < 26 ; i++){
  cout << endl << rotors_array[1].map[i][0] << "  " << rotors_array[1].map[i][1] << endl;
}*/

for (int rotor_n = 0; rotor_n < number_rotors; rotor_n++){
  for (int number = 0; number < 26; number++){
    for (int j = 0; j < 26; j++){
      if (rotors_array[rotor_n].map[j][1] == number){
        unordered_map[number] = rotors_array[rotor_n].map[j][0];
      }
    }
  }
  for (int i = 0; i < 26; i++){
    rotors_array[rotor_n].inverse_map[i][0] = i;
    rotors_array[rotor_n].inverse_map[i][1] = unordered_map[i];
  }
}

for (int rotor_n = 0; rotor_n < number_rotors; rotor_n++){
  //cout << endl << endl << "The outputted digit of rotor " << rotor_n << " is: "<< digit;
  digit = rotors_array[rotor_n].mapping(rotors_array[rotor_n].starting_pos, rotors_array[rotor_n].inverse_map, digit);
}

return digit;

/*
cout << "After inversing: " << endl;
for (int i = 0; i < 26 ; i++){
  cout << endl << rotors_array[1].map[i][0] << "  " << rotors_array[1].map[i][1] << endl;
}*/
}


void encrypt_string(string str, enigma enigma, int argc, char** argv){

  int number_rotors = (argc - 4);
  char inputted_letter;
  char outputted_letter;
  int ascii;
  int string_length = str.size();

  if (argc < 4){
    cerr << "usage: enigma plugboard-file reflector-file (<rotor-file>)* rotor-position";
    throw 1;
  }

  //cout << endl << endl << "The string length is: " << string_length << endl << endl;

  class plugboard plugboard;
  class reflector reflector; // Q: do you have to put class here because plugboard is also the name of a variable?

  plugboard.load_plugboard(plugboard.connections, argv[1]);
  reflector.load_reflector(reflector.map, argv[2]);

  // outcome if 0 rotors
  if (number_rotors == 0){

    for (int letter_n = 0; letter_n < string_length; letter_n++){
      inputted_letter = str[letter_n];

      ascii = inputted_letter;
      if (invalid_input_character(ascii)){
        cerr << "INVALID_INPUT_CHARACTER";
        throw 2;
      }

      if (ascii != 9 && ascii != 13 && ascii != 32 && number_rotors == 0){
        outputted_letter = enigma.no_rotors_encrypt(inputted_letter, enigma, plugboard, reflector, argc, argv);
        cout << outputted_letter;
      }
    }
}

  class rotor rotors_array[number_rotors];
  rotors_array[0].load_rotors_array(rotors_array, argc, argv);

  /*class rotor rotors_array[number_rotors];
  rotors_array[0].load_rotors_array(rotors_array, argc, argv);*/

  for (int letter_n = 0; letter_n < string_length; letter_n++){

    inputted_letter = str[letter_n];

    ascii = inputted_letter;

    if (invalid_input_character(ascii)){
      cerr << "INVALID_INPUT_CHARACTER";
      throw 2;
    }

    if (ascii == 9 || ascii == 13 || ascii == 32){
      str[letter_n] = ' ';
    }

    if (ascii != 9 && ascii != 13 && ascii != 32 && number_rotors > 0){ // Keep asking for input letter if input a letter (tab, return, space)
      outputted_letter = enigma.encrypt(inputted_letter, enigma, plugboard, reflector, rotors_array, argc, argv);
      cout << outputted_letter;
    }
  }
}

bool invalid_input_character(int ascii){
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

string input_string(string str){
  getline(cin,str);
  //cout << "the string is " << string << "   ";
  return str;
}

char enigma::no_rotors_encrypt(char inputted_letter, enigma enigma, plugboard plugboard, reflector reflector, int argc, char** argv){

  char outputted_letter;

  // Convert to corresponding digit
  int digit = enigma.letter_to_digit(inputted_letter);
  //cout << endl << endl << "digit: " << digit << endl << endl

  // Run through plugboard
  digit = enigma.check_connections(digit, plugboard.connections);
  //cout << "Digit after plugboard: " << digit << endl << endl;

  // Run through relector
  digit = enigma.check_connections(digit, reflector.map);
  //cout << "Digit after reflector: " << digit << endl << endl;

  // Run back through the plugboard
  digit = enigma.check_connections(digit, plugboard.connections);
  //cout << "Digit after returning through the plugboard: " << digit;

  // Convert from integer into chracter
  outputted_letter = enigma.digit_to_letter(digit);
  //cout << endl << endl << "The encrypted version of inputted letter is: " << outputted_letter << endl << endl;

  return outputted_letter;
}

char enigma::encrypt(char inputted_letter, enigma enigma, plugboard plugboard, reflector reflector, rotor rotors_array[], int argc, char** argv){

  char outputted_letter;
  int number_rotors = (argc - 4);
  //int ascii;

  // Rotate rotor & check notches
  rotors_array[0].check_notches(rotors_array, number_rotors-1, argc);

  // Convert to corresponding digit
  int digit = enigma.letter_to_digit(inputted_letter);
  //cout << endl << endl << "digit: " << digit << endl << endl;

// Run through plugboard
digit = enigma.check_connections(digit, plugboard.connections);
//cout << "Digit after plugboard: " << digit << endl << endl;

// Run through rotors (in descending order to the first one)
//cout << endl << endl << "first rotor: " << endl<< "starting pos*: " << rotors_array[0].starting_pos << endl << endl;
for (int n = number_rotors-1; n >= 0 ; n--){
  digit = rotors_array[n].mapping(rotors_array[n].starting_pos, rotors_array[n].map, digit);
  //cout << "Digit after rotor " << (n+1) << " is: " << digit << endl<< endl;
}

// Run through relector
digit = enigma.check_connections(digit, reflector.map);
//cout << "Digit after reflector: " << digit << endl << endl;

/*cout << endl << endl;
for (int n = 0; n < 13; n ++){
  cout << reflector.map[n][0] << " " << reflector.map[n][1] << endl;
}*/

// Run back through the rotors
digit = rotors_array[0].inverse_mapping(rotors_array, argc, digit);
//cout << "Digit after inverse mapping: " << digit;

// Run back through the plugboard
digit = enigma.check_connections(digit, plugboard.connections);
//cout << "Digit after returning through the plugboard: " << digit;


// Convert from integer into chracter
outputted_letter = enigma.digit_to_letter(digit);
//cout << endl << endl << "The encrypted version of inputted letter is: " << outputted_letter << endl << endl;

return outputted_letter;

}


// Member function definitions:

int enigma::check_connections(int inputted_letter, int connections[13][2]){
  //cout << endl << "The inputted letter is: " << inputted_letter << endl;
  for(int i=0; i <= 12; i++){
    if (connections[i][0] == inputted_letter){
    //  cout << "There is a connection in the first column; connected to: "
        //   << connections[i][1] << endl << endl;
      return connections[i][1];
    }
    if (connections[i][1] == inputted_letter){
    //  cout << "There is a connection in the second column; connected to: "
        //   << connections[i][0] << endl << endl;
      return connections[i][0];
    }
  }
//  cout << "There is not a connection";
  return inputted_letter;
}

int rotor::mapping(int starting_pos, int map[26][2], int inputted_digit){
  // the inputted digit is in absolute form (i.e. not taking into account rotation)
  int rotation_transformation_1;
  int rotation_transformation_2;
  int mapped_digit;
  //cout << endl << "Starting position (digit at 12 o'clock): " << starting_pos<<endl;

  //cout << "Inputted (absolute) digit is: " << inputted_digit << endl;
  // factoring in rotation to the inputted_digit
  // transforming inputted digit (absolute form) to corresponding relative form
  rotation_transformation_1 = inputted_digit + starting_pos; //takes into account rotation

  if (rotation_transformation_1 >= 26){
    rotation_transformation_1 = rotation_transformation_1 - 26;
  }
  //cout << "Relative version is: " << rotation_transformation_1<<endl;

  // mapping the relative digit
  mapped_digit = map[rotation_transformation_1][1]; // This mapping doesnt compensate for THE RETURN JOURNEY (ONCE DONE - COMPLETE!)
  //cout << "Which has been mapped to: " << mapped_digit << endl;

  // removing affects of rotation
  // transforming relative form to corresponding absolute form
  rotation_transformation_2 = mapped_digit - starting_pos;

  if (rotation_transformation_2 < 0){
    rotation_transformation_2 = rotation_transformation_2 + 26;
  }

  //cout << "Absolute version of this is: " << rotation_transformation_2 << endl << endl;
  return rotation_transformation_2;
}
