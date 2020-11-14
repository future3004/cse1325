#include "customer.h"
#include <iostream>

Customer::Customer(std::string name, std::string phone, std::string email): _name{name},
  _phone{phone}, _email{email} {}
  
Customer::Customer(std::istream& ist){
  ist >> _name; ist.ignore(32767, '\n');
  ist >> _phone; ist.ignore(32767, '\n');
  ist >> _email; ist.ignore(32767, '\n');
}

std::string Customer::to_string() const {
    return _name + " ("
                 + _phone + ", "
                 + _email + ") " + '\n';
}

void Customer::save(std::ostream& ost){
  ost << _name << std::endl;
  ost << _phone << std::endl;
  ost << _email << std::endl;

}

std::ostream& operator<<(std::ostream& ost, const Customer& customer){
  ost << customer.to_string();
  return ost;
}
