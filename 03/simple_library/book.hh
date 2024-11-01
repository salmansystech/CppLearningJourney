#ifndef BOOK_HH
#define BOOK_HH

#include "date.hh"
#include <string>
class Book
{
public:
    Book(const std::string& author, const std::string& title);
    void loan(const Date& loan_date);
    void give_back();
    void renew();
    void print() const;

private:
    std::string author_;
    std::string title_;
    bool loaned_;
    Date loan_date_;
    Date due_date_;
};

#endif // BOOK_HH
