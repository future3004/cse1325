#include "order.h"

Order::Order(Customer& customer): _customer{new Customer{customer}}, _items{nullptr} {} 

Order::Order(std::istream& ist) {
 delete _customer; _customer = nullptr;
 _customer = new Customer{ist};
 int _itemSize;
 ist >> _itemSize;
 ist.ignore(32767, '\n');
 
 for(int j=0; j < _itemSize; ++j){
   _items.push_back(new Item(ist));
 }
}

void Order::save(std::ostream& ost){
 _customer->save(ost);
 ost << _items.size() << std::endl;
 for(int i = 0; i < _items.size(); ++i){
   _items[i]->save(ost);
 }
}

void Order::add_item(const Item& item){
 _items.push_back(new Item{item});
}

double Order::total() const {
 double itemsTotal = 0.0;
 for(int i = 0; i < _items.size(); ++i){
   itemsTotal += _items[i]->subtotal();
 }
 return itemsTotal;
}

std::string Order::to_string() const {
    double _total = total();
    return "For Customer $" + std::to_string(_total)
            + '\n'; //+ _customer.to_string() 
}

std::ostream& operator<<(std::ostream& ost, const Order& order){
 ost << order.to_string();
 return ost;
}
