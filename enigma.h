#ifndef ENIGMA_H
#define ENIGMA_H

#include<string>

// classes:

class Rotor{

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
      // recursive function; checks notches & rotates rotors accordingly
      void check_notches(Rotor rotors_array[], int rotor_n, int argc);
      // maps through rotors (outwards)
      int mapping(int starting_pos, int map[26][2], int letter_dig);
      // produces an inverse map and maps accordingly (return)
      int inverse_mapping(Rotor rotors_array[], int argc, int digit);
      // loads an array of rotors
      void load_rotors_array(Rotor rotor_array[], int argc, char** argv);

      friend class Enigma;
};

class Plugboard{

    // data members:

    // plugboard connections
    int connections[13][2];

    // member functions:

    // loads plugboard into an array
    void load_plugboard(int plugboard[13][2], char* argv_component);
    // checks plugboard connections & returns it if there is one
    friend int check_connections(int digit, int connections[13][2]);
    friend class Enigma;
};

class Reflector{

    //data members:

    // reflector map
    int map[26][2];

    // member functions:

    // load reflecor map into an array
    void load_reflector(int map[13][2], char* argv_component);
    // maps through reflector
    friend int check_connections(int inputted_letter, int connections[13][2]);
    friend class Enigma;
};

class Enigma{

    // data members:

    Plugboard plugboard; // Plugboard (classes )or plugboard_t (structs)
    Reflector reflector;
    Rotor *rotors_array;

    // member functions:

    // encrypts a letter (if there are rotors)
    char encrypt(char inputted_letter, Enigma enigma, int argc);
    // encrypts a letter (if there are not rotors)
    char no_rotors_encrypt(char inputted_letter, Enigma enigma);
    // Used for going through reflector & plugboard
    int check_connections(int inputted_letter, int connections[13][2]);
    // Converts inputted letter into corresponding digit between 0 & 25
    int letter_to_digit(char letter);
    // Converts digit between 0 & 25 to corresponding letter
    char digit_to_letter(int digit);
    // Tests if inputted character acceptable
    bool invalid_input_character(int ascii);
    // Prompts user to input a string
    std::string input_string();
    // Encrypts inputted string
    void encrypt_string(std::string str, Enigma enigma, int argc, char** argv);
  public:
    // Allows user to input string & calls encrypt_string on it
    int welcome(Enigma enigma, int argc, char** argv);
};


#endif
