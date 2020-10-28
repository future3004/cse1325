#include "store.h"
#include <iostream>

Store::Store(std::string name) : _name{name} { }
Store::Store(std::istream& ist){
  int _size;
  std::string _type;
  std::getline(ist, _name);
  ist >> _size;
  ist.ignore(32767, '\n');
  
  for(int i = 0; i < _size; ++i){
  
   std::getline(ist, _type);
   
   if(_type == "tool"){
    _products.push_back(new Tool(ist));
   } 
   else if(_type == "plant"){
    _products.push_back(new Plant(ist));
   }
   else if(_type == "mulch"){
    _products.push_back(new Mulch(ist));
   } else {
     throw std::runtime_error{"Invalid product type on input: " + _type};
   }
 }
 
}

void Store::add_product(const Tool& product) {_products.push_back(new Tool{product});}
void Store::add_product(const Plant& product) {_products.push_back(new Plant{product});}
void Store::add_product(const Mulch& product) {_products.push_back(new Mulch{product});}
int Store::products() {return _products.size();}
const Product& Store:: product(int index) {return *_products.at(index);}

void Store::save(std::ostream& ost){
 ost << _name << std::endl;
 ost << _products.size() << std::endl;
 
 for(int i = 0; i < _products.size(); ++i){
   _products[i]->save(ost);
   //(_products.at(i))->save(ost);
 }
}


