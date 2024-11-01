#ifndef PLAYER_HH
#define PLAYER_HH
#include <string>


class Player
{
public:
    Player(const std::string& name);
    std::string get_name() const;

    int get_points() const;


    bool has_won() const;


    void add_points(int points);

private:
    std::string name_;
    int points_;
};

#endif
