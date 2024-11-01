#include "queue.hh"
#include <iostream>

// Implement the member functions of Queue here
Queue::Queue(unsigned int cycle) : cycle_(cycle) {}

void Queue::enqueue(string const& reg) {



    auto new_vehicle = make_shared<Vehicle>();
    new_vehicle->reg_num = reg;
    new_vehicle->next = nullptr;
    if (last_ != nullptr) {
        last_->next = new_vehicle;
    } else {
        first_ = new_vehicle;
    }

    last_ = new_vehicle;
}

bool Queue::dequeue(string& reg) {
    if (!is_green_ || first_ == nullptr) {
        return false;
    }
    reg = first_->reg_num;
    first_ = first_->next;
    if (first_ == nullptr) {
        last_ = nullptr;
    }
    return true;
}
void Queue::switch_light() {
    is_green_ = !is_green_;

    if (is_green_) {
        if (first_ != nullptr) {
            cout << "GREEN: Vehicle(s) ";
            unsigned int count = 0;
            string reg;
                       while (count < cycle_ && dequeue(reg)) {
                           cout << reg << " ";
                           count++;
                       }
                       cout << "can go on" << endl;
                   } else {
                       cout << "GREEN: No vehicles waiting in traffic lights" << endl;
                   }
               } else {
                   if (first_ != nullptr) {
                       cout << "RED: Vehicle(s) ";
                       shared_ptr<Vehicle> current = first_;
                       while (current != nullptr) {
                           cout << current->reg_num << " ";
                           current = current->next;
                       }
                       cout << "waiting in traffic lights" << endl;
                   } else {
                       cout << "RED: No vehicles waiting in traffic lights" << endl;
                   }
               }
           }




void Queue::reset_cycle(unsigned int cycle) {
    cycle_ = cycle;
}

void Queue::print() const {
    if (first_ == nullptr) {
        cout << (is_green_ ? "GREEN: No vehicles waiting in traffic lights" : "RED: No vehicles waiting in traffic lights") << endl;
        return;
    }

    cout << (is_green_ ? "GREEN: Vehicle(s) " : "RED: Vehicle(s) ");

    shared_ptr<Vehicle> current = first_;
    while (current != nullptr) {
        cout << current->reg_num << " ";
        current = current->next;
    }
    cout << (is_green_ ? "can go on" : "waiting in traffic lights") << endl;
}


