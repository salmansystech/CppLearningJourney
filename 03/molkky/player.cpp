#include "player.hh"
#include <iostream>

Player::Player(const std::string& name) : name_(name), points_(0) {}

std::string Player::get_name() const {
    return name_;
}
int Player::get_points() const {
    return points_;
}
bool Player::has_won() const {
    return points_ == 50;
}
void Player::add_points(int points) {
    points_ += points;
    if (points_ > 50) {
        std::cout << name_ << " gets penalty points!" << std::endl;
        points_ = 25;
    }
}

