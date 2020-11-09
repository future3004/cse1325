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
   void add_item(const Item& item);
   double total() const;
   friend std::ostream& operator<<(std::ostream& ost, const Order& order);
  protected:
    virtual std::string to_string() const;
  private:
   std::vector<Item*> _items;
   Customer* _customer;
};

#endif
