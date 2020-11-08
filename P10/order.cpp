#include "order.h"

Order::Order(Customer& customer){}
Order::Order(std::istream& ist){}
void Order::save(std::ostream& ost){}
void Order::add_item(Item& item){}
double Order::total(){return 0.0;}
std::ostream& operator<<(std::ostream& ost, const Order& order){return ost;}
