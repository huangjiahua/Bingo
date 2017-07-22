void print_map(const std::vector<char>&);
void get_command(void);
bool check_game(void);
void end(void);

using v_index = std::vector<char>::size_type;

class Player {
private:
    std::vector<v_index> territory;
    char chessman;
public:
    Player(const char sign) :
        chessman(sign) {}
    bool place(const v_index, std::vector<char> &);
    char getChess() {return chessman;}
    v_index current() {return territory[territory.size() - 1];}
};

std::vector<char> map{'0', '1', '2', '3',
    '4', '5', '6', '7', '8'};
