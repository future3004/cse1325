#ifndef __MULCH_H
#define __MULCH_H

#include "product.h"

enum class Material {
  RUBBER,
  PINE,
  CEDAR,
  HARDWOOD,
};

std::string to_string(Material material);

std::ostream& operator<<(std::ostream& ost, const Material& material);

class Mulch : public Product {
  public:
    Mulch(std::string name, double price, std::string description, int volume, Material material);
   //std::string to_string();
  protected:
    std::string to_string() const override;
  private:
    int _volume;
    Material _material;
};

#endif
