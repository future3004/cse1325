#include "plant.h"

Plant::Plant(std::string name, double price, std::string description, std::string species, Exposure exposure)
    : Product(name, price, description), _species{species}, _exposure{exposure} { }
    
Plant::Plant(std::istream& ist): Product(ist) {
  std::string ist_val;
  std::getline(ist, _species);
  std::getline(ist, ist_val);
  _exposure = from_string(ist_val);
}

std::string Plant::to_string() const {
    return Product::to_string() + "\n  Species: " + _species + "\n  Exposure: " + ::my_string(_exposure);
}

//std::string Plant::to_string() {
//    return Product::to_string() + "\n  Species: " + _species + "\n  Exposure: " + ::to_string(_exposure);
//}
std::ostream& operator<<(std::ostream& ost, const Exposure& exposure) {
    ost << my_string(exposure);
    return ost;
}
std::string my_string(Exposure exposure) {
    if(exposure == Exposure::SHADE) return "shade";
    else if(exposure == Exposure::PARTSUN) return "part sun";
    else if(exposure == Exposure::SUN) return "full sun";
    else throw std::out_of_range("Invalid Exposure value");
}

void Plant::save(std::ostream& ost){
  //std::string exp = std::;
  ost << "plant" << std::endl;
  Product::save(ost);
  ost << _species << std::endl;
  ost << my_string(_exposure) << std::endl;
}

Exposure from_string(std::string ist_value){
  if(ist_value == "shade") return  Exposure::SHADE;
    else if(ist_value == "part sun") return Exposure::PARTSUN;
    else if(ist_value == "full sun") return Exposure::SUN;
    else throw std::out_of_range("Invalid Exposure value");
}



