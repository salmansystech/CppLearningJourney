#include "account.hh"
#include <iostream>
#include <iomanip>

int Account::running_number_ = 0;

Account::Account(const std::string& owner, bool has_credit)
    : owner_(owner), balance_(0.0), has_credit_(has_credit), credit_limit_(0.0) {

    generate_iban();
}

    void Account::save_money(double amount) {
    balance_ += amount;
}
   void Account::take_money(double amount) {
        if (balance_ >= amount) {
            balance_ -= amount;
            std::cout << amount << " euros taken: new balance of " << iban_ << " is " << balance_ << " euros" << std::endl;
        } else if (has_credit_) {
            if (balance_ - amount >= -credit_limit_) {
                balance_ -= amount;
                std::cout << amount << " euros taken: new balance of " << iban_ << " is " << balance_ << " euros" << std::endl;
            } else {
                std::cout << "Cannot take money: credit limit overflow" << std::endl; // Corrected message
            }
        } else {
            std::cout << "Cannot take money: balance underflow" << std::endl; // Corrected message
        }
    }
    void Account::transfer_to(Account& other, double amount) {
        double old_balance = balance_;
        take_money(amount);
        if (old_balance != balance_) {
            other.save_money(amount);
        } else {
            std::cout << "Transfer from " << iban_ << " failed" << std::endl;
        }
    }
    void Account::set_credit_limit(double limit) {
        if (has_credit_) {
            credit_limit_ = limit;
        } else {
            std::cout << "Cannot set credit limit: the account has no credit card" << std::endl;
        }
    }
    void Account::print() const {
        std::cout << owner_ << " : " << iban_ << " : " << std::fixed << std::setprecision(0) << balance_ << " euros" << std::endl;
    }
    void Account::generate_iban() {
        ++running_number_;
        std::string suffix = "";
        if (running_number_ < 10) {
            suffix.append("0");
        } else if (running_number_ > 99) {
            std::cout << "Too many accounts" << std::endl;
        }
        suffix.append(std::to_string(running_number_));
        iban_ = "FI00 1234 ";
        iban_.append(suffix);
    }
