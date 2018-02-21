// main for the game Bingo
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include "bingo.h"

using namespace std;

int main()
{
    // initialize players and timer
    Player p1{'O'}, p2{'X'};
    int timer = 0;
    // print the original # map
    print_map(map);
    while (true) {
        // get the command from the player
        (timer % 2 == 0) ? get_command(timer, p1, map)
            : get_command(timer, p2, map);

        // print the new map
        system("clear");
        print_map(map);

        // check the state of the game
        if (!check_game(map, timer))
            break;
        //increment timer
        ++timer;
    }
    system("clear");

    return 0;
}

bool Player::place(const v_index index, vector<char> &map)
{
    if(index != -1 && map[index] != 'O' && map[index] != 'X') {
        map[index] = getChess();
        return 1;
    }
    return 0;
}

void print_map(const vector<char> &map)
{
    cout << "     |     |     " << endl;
    	cout << "  " << map[0] << "  |  " << map[1] << "  |  " << map[2] << endl;

    	cout << "_____|_____|_____" << endl;
    	cout << "     |     |     " << endl;

    	cout << "  " << map[3] << "  |  " << map[4] << "  |  " << map[5] << endl;

    	cout << "_____|_____|_____" << endl;
    	cout << "     |     |     " << endl;

    	cout << "  " << map[6] << "  |  " << map[7] << "  |  " << map[8] << endl;

    	cout << "     |     |     " << endl << endl;
}

void get_command(int &timer, Player &p, vector<char> &map)
{
    v_index x;
    string str = (timer % 2 == 0) ? "Player1: " : "Player2: ";
    cout << "\n" << endl;
    cout << "Type 0~8 " << str;
    if ((cin >> x) && x < 9 && map[x] != 'O' && map[x] != 'X')
        p.place(x, map);
    else {
        p.place(-1, map);
        --timer;
    }
}

bool check_game(const vector<char> &map, const int timer)
{
    if (timer < 4)
        return 1;
    for (int i = 0; i != 3; ++i) {
        if (map[i] == map[i+3] && map[i] == map[i+6]) {
            print_win(map[i]);
            return 0;
        }
    }

    for (int i = 0; i <= 6; i += 3) {
        if (map[i] == map[i+1] && map[i] == map[i+2]) {
            print_win(map[i]);
            return 0;
        }
    }

    if (map[0] == map[4] && map[0] == map[8]) {
        print_win(map[0]);
        return 0;
    }

    if (map[2] == map[4] && map[2] == map[6]) {
        print_win(map[2]);
        return 0;
    }

    if (timer == 8) {
        char ch = 0;
        cout << "\nNo one win~~" << endl;
        cout << "Enter anything to quit" << endl;
        cin >> ch;
        return 0;
    }

    return 1;
}

void print_win(char ch)
{
    if (ch == 'O')
        cout << "\nPlayer 1 win!!!" << endl;
    else
        cout << "\nPlayer 2 win!!!" << endl;
    cout << "Enter anything to quit" << endl;
    cin >> ch;
}
