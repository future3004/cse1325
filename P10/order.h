#ifndef _ORDER_H
#define _ORDER_H

#include "customer.h"
#include "item.h"
#include <iostream>
#include <vector>

class Order {
  public:
   Order(Customer& customer);
   Order(std::istream& ist);
   void save(std::ostream& ost);
   void add_item(Item& item);
   double total();
   friend std::ostream& operator<<(std::ostream& ost, const Order& order);
  private:
   std::vector<Item*> _items;
   Customer* _customer;

};

#endif
