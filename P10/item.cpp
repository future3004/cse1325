#include "item.h"
#include "tool.h"
#include "plant.h"
#include "mulch.h"

Item::Item(Product& product, int quantity): _product{&product}, _quantity{quantity} {}
Item::Item(std::istream& ist){
 ist >> _quantity; ist.ignore(32767, '\n');
 std::string s;
 std::getline(ist, s);
 if(s == "tool"){
  _product = new Tool(ist);
 } 
 else if(s == "plant"){
   _product = new Plant(ist);
 }
 else if(s == "mulch"){
  _product = new Mulch(ist);
 }
 else{ throw std::runtime_error{"Invalid product type on: " + s};}
 
}

void Item::save(std::ostream& ost){
 ost << _quantity << std::endl;
 _product->save(ost);
}

double Item::subtotal(){
 return _product->price() * static_cast<double>(_quantity);
}

std::ostream& operator<<(std::ostream& ost, const Item& item){
 ost << item._quantity << ' ' << *item._product;
 return ost;
}

