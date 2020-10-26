#include "mulch.h"

Mulch::Mulch(std::string name, double price, std::string description, int volume, Material material)
    : Product(name, price, description), _volume{volume}, _material{material} { }

Mulch::Mulch(std::istream& ist): Product(ist){
 std::string ist_val;
 ist >> _volume;
 getline(ist, ist_val);
 _material = material_string(ist_val);
}

std::string Mulch::to_string() const {
    return Product::to_string() + "\n  Volume: " + std::to_string(_volume) + " ft³\n  Material: " + ::to_string_material(_material);
}
std::ostream& operator<<(std::ostream& ost, const Material& material) {
    ost << to_string_material(material);
    return ost;
}
//std::string Mulch::to_string(){
//    return Product::to_string() + "\n  Volume: " + std::to_string(_volume) + " ft³\n  Material: " + ::to_string(_material);
//}
std::string to_string_material(Material material) {
    if(material == Material::RUBBER) return "rubber";
    else if(material == Material::PINE) return "pine";
    else if(material == Material::CEDAR) return "cedar";
    else if(material == Material::HARDWOOD) return "hardwood";
    else throw std::out_of_range("Invalid Material value");
}

void Mulch::save(std::ostream& ost){
  ost << "mulch" << std::endl;
  Product::save(ost);
  ost << _volume << std::endl;
  ost << to_string_material(_material) << std::endl;
}

Material material_string(std::string ist_value) {
    if(ist_value == "rubber") return Material::RUBBER;
    else if(ist_value == "pine") return Material::PINE;
    else if(ist_value == "cedar") return Material::CEDAR;
    else if(ist_value == "hardwood") return Material::HARDWOOD;
    else throw std::out_of_range("Invalid Material value");
}

