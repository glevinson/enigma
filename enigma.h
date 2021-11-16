#ifndef ENIGMA_H
#define ENIGMA_H


// classes:

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
};

class reflector{
  public:

    int map[26][2];

    void load_reflector(int map[13][2], char* argv_component);
    int mapping(int map[26][2]);


};

// functions:

int check_connections(int inputted_letter, int connections[13][2]);

void load_map(int map[26][2], char* argv_component);

void load_plugboard(int plugboard[13][2], char* argv_component);

void load_notches(int notches[26], char* argv_component);

void load_positions(int starting_positions[], char** argv, int argc);

void load_rotors_array(rotor rotor_array[], int argc, char** argv);

void check_notches(rotor rotors_array[], int rotor_n, int argc);

int letter_to_digit(char letter);

int reflector_mapping(int map[26][2], int digit);

int inverse_mapping(rotor rotors_array[], int argc, int digit);

char encrypt(char inputted_letter, int argc, char** argv);

char digit_to_letter(int digit);

void load_reflector(int map[13][2], char* argv);

#endif
