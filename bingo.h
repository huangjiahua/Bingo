using v_index = std::vector<char>::size_type;

class Player {
private:
    char chessman;
public:
    Player(const char sign) :
        chessman(sign) {}
    bool place(const v_index, std::vector<char> &);
    char getChess() {return chessman;}
};

std::vector<char> map{'0', '1', '2', '3',
    '4', '5', '6', '7', '8'};


void print_map(const std::vector<char>&);
void get_command(int &, Player&, std::vector<char>&);
bool check_game(const std::vector<char>&, const int);
void end(void);
void print_win(char ch);
