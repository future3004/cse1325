#ifndef __STORE_H
#define __STORE_H

#include "tool.h"
#include "plant.h"
#include "mulch.h"
#include "customer.h"
#include "order.h"
#include "item.h"

#include <vector>
#include <iostream>
#include <fstream>

class Store {
  public:
    Store(std::string name);
    Store(std::istream& ist);
    void save(std::ostream& ost);
    std::string name();
    
    void add_product(const Tool& product);
    void add_product(const Plant& product);
    void add_product(const Mulch& product);
    int products();
    Product& product(int index);
    
    int customers();
    void add_customer(const Customer& customer);
    const Customer& customer(int index);
    
    int add_order(const Customer& customer);
    void add_item(int order, Product& product, int quantity);
    int orders();
    const Order& order(int index);
    std::vector<Order*>::iterator iterator;
    std::vector<Order*>::const_iterator const_iterator;
    //typedef Orders::iterator iterator;
    //typedef Orders::const_iterator const_iterator;
    //iterator begin() {return _orders.at(0);}
    //iterator end() {return _orders.at(_orders.size());}

  private:
    std::string _name;
    std::vector<Product*> _products;
    std::vector<Customer*> _customers;
    std::vector<Order*> _orders;
    //typedef std::vector<Order*> Orders;
    //Orders orderz;
    
};

#endif
