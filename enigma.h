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
    int check_connections(int inputted_letter, int connections[13][2]);
};

/*class reflector{
  public:

    int map[26][2];

    int mapping(int map[26][2])

}*/

// functions:

void load_map(int map[26][2], char* argv_component);

void load_plugboard(int plugboard[13][2], char** argv);

void load_notches(int notches[26], char* argv_component);

void load_positions(int starting_positions[], char** argv, int argc);

void load_rotors_array(rotor rotor_array[], int argc, char** argv);

void check_notches(rotor rotors_array[], int rotor_n, int argc);

#endif
