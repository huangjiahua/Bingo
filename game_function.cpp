#include <iostream>
#include <vector>
#include "bingo.h"

using namespace std;
bool Player::place(const v_index index, vector<char> &map)
{
    if(index) {
        map[index] = getChess();
        return 1;
    }
    return 0;
}

void print_map(vector<char> &map)
{
    auto it = map.begin();
    char page[18][18];
    for (int i = 0; i != 18; ++i) {
        for (int j = 0; j != 18; ++j) {
            if ((j + 1) % 6 == 0 && j != 17 && (i + 1) % 6 != 0)
                page[i][j] = '|';
            else if((j + 1) % 6 == 0 && j != 17 && (i + 1) % 6 == 0)
                page[i][j] = '+';
            else if((i + 1) % 6 == 0 && i != 17 && (j + 1) % 6 != 0)
                page[i][j] = '-';
        }
    }
    for (int i = 0; i != 3; ++i) {
        for (int j = 0; j != 3; ++j) {
            page[6 * i + 3][6 * j + 3] = *it++;
        }
    }
    for (int i = 0; i != 18; ++i) {
        for (int j = 0; j != 18; ++j) {
            cout << page[i][j];
        }
        cout << endl;
    }
}

void get_command()
{
    int x;
    cin >> x;
}

bool check_game()
{
    return 1;
}

void end()
{
    ;
}
