#include <iostream>

class Players {
private:
    static int num_players; // Static member to track the number of players
    std::string name;

public:
    // Constructor increments num_players when a new object is created
    Players(const std::string& player_name) : name(player_name) {
        ++num_players;
        std::cout << "Player " << name << " created. Total players: " << num_players << std::endl;
    }

    // Destructor decrements num_players when an object is destroyed
    ~Players() {
        --num_players;
        std::cout << "Player " << name << " destroyed. Total players: " << num_players << std::endl;
    }

    // Static method to get the current number of players
    static int get_num_players() {
        return num_players;
    }
};

// Definition and initialization of the static member
int Players::num_players = 0;

int main() {
    std::cout << "Initial number of players: " << Players::get_num_players() << std::endl;

    // Creating players
    Players player1("Alice");
    Players player2("Bob");

    std::cout << "Current number of players: " << Players::get_num_players() << std::endl;

    {
        Players player3("Charlie");
        std::cout << "Current number of players (inside block): " << Players::get_num_players() << std::endl;
    } // player3 goes out of scope here

    std::cout << "Current number of players: " << Players::get_num_players() << std::endl;

    return 0;
}
