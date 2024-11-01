#include "book.hh"
#include <iostream>

Book::Book(const std::string& author, const std::string& title)
    : author_(author), title_(title), loaned_(false) { }

void Book::loan(const Date& loan_date) {
    if (loaned_) {
        std::cout << "Already loaned: cannot be loaned" << std::endl;
    } else {
        loaned_ = true;
        loan_date_ = loan_date;
        due_date_ = loan_date;
        due_date_.advance(28);
    }
}

void Book::give_back() {
    loaned_ = false;
}

void Book::renew() {
    if (!loaned_) {
        std::cout << "Not loaned: cannot be renewed" << std::endl;
    } else {
        due_date_.advance(28);
    }
}

void Book::print() const {
    std::cout << author_ << " : " << title_ << std::endl;
    if (!loaned_) {
        std::cout << "- available" << std::endl;
    } else {
        std::cout << "- loaned: ";
        loan_date_.print();
        std::cout << "- to be returned: ";
        due_date_.print();
    }
}
