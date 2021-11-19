#ifndef ENIGMA_H
#define ENIGMA_H


// classes:

class rotor{
  public:

      // data members:

      // stores starting postiion of a rotor
      int starting_pos;
      // stores the notches of a rotor
      int notches[26];
      // stores the map of a rotor (outwards)
      int map[26][2];
      // stores the inverse map of a rotor (returning)
      int inverse_map [26][2];

      // member functions:

      // loads rotor starting positions into an array
      void load_positions(int starting_positions[], char** argv, int argc);
      // loads rotors notches into an array
      void load_notches(int notches[26], char* argv_component);
      // loads rotors map into an array
      void load_map(int map[26][2], char* argv_component);
      // loads an array of rotors
      void load_rotors_array(rotor rotor_array[], int argc, char** argv);
      // recursive function; checks notches & rotates rotors accordingly
      void check_notches(rotor rotors_array[], int rotor_n, int argc);
      // maps through rotors (outwards)
      int mapping(int starting_pos, int map[26][2], int letter_dig);
      // produces an inverse map and maps accordingly (return)
      int inverse_mapping(rotor rotors_array[], int argc, int digit);
};

class plugboard{
  public:

    // data members:

    // plugboard connections
    int connections[13][2];

    // member functions:

    // loads plugboard into an array
    void load_plugboard(int plugboard[13][2], char* argv_component);
    // checks plugboard connections & returns it if there is one
    friend int check_connections(int digit, int connections[13][2]);
};

class reflector{
  public:

    //data members:

    // reflector map
    int map[26][2];

    // member functions:

    // load reflecor map into an array
    void load_reflector(int map[13][2], char* argv_component);
    // maps through reflector
    friend int check_connections(int inputted_letter, int connections[13][2]);

};

class enigma{

  public:

    // data members:

    plugboard plugboard;
    reflector reflector;

    // member functions:

    // encrypts a letter (if there are rotors)
    char encrypt(char inputted_letter, enigma enigma, rotor rotors_array[], int argc, char** argv);
    // encrypts a letter (if there are not rotors)
    char no_rotors_encrypt(char inputted_letter, enigma enigma, int argc, char** argv);
    // Used for going through reflector & plugboard
    int check_connections(int inputted_letter, int connections[13][2]);
    // Converts inputted letter into corresponding digit between 0 & 25
    int letter_to_digit(char letter);
    // Converts digit between 0 & 25 to corresponding letter
    char digit_to_letter(int digit);
    // Tests if inputted character acceptable
    bool invalid_input_character(int ascii);
    // Allows user to input string & calls encrypt_string on it
    int welcome(int argc, char** argv);
};





#endif
