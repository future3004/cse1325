#include "item.h"

Item::Item(Product& product, int quantity): _product{product}, _quantity{quantity} {}
Item::Item(std::istream& ist){}
void Item::save(std::ostream& ost){}
double Item::subtotal(){return 0.0;}
std::ostream& operator<<(std::ostream& ost, const Item& item){return ost;}

