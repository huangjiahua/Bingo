// main for the game Bingo
#include <iostream>
#include <vector>
#include <string>
#include "bingo.h"

int main()
{
    // print the original # map
    print_map();
    while (true) {
        // get the command from the player
        get_command();

        // print the new map
        system("clear");
        print_map();

        // check the state of the game
        if (!check_game())
            break;
    }
    system("clear");
    end();

    return 0;
}
