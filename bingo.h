void print_map(void);
void get_command(void);
void check_game(void);
void end(void);

using v_index = std::vector<char>::size_type;

class Player {
private:
    std::vector<v_index> territory;
    char chessman;
public:
    bool place(v_index);
    v_index current() {return territory[territory.size() - 1]}
}

vector<char> map{0, 1, 2, 3, 4, 5, 6, 7, 8};
