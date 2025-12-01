/*
Liam Matheson
W0494713
C++ Final Project
2025-12-01

I made a basic text based adventure game. You can GO, LOOK, GET, USE, and inventory.
Find the dungeon exit to win.

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

class GameCommands {  // #14 Classes - slide 5
public: // #15 Multiple Inheritance - slide 5

    // adding functions for different game actions

    vector<string> words; // #12 DynamicArrays_Vectors - Vector. slide 13

    int location = 0; 

    int roomsize = 10;

    Room room[10]; // #13 Arrays - slide 4

    /*
    [~][9][~]
    [5][6][7]
    [8][0][1]  Map
    [2][3][4]

    */

    Player player;


    void room_stuff() { // 
        room[0] = { "Ye find yeself in yon dungeon. Obvious exits are NORTH, WEST, SOUTH, and EAST",{{"north",6},{"west",8},{"south",3},{"east",1}},{},{},{},{} }; // #10 Arrays - slide 3
        room[1] = { "Ye find yeself in right. Obvious exits are NORTH, WEST, and SOUTH",{{"north",7},{"west",0},{"south",4}},{},{},{},{} };
        room[2] = { "Ye find yeself in downleft. Obvious exits are NORTH, and EAST",{{"north",8},{"east",3}},{},{},{} };
        room[3] = { R"(


                                  %.........%@     
                                %.......:.....#%   
                               %...+%==+*===%...%  
                              %...%=%       %%...% 
                              %...+          %%..%%
                              %...%           %..%%
                               @...          %-..%%
                             %..%%..%%     %=...%% 
                             %%...%....+++:...%+%  
                           %...:%==%+%%...=%%=%%   
                         %....==%=+% .%%%%%%%      
                      +%....+-%@                   
                    @%....+:%%                     
                  @@....=:%=                       
                %%....=:%                          
              %#....=:%+%                          
            %-....=:%+....%                        
          %.....+:%+..%%..+@                       
       @@@%==.=:%-.:%..%.%........:@@%             
   %@......%+=%.....%.%%................@          
  :.............%..=%....................@         
  @+..............@.......:::--........ +@         
   +++++++   .-=................   #%##*+@         
    @+++++=--=-=======-=-+++++#**######@@          
    @####@@@+-====-==-==++==-*##%@@@####@          
    @++###*#############################@          
   @+++####===----========+++++#++###+###          
 @..@#+++++=+=----++==----++++++++#####@+.@        
 @+ ....@@@+-=---------=++++++++##@@:....##@       
 @++#*++  ..:...:.:::.:............ # #####@       
 @++##+++++++------.    .:-==-=############@       
   #@@##+++++====-===--+++++=++++++####@@          
         %@@@@@========++++==-@@@@@:               


Ye find yeself in down. There appears to be a pedestal in the center of the room. Obvious exits are NORTH, WEST, and EAST)",{{"north",0},{"west",2},{"east",4}},{"key"},{},{{"pedestal", "You see a pedestal with a KEY upon it."}},{} }; // key room
        room[4] = { "Ye find yeself in downright. Obvious exits are NORTH,and WEST",{{"north",1},{"west",3}},{},{},{},{} };
        room[5] = { "Ye find yeself in upleft. Obvious exits are SOUTH, and EAST",{{"south",8},{"east",6}},{},{},{},{} };
        room[6] = { R"(


                                                   
                    =@@@@@@@@@                     
               @@@#.===-===-==- @@@%               
            @ .==.@===@===%====%.=+- @@            
         =@.=======@==@=======+@===-*=- @          
         *===@@====@**@%@@@***@+====*===:@         
      @ ..@==@===*@@++++==+++++@@*=====@@..@       
     @.===@=@#*@@*+++===::===+++*+@*#@=@====@      
    @.====@-=@@+++===+==::===+===+++@*=@=====@     
   -.===@===@+++====+=+=-:==+======++@*+=====-@    
   +#======@++==========-:==========++@*======@    
  @  . %@@@@+=====+=====::========+==++@@@@... @   
  @.======@+*=====+=====::========++=++@*======.   
  @:======@+=+======+===-:========+==++@*====== +  
  @-==@==%@+============-:==++====+===*%*==@===.*  
  @======*@+========+===-:=+==========+%*====== .  
  @*******@+==+====+==+=-:====+=======+%#**#***@   
  @ ...-=*@+============-:=========+==+#@==:...@   
  @-=====*@+======-=====-:==========-=+%*======..  
  @=====@*@#=====-=====--=--=-=---=---*@*====== *  
  @==+===#@*==*.-+=====@=.@======@:-@=*@@@=-=== +  
  @======*@#==@@@=======@@%======#@@==*@**=@===:   
  =@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@   
  @ -===@*@+============-:===+========+%*=====:-   
  @===@==*@+==+====+====-:=+====@=@@=#+%*====== =  
  @======#@++=========+=-:====+=@=@@=@+%*====== *  
  @==-===*@+============-:======@####@+#*======.-  
  @======*@+===+========-:============+%**@-===+   
   @@@@@@@@+==++========-:+=+=========+%@@@@@@@@   
  @---==%=@*==+=========-:===+========*#*=+====.   
  @-=-===+@*+=+=========-:===========+*%*=@==== +  
  @====-=*@*+========+==-:============*%*======.+  
  @======*@*+===========-:============*%**@====-.  
  @***@***@*============-:=====-======*%#**##**@   
                                                   
                                                   


Ye find yeself in up. To the north is a DOOR. Other exits are WEST, SOUTH, and EAST)",{{"north",9},{"west",5},{"south",0},{"east",7}},{},{{"north", true}},{{"door", "You see a heavy door with a big lock on it."}},{""}}; // locked door? havent added rooms up there yet
        room[7] = { "Ye find yeself in upright. Obvious exits are WEST, and SOUTH",{{"west",6},{"south",1}},{},{},{},{} };
        room[8] = { "Ye find yeself in left. There appears to be something carved on the wall. Obvious exits are NORTH, SOUTH, and EAST",{{"north",5},{"south",2},{"east",0}},{},{},{{"wall", R"(



@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
* :::::::::::::: @ :::::::::::::::::::::: -----=-+@
*:::::::@::::::::=:::::::::-++++#:.:::::@-------+*@
*::::::::::::::::::::::::::::::::::::::%::.:--:::+@
@::::::::::::::::::::::::::::::::::::::::::#::*::-@
@ ::@::::@%%%@:::::::@%%%%@::@%@#:::::::::::::=-:*@
+:::@:::::%**%@::::::@%*%@:::@%*%%@%::::::::::--:+@
+:::::::::@+*#@@::::@@+*%.::::@#+**%%@@::::::::::+@
*::::::::::@***%#::@%@*+@::::::::@#***%%@%:::::.:+@
*::::::::::.@***@:*%*@*@::::::::::::@*+**@.::::::+@
*:.:-:::::::@*+*#@@%**@ :::::::::@@%%+**#@::::@%:+@
*:::::::::::-@+**%%***@.::::::@@%%++**@ :::::::::+@
*:::::::::::::@*@****@:::::::@%+%*@@ @::::::::@::+@
#::::::::::::::@+***@::::::::@%@@ ::::::::::::+:=+@
#--:::::::=::::...@ :::::::::. ::::::::: :::*:::**@
%--::+:::+:::::::::::::::::::::::::::::::::=:.:+++@
@++--::::::: ::::::::::-+=++*.:@::::::::::-*:::*++@
@*+*-::::@@@.:::::::::.:-:::::::::--:::::::::+*#++@
@***+***@++**+***+++-:-=+++*+*+**++***+@@@@+*@++++@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@



You see a carving on the wall. It says v > )"}},{} };
        room[9] = { "Ye find yeself in upup. Obvious exits are SOUTH",{{"south",9}},{},{},{},{} };
    }

    void look() { // #7 Functions - slide 3
        system("cls"); // this line clears the console. i might end up putting this all over the place or find a smarter way in the loop to keep old room messages clear. so you have to LOOK again
        cout << room[location].description << endl; // ✔ Basics IO, Sequence, Selection, Repetition, and Random - Slide 5. cout, cin
    };

    void look(const string& target) { // #5 Into_To_Pointers - slide 2. Pointers // #9 Functions - Function overloading. Slide 7
        system("cls");
        if (room[location].features.count(target)) { // ✔ Basics IO, Sequence, Selection, Repetition, and Random - Slide 7. if statement
            cout << room[location].features[target] << endl;
        }
        else {
            cout << "You see nothing special about that." << endl;
        }
    }

    void get() { // #18 Functions - slide 3
        if (!room[location].items.empty()) {
            system("cls");
            cout << "You pick up the " << room[location].items[0] << endl;
            player.inventory.push_back(room[location].items[0]); // add to inventory
            room[location].items.clear(); // remove item from room
        }
    };

    bool go(string direction) { // if room.direction exists, your location is set there and LOOK is run. else, output "you cant go there"
        if (room[location].exits.count(direction)) { // gets 1 or 0 if direction exists
            // check if the exit is locked
            if (room[location].locked.count(direction) && room[location].locked[direction]) {
                system("cls");
                cout << "The door is locked. You need a key." << endl;
                return false;
            }
            location = room[location].exits[direction];

            if (location == 9) {
                system("cls");
                cout << R"(



                                                   
                  -#@@@@@@@@@@@@+:                 
           .........................====+          
  @.......@@#@@%=-=================+@@@%@@.......# 
  @..@@@@..*@......................-===@%..@@@@..+ 
  :..@   @..@.@.........*..@......@-===@..@   @..  
   #.#      @..........:####.+.....===-@      +.@  
   @.=@     %........=@*###@#=@....===.:     @-.@  
    ..@      %........#=-####@.:...===@      @.+   
    @..@     @........#######@.:..===-@     @..@   
     @..%=    =......@.#%#*##.@...===#    @+..%    
       @.:@   @.......@.@##@.@...===.@   @..@      
         @.:@@ @........=@@=....===.@ @%..@        
           @@.=+@........@*....@#==@+-.@@          
               @@=@..........===.%=@@              
                @..@@.....====-@@..@               
                      @.-++==@                     
                       @@@@@@                      
                       @...=@                      
                      @....-=@                     
                    @........=-@                   
                  @%%%%%%%%@@@@@@@                 
                  @##..........#%@                 
                  @#*#........@#%@                 
                @#######****####@@@=               
             @@ @@@@@@@@@@@@@@@@@@@%+@@            
            # .:  --==++**************@            
              :::*::::::::::---:-****@             
              .:.%:::::::::::::::@***@             
           @ ::  ::::::::-=++**********#@          
         # ..  .......::::::::::::::*****#         
         # ::  ::::::::::::::::::::-**@**#         
         =@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@         
                                                   
                                                   



                        )";
                cout << "Congratulations! You reached the final room and won the game!" << endl;
                exit(0); // ends the game
            }

            return true;
        }
        else { // add another else if for something like a locked door?
            system("cls");
            cout << "You cannot go that way.\n";
            return false;
        }
    };

    void show_inventory() {
        system("cls");
        if (player.inventory.empty()) { // #19 Basics IO, Sequence, Selection, Repetition, and Random - Slide 7. if statement
            cout << "Your inventory is empty." << endl;
        }
        else {
            cout << "You have:" << endl;
            for (const auto& item : player.inventory) { // #11 Arrays - Looping through arrays. Slide 7. I know the slide shows a more basic approach, but this is the same using auto&. it loops through an array though.
                cout << "- " << item << endl;
            }
        }
    }

    void use(const string& item, const string& target_direction) {
        if (item == "key") { // #20 Basics IO, Sequence, Selection, Repetition, and Random - Slide 7. if statement
            // check if player has the key
            auto it = find(player.inventory.begin(), player.inventory.end(), "key"); // looks through inventory vector for key
            if (it == player.inventory.end()) {
                system("cls");
                cout << "You don't have a key." << endl;
                return;
            }

            // check if the direction exists and is locked
            if (room[location].locked.count(target_direction) && room[location].locked[target_direction]) {
                room[location].locked[target_direction] = false; // unlocks door
                system("cls");
                cout << "You unlocked the door to the " << target_direction << "." << endl;

                if (go(target_direction)) { // and move into new room
                    look();
                
                }
            }
            else {
                system("cls");
                cout << "There is nothing to unlock there." << endl;
            }
        }
        else {
            system("cls");
            cout << "You can't use that here." << endl;
        }
    }

};

int main() {
    GameCommands game; // #14 - Classes - Creating an object, slide 16
    game.room_stuff(); // starting the rooms

    cout << R"(


 /$$$$$$$  /$$   /$$ /$$   /$$  /$$$$$$  /$$$$$$$$  /$$$$$$  /$$   /$$
| $$__  $$| $$  | $$| $$$ | $$ /$$__  $$| $$_____/ /$$__  $$| $$$ | $$
| $$  \ $$| $$  | $$| $$$$| $$| $$  \__/| $$      | $$  \ $$| $$$$| $$
| $$  | $$| $$  | $$| $$ $$ $$| $$ /$$$$| $$$$$   | $$  | $$| $$ $$ $$
| $$  | $$| $$  | $$| $$  $$$$| $$|_  $$| $$__/   | $$  | $$| $$  $$$$
| $$  | $$| $$  | $$| $$\  $$$| $$  \ $$| $$      | $$  | $$| $$\  $$$
| $$$$$$$/|  $$$$$$/| $$ \  $$|  $$$$$$/| $$$$$$$$|  $$$$$$/| $$ \  $$
|_______/  \______/ |__/  \__/ \______/ |________/ \______/ |__/  \__/
                                                                      
                                                                      
                                                                      
  /$$$$$$  /$$   /$$ /$$$$$$$$  /$$$$$$  /$$$$$$$$       /$$    /$$   
 /$$__  $$| $$  | $$| $$_____/ /$$__  $$|__  $$__/      | $$   | $$   
| $$  \ $$| $$  | $$| $$      | $$  \__/   | $$         | $$   | $$   
| $$  | $$| $$  | $$| $$$$$   |  $$$$$$    | $$         |  $$ / $$/   
| $$  | $$| $$  | $$| $$__/    \____  $$   | $$          \  $$ $$/    
| $$/$$ $$| $$  | $$| $$       /$$  \ $$   | $$           \  $$$/     
|  $$$$$$/|  $$$$$$/| $$$$$$$$|  $$$$$$/   | $$            \  $/      
 \____ $$$ \______/ |________/ \______/    |__/             \_/       
      \__/                                                            



            )" << endl;

    for (;;) {
            
        // reads user input and breaks line up into constituent words
        game.words.clear();
        string input;
        try { // #6 Exceptions - slide 5
            getline(cin, input); // #4 Validation - Slide 3. getline(cin, variable);
        }
        catch (const exception& e) {
            system("cls");
            cout << "Input error: " << e.what() << endl;
            continue; // go back to the loop
        }

        stringstream ss(input);
        string word;

        while (ss >> word) { // #3 ✔ Basics IO, Sequence, Selection, Repetition, and Random - Slide 9. while loop
            game.words.push_back(word);
        }

        // handling input

        if (game.words.empty()) { // #21 Exception Handling - slide 5
            system("cls");
            game.look();
            continue;
        }

        else if (game.words[0] == "look" && game.words.size() == 1) { // just look
            game.look();
        }

        else if (game.words[0] == "look" && game.words.size() > 1) { // look wall
            game.look(game.words[1]); // uses overloaded look
        }

        else if (game.words[0] == "go" && game.words.size() > 1) {
            if (game.go(game.words[1])) {
                game.look(); // #8 Functions - slide 4
            }
        }
        
        else if (game.words[0] == "go" && game.words.size() == 1) { // if you just type "go"
            system("cls");
            cout << "Go where?" << endl;
        }

        else if (game.words[0] == "get" && game.words.size() > 1) {
            if (game.words[1] == "key") {
                if (!game.room[game.location].items.empty()) {
                    game.get();
                }
                else {
                    system("cls");
                    cout << "You can't get that.\n";
                }
            }
            else {
                system("cls");
                cout << "You can't get that.\n";
            }
        }

        else if (game.words[0] == "inventory") { // runs inventory()
            game.show_inventory();
        }

        else if (game.words[0] == "use" && game.words.size() > 2) {
            game.use(game.words[1], game.words[2]);
        }

        else if (game.words[0] == "use" && game.words.size() == 1) {
            system("cls");
            cout << "Use what?";
        }

        else if (game.words[0] == "help" && game.words.size() == 1) {
            system("cls");
            cout << "type LOOK to look at your surroundings. \ntype INVENTORY to view your items. \ntype GO and a direction to go to another room. \ntype GET to get an item. \ntype USE to use an item";
        }

        else {
            system("cls");
            cout << "I don't understand. Type HELP or try again." << endl;
        }

    }

    return 0;
}

// todo
// handle pressing enter with no text. DONE
// pedestal still has key on it after you take it