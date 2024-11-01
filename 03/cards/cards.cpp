#include <iostream>
#include "cards.hh"

Cards::Cards(): top_(nullptr)
{
    std::cout << "constructor" << std::endl;
}

Cards::~Cards()
{
    std::cout << "destructor" << std::endl;
    while (top_ != nullptr) {
            int id;
            remove(id);
        }
}
void Cards::add(int id) {
    std::shared_ptr<Card_data> new_card = std::make_shared<Card_data>();
    new_card->data = id;
    new_card->next = top_;
    top_ = new_card;
}
bool Cards::remove(int& id) {
    if (top_ == nullptr) {
        return false;
    }
    id = top_->data;
    top_ = top_->next;
    return true;
}
   void Cards::print_from_top_to_bottom(std::ostream& s){
    std::shared_ptr<Card_data> current = top_;
    int index = 1;
    while (current != nullptr){
        s << index++ << ": " << current->data << std::endl;
        current = current->next;
    }
}
void Cards::print_from_bottom_to_top(std::ostream& s){
    recursive_print(top_, s);
}
int Cards::recursive_print(std::shared_ptr<Card_data> current, std::ostream& s){
    if (current == nullptr){
        return 0;
    }
    int count = recursive_print(current->next, s);
    s << ++count << ": " << current->data << std::endl;
    return count;
}
bool Cards::top_to_bottom(){
    if (top_ == nullptr || top_->next == nullptr){
        return false;
    }
    std::shared_ptr<Card_data> first_card = top_;
    top_ = top_->next;

    std::shared_ptr<Card_data> current = top_;
    while (current->next != nullptr){
        current = current->next;
    }
    current->next = first_card;
    first_card->next = nullptr;
    return true;
}
void Cards::reverse(){
    std::shared_ptr<Card_data> prev = nullptr;
    std::shared_ptr<Card_data> current = top_;
    std::shared_ptr<Card_data> next = nullptr;
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    top_ = prev;
}
