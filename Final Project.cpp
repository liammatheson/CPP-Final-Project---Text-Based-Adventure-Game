/*
Liam Matheson
W0494713
C++ Final Project
2025-12-01

Grading Rubric (30 points)

    Functionality (10 pts): Program runs correctly and meets requirements.
    Code Quality (8 pts): Proper structure, indentation, and naming conventions.
    Comments & Documentation (6 pts): Clear explanations covering all topics.
    Error Handling (6 pts): Basic exception handling implemented.

    Theme: Text Based Adventure Game

    Core Features
        Input/Output: Use cout/cin for user input and display results in the console.
        Control Structures: if-else statement and loops (for or while).
        Headers and Implementation files: Implement at least one header file to organize code.
        Arrays or Vector: Use at least one array or vector to store data.
        Classes & Objects: Create at least two classes (besides the main class) to demonstrate object-oriented programming.
        Error Handling: Include basic exception handling (e.g., try-catch for invalid input).
    Comments & Documentation
        Add comments throughout the code explaining:
            Purpose of each class and method.
            Logic behind control structures.
            How arrays or collections are used.
            For 20 line of code indicate the slide used in class and slide number where this topic was explained. (20 comments referencing the 20 slides- not the entire code)
        Include a header comment with:
            Project title
            Student name
            Date
            Brief description of the program

*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <cstdlib>
using namespace std;

#include "header.h"

class GameCommands {
public:

    // adding functions for different game actions

    vector<string> words;
    int location = 0;

    struct Room {                   // making a struct for rooms. Contains the text you get when you LOOK and the valid directions you can GO.
        string description;
        map<string, int> exits;
    };

    Room room[9]; // initializing rooms. i will set them up to be 3x3. you start in the center.

    /*

    [5][6][7]
    [8][0][1]  Map
    [2][3][4]

    */

    void room_stuff() {
        room[0] = { "Ye find yeself in yon dungeon. Obvious exits are NORTH, WEST, SOUTH, and EAST",{{"north",6},{"west",8},{"south",3},{"east",1}} };
        room[1] = { "Ye find yeself in right. Obvious exits are NORTH, WEST, and SOUTH",{{"north",7},{"west",0},{"south",4}} };
        room[2] = { "Ye find yeself in downleft. Obvious exits are NORTH, and EAST",{{"north",8},{"east",3}} };
        room[3] = { "Ye find yeself in down. Obvious exits are NORTH, WEST, and EAST",{{"north",0},{"west",2},{"east",4}} };
        room[4] = { "Ye find yeself in downright. Obvious exits are NORTH,and WEST",{{"north",1},{"west",3}} };
        room[5] = { "Ye find yeself in upleft. Obvious exits are SOUTH, and EAST",{{"south",8},{"east",6}} };
        room[6] = { "Ye find yeself in up. Obvious exits are WEST, SOUTH, and EAST",{{"west",5},{"south",0},{"east",7}} };
        room[7] = { "Ye find yeself in upright. Obvious exits are WEST, and SOUTH",{{"west",6},{"south",1}} };
        room[8] = { "Ye find yeself in left. Obvious exits are NORTH, SOUTH, and EAST",{{"north",5},{"south",2},{"east",0}} };
    }

    void look() {
        system("cls"); // this line clears the console. i might end up putting this all over the place or find a smarter way in the loop to keep old room messages clear. so you have to LOOK again
        cout << room[location].description << endl;
    };

    void get() {

    };

    bool go(string direction) { // if room.direction exists, your location is set there and LOOK is run. else, output "you cant go there"
        if (room[location].exits.count(direction)) { // gets 1 or 0 if direction exists
            location = room[location].exits[direction];
            return true;
        }
        else { // add another else if for something like a locked door?
            cout << "You cannot go that way.\n";
            return false;
        }
    };

    void use() {

    };

};



int main() {
    GameCommands game;
    game.room_stuff(); // starting the rooms
    game.look(); // one look to start the game

    for (;;) {

        // reads user input and breaks line up into constituent words
        game.words.clear();
        string input;
        getline(cin, input);

        stringstream ss(input);
        string word;

        while (ss >> word) {
            game.words.push_back(word);
        }

        // handling input

        if (game.words[0] == "look") {
            game.look();
        }
        else if (game.words[0] == "go" && game.words.size() > 1) {
            game.go(game.words[1]);
            game.look();
        }

    }


    

    return 0;
}

// todo
// handle pressing enter with no text