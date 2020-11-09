#include "item.h"

Item::Item(Product& product, int quantity): _product{new Product{product}}, _quantity{quantity} {}
Item::Item(std::istream& ist){
 //delete _customer; _customer = nullptr;
 //_customer = new Customer{ist};
 _product = new Product(ist);
 ist >> _quantity; ist.ignore(32767, '\n');
}

void Item::save(std::ostream& ost){
 _product->save(ost);
 ost << _quantity << std::endl;
}

double Item::subtotal(){
 double subT = (_product->_price) * _quantity;
 return subT;
}

std::string Item::to_string() const {
 //std::string output;
 return std::to_string(_quantity) + " " + '\n'; //Product::to_string()  + Product::to_string()
}

std::ostream& operator<<(std::ostream& ost, const Item& item){
 ost << item.to_string();
 return ost;
}

