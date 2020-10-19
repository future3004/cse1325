#ifndef __STORE_H
#define __STORE_H

#include "tool.h"
#include "plant.h"
#include "mulch.h"

#include <vector>

class Store {
  public:
    Store(std::string name);
    void add_product(const Tool& product);
    void add_product(const Plant& product);
    void add_product(const Mulch& product);
    int products();
    const Product& product(int index);
    std::vector<Product*> get_products_vector();
  protected:
   std::vector<Product*> _products;
  private:
    std::string _name;
    
};

#endif
